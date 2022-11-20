package com.jspservletcookbook;    

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Properties;

import javax.mail.*;
import javax.mail.internet.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class EmailServlet extends HttpServlet {

   //default value for mail server address, in case the user 
   //doesn't provide one
   private final static String DEFAULT_SERVER = "mail.attbi.com";

  public void doPost(HttpServletRequest request, 
      HttpServletResponse response) throws ServletException,
          java.io.IOException {
          
          //obtain the values for email components from
    //request parameters
    String smtpServ = request.getParameter("smtp");

    if (smtpServ == null || smtpServ.equals(""))
        smtpServ = DEFAULT_SERVER;

    String from = request.getParameter("from");

    String to = request.getParameter("to");

    String subject = request.getParameter("subject");

    String emailContent = request.getParameter("emailContent");
    
    response.setContentType("text/html");
    java.io.PrintWriter out = response.getWriter();
    out.println("<html><head><title>Email message sender</title></head><body>");
     
       try {
       
           sendMessage(smtpServ, to, from, subject, emailContent);
           
       } catch (Exception e) {
       
           throw new ServletException(e.getMessage()); 
           
       }
       
     out.println(
        "<h2>The message was sent successfully</h2>");
    
    out.println("</body></html>");
    

     } //doPost
     
  private void sendMessage(String smtpServer, String to, String from, String subject,String emailContent) throws Exception {
     
    Properties properties = System.getProperties();

    //populate the 'Properties' object with the mail
    //server address, so that the default 'Session'
    //instance can use it.
    properties.put("mail.smtp.host", smtpServer);

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

        if (emailContent != null)
            mailMsg.setText(emailContent);
        
        //Finally, send the meail message; throws a 'SendFailedException' 
        //if any of the message's recipients have an invalid adress
        Transport.send(mailMsg);
    
        } catch (Exception exc) {
     
         throw exc;
    
        }
     
    }//sendMessage
    
    public void doGet(HttpServletRequest request, 
      HttpServletResponse response) throws ServletException,
          java.io.IOException {
		  
		      doPost(request, response);
			  
	}
    
}//EmailServlet
