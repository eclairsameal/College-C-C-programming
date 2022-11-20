package com.jspservletcookbook;    

import java.io.IOException;
import java.io.PrintWriter;

import java.util.Properties;
import java.util.Enumeration;

import javax.mail.*;
import javax.mail.internet.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class HeaderAccessor extends HttpServlet {

   private final static String DEFAULT_SERVER = "mail.attbi.com";

    public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    
    response.setContentType("text/html");
    java.io.PrintWriter out = response.getWriter();
    out.println("<html><head><title>Email Reader</title></head><body>");
     
   handleMessages(request, out);
    
      out.println("</body></html>");
      out.close();
     } //doGet
     
     private void handleMessages(HttpServletRequest request,
              PrintWriter out) throws IOException, ServletException {
    
   HttpSession httpSession =  request.getSession();
   String user = (String) httpSession.getAttribute("user");
   String password = (String) httpSession.getAttribute("pass");
   String popAddr = (String) httpSession.getAttribute("pop");
   
   Store popStore = null;
   Folder folder = null;
   
   if (! check(popAddr))
       popAddr = HeaderAccessor.DEFAULT_SERVER;
    
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
    }//printMessages
    
	private void displayMessage(Message msg, PrintWriter out) 
        throws MessagingException, IOException{
    
       if (msg != null && msg.getContent() instanceof String){
         
         if (msg.getFrom()[0] instanceof InternetAddress){
         out.println("Message received from: " + ((InternetAddress)msg.getFrom()[0]).getAddress() +"<br />");
         }
       
         out.println("Message content type: " + msg.getContentType() +"<br />");
         out.println("Message body content: " + (String) msg.getContent());
         //Headers
         out.println("<ul>");
         
         Header head = null;
         Enumeration headers = msg.getAllHeaders();
         
         while ( headers.hasMoreElements() ){
         
          head = (Header) headers.nextElement();
           out.println("<li>" + head.getName() + ": " + head.getValue()+ "</li>");
         }
          out.println("</ul>");
         
       } else{
       
            out.println("<h2>The received email message was not of a text content type.</h2>");
       
       }
         
    }//displayMessage
    
	private boolean check(String value){
    
        if(value == null || value.equals(""))
            return false;
            
    	return true;
    }
}
