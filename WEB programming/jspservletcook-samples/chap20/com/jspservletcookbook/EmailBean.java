package com.jspservletcookbook;    

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Properties;

import javax.mail.*;
import javax.mail.internet.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class EmailBean  {

   //defaults
   private final static String DEFAULT_CONTENT = "Unknown content";
   private final static String DEFAULT_SUBJECT= "Unknown subject";
   private static String DEFAULT_SERVER = null;
   private static String DEFAULT_TO = null;
   private static String DEFAULT_FROM = null;
   static{
    java.util.ResourceBundle bundle = 
     java.util.ResourceBundle.getBundle("com.jspservletcookbook.mailDefaults"); 

   DEFAULT_SERVER = bundle.getString("DEFAULT_SERVER");
   DEFAULT_TO = bundle.getString("DEFAULT_TO");
   DEFAULT_FROM = bundle.getString("DEFAULT_FROM");
   
   System.out.println("DEFAULT_SERVER: " + DEFAULT_SERVER);
   }

    //JavaBean properties
	private String smtpHost;
	private String to;
	private String from;
	private String content;
	private String subject;
    
     public void sendMessage() throws Exception {
     
      Properties properties = System.getProperties();

      //populate the 'Properties' object with the mail
      //server address, so that the default 'Session'
      //instance can use it.
      properties.put("mail.smtp.host", smtpHost);

      Session session = Session.getDefaultInstance(properties);
         
      Message mailMsg = new MimeMessage(session);//a new email message

      InternetAddress[] addresses = null;
    
      try {
   

          if (to != null) {
        
              //throws 'AddressException' if the 'to' email address
              //violates RFC822 syntax
              addresses = InternetAddress.parse(to, false);

              mailMsg.setRecipients(Message.RecipientType.TO, addresses);
        
          } else {
        
              throw new MessagingException(
                "The mail message requires a 'To' address.");
        
          }

          if (from != null) {
        
              mailMsg.setFrom(new InternetAddress(from));
        
          } else {
        
              throw new MessagingException(
                "The mail message requires a valid 'From' address.");
        
          } 
        
          if (subject != null)
              mailMsg.setSubject(subject);

          if (content != null)
              mailMsg.setText(content);
        
          //Finally, send the mail message; throws a 'SendFailedException' 
          //if any of the message's recipients have an invalid address
          Transport.send(mailMsg);
    
          } catch (Exception exc) {
     
              throw exc;
    
          }
     
  }//sendMessage


	
	private void handleMessages(HttpServletRequest request,
              PrintWriter out) throws IOException, ServletException {
    
   HttpSession httpSession =  request.getSession();
   String user = (String) httpSession.getAttribute("user");
   String password = (String) httpSession.getAttribute("pass");
   String popAddr = (String) httpSession.getAttribute("pop");
   
   Store popStore = null;
   Folder folder = null;
   
   if (! check(popAddr))
       popAddr = EmailBean.DEFAULT_SERVER;
    
    try {
   
   if ((! check(user)) || (! check(password)))
      throw new ServletException("A valid username and password is required to check email.");
   
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
  }
   
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
    
       if (msg != null && msg.getContent() instanceof String){
         
         if (msg.getFrom()[0] instanceof InternetAddress){
         out.println("Message received from: " + ((InternetAddress)msg.getFrom()[0]).getAddress() +"<br />");
         }
         out.println("Message received on: " + msg.getReceivedDate() +"<br />");
         out.println("Message content type: " + msg.getContentType() +"<br />");
          out.println("Message content type: " + (String) msg.getContent());
       } else{
       
            out.println("<h2>The received email message was not of a text content type.</h2>");
       
       }
         
    }//displayMessage
    
	public void setSmtpHost(String host){
        if (check(host)){
        this.smtpHost = host;
        } else {
    	this.smtpHost = EmailBean.DEFAULT_SERVER;
        }
    }//setTo
    
	public void setTo(String to){
        if (check(to)){
        this.to = to;
        } else {
    	this.to = EmailBean.DEFAULT_TO;
        }
    }//setTo
    
	public void setFrom(String from){
        if (check(from)){
        this.from = from;
        } else {
    	this.from = EmailBean.DEFAULT_FROM;
        }
    }//setFrom
    
	public void setContent(String content){
        if (check(content)){
        this.content = content;
        } else {
    	this.content = EmailBean.DEFAULT_CONTENT;
        }
    }//setContent
    
	public void setSubject(String subject){
        if (check(subject)){
        this.subject = subject;
        } else {
    	this.subject = EmailBean.DEFAULT_SUBJECT;
        }
    }//setSubject
    
	private boolean check(String value){
    
        if(value == null || value.equals(""))
            return false;
            
    	return true;
    }
}
