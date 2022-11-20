package com.jspservletcookbook;    

import java.io.*;
import java.util.Properties;

import javax.mail.*;
import javax.mail.internet.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class AttachBean  {

  public AttachBean(){}

   //defaults
   private final static String DEFAULT_SERVER = "mail.comcast.net";
   private final static String DEFAULT_TO = "author@jspservletcookbook.com";
   private final static String DEFAULT_FROM = "author@jspservletcookbook.com";
   private final static String DEFAULT_CONTENT = "Unknown content";
   private final static String DEFAULT_SUBJECT= "Unknown subject";
   

    //JavaBean properties
	private String smtpHost;
	private String to;
	private String from;
	private String content;
	private String subject;
	private String attachFolder;
    
     public void sendMessage(HttpServletRequest request,
              PrintWriter out) throws IOException {
     
    setSmtpHost( request.getParameter("smtp") );
    setFrom(request.getParameter("from"));
    setTo(request.getParameter("to"));
    setSubject(request.getParameter("subject"));
    setContent(request.getParameter("content"));
    
    Properties properties = System.getProperties();
    properties.put("mail.smtp.host", smtpHost);
    Session session = Session.getDefaultInstance(properties);
         
   Message mailMsg = new MimeMessage(session);
   InternetAddress[] addresses = null;
    
    try {
   

    if (to != null) {
        
        addresses = InternetAddress.parse(to, false);
        mailMsg.setRecipients(Message.RecipientType.TO, addresses);
        
        } else {
        
        throw new MessagingException("The mail message requires a 'To' address.");
        
        }

        if (from != null) {
        
        mailMsg.setFrom(new InternetAddress(from));
        
        } else {
        
        throw new MessagingException("The mail message requires a valid 'From' address.");
        
        } 
        
        mailMsg.setSubject(subject);

        mailMsg.setText(content);

        Transport.send(mailMsg);
        
        out.println("<h2>The message was sent successfully</h2>");

        
    } catch (Exception exc) {
    
        out.println("<h2>Sorry, an error occurred while sending the message.</h2>");
        out.println(exc.toString());
        
    }
    }//sendMessage
	
	public void handleMessages(HttpServletRequest request,
              PrintWriter out) throws IOException, ServletException {
    
       HttpSession httpSession =  request.getSession();
       String user = (String) httpSession.getAttribute("user");
       String password = (String) httpSession.getAttribute("pass");
       String popAddr = (String) httpSession.getAttribute("pop");
   
       Store popStore = null;
       Folder folder = null;
   
       if (! check(popAddr))
           popAddr = AttachBean.DEFAULT_SERVER;
    
        try {
   
           if ((! check(user)) || (! check(password)))
              throw new ServletException(
                  "A valid username and password is required to check email.");
   
           Properties properties = System.getProperties();
   
           Session session = Session.getDefaultInstance(properties);
   
           popStore = session.getStore("pop3");
   
           popStore.connect(popAddr, user, password);
   
          folder = popStore.getFolder("INBOX");
   
          if (! folder.exists())
             throw new ServletException("An 'INBOX' folder does not exist for the user.");
       
          folder.open(Folder.READ_ONLY);
  
         Message[] messages = folder.getMessages();

         int msgLen = messages.length;
  
         if (msgLen == 0)
             out.println("<h2>The INBOX folder does not yet contain any email messages.</h2>");
  
        for (int i = 0; i < msgLen; i++){
      
           displayMessage(messages[i], out);
           
          out.println("<br /><br />");
         }//for
   
        } catch (Exception exc) {
    
            out.println("<h2>Sorry, an error occurred while accessing the email messages.</h2>");
            out.println(exc.toString());
        
        } finally {
            try{
            
               if (folder != null)
               folder.close(false);
            
               if (popStore != null)
              popStore.close();
              
            } catch (Exception e) { }
       }
    }//handleMessages
    
	private void displayMessage(Message msg, PrintWriter out) 
        throws MessagingException, IOException{
        
        if (msg != null){
        
            Object o = msg.getContent();
    
            if ( o instanceof String){
         
                handleStringMessage(msg,(String) o, out);
          
            } else if ( o instanceof Multipart ) {
          
                Multipart mpart = (Multipart) o;
                Part part = null;
                File file = null;
                //FileWriter writer = null;
				FileOutputStream stream = null;
                InputStream input = null;
                String fileName = "";
              
                for (int i = 0; i < mpart.getCount(); i++){
                  
                    part = mpart.getBodyPart(i);
                    
                    Object partContent = part.getContent();
                  
                    if (partContent instanceof String){
                  
                        handleStringMessage(msg,(String) partContent, out);
                   
                    }  else {
                
                       fileName = part.getFileName();
              
                       if (! check(fileName)){
                           fileName = "file"+new java.util.Date().getTime();}
                      
                      file = new File(attachFolder + System.getProperty("file.separator") + fileName);
                          
                     //writer = new FileWriter(file);
					 stream = new FileOutputStream(file);
                 
                     input = part.getInputStream();
                     
                     int ch;
                 
                     while ( (ch = input.read()) != -1){
                         //writer.write(ch);
						 stream.write(ch);
						 }
                    
                	input.close(); 
                    
                    out.println("Handled attachment named: "+fileName+"<br /><br />");
                    }// if
                }//for
            }//else if instanceof multipart
       
        } else{
       
            out.println("<h2>The received email message returned null.</h2>");
       
       }// if msg != null
         
    }//displayMessage
    
	private void handleStringMessage(Part part, String emailContent, PrintWriter out)  throws MessagingException {
    
      if (part instanceof Message){
      
          Message msg = (Message) part;
      
          if (msg.getFrom()[0] instanceof InternetAddress){
         
             out.println(
                 "Message received from: " + ((InternetAddress) msg.getFrom()[0]).getAddress() +"<br />");
             }
             
             out.println("Message content type: " + msg.getContentType() +"<br />");
             
             out.println("Message content: " + emailContent +"<br />");
        }
        
    }//handleStringMessage
    
	private boolean check(String value){
    
        if(value == null || value.equals(""))
            return false;
            
    	return true;
    }
	
	public void setAttachFolder(String folder){
        
		this.attachFolder = folder;
		
    }//setAttachFolder
    
	public void setSmtpHost(String host){
        if (check(host)){
        this.smtpHost = host;
        } else {
    	this.smtpHost = DEFAULT_SERVER;
        }
    }//setTo
    
	public void setTo(String to){
        if (check(to)){
        this.to = to;
        } else {
    	this.to = DEFAULT_TO;
        }
    }//setTo
    
	public void setFrom(String from){
        if (check(from)){
        this.from = from;
        } else {
    	this.from = DEFAULT_FROM;
        }
    }//setFrom
    
	public void setContent(String content){
        if (check(content)){
        this.content = content;
        } else {
    	this.content = DEFAULT_CONTENT;
        }
    }//setContent
    
	public void setSubject(String subject){
        if (check(subject)){
        this.subject = subject;
        } else {
    	this.subject = DEFAULT_SUBJECT;
        }
    }//setSubject
   
}
