package com.jspservletcookbook;    

import java.io.*;
import java.util.Properties;

import javax.activation.*;
import javax.mail.*;
import javax.mail.internet.*;

import javax.servlet.*;
import javax.servlet.http.*;

public class EmailAttachServlet extends HttpServlet {

   //default value for mail server address, in case the user 
   //doesn't provide one
   private final static String DEFAULT_SERVER = "mail.attbi.com";

  public void doPost(HttpServletRequest request, 
    HttpServletResponse response) throws ServletException,
      java.io.IOException {
    
      response.setContentType("text/html");
      java.io.PrintWriter out = response.getWriter();
      out.println(
        "<html><head><title>Email message sender</title></head><body>");
     
      String smtpServ = request.getParameter("smtp");

      if (smtpServ == null || smtpServ.equals(""))
        smtpServ = DEFAULT_SERVER;

      String from = request.getParameter("from");

      String to = request.getParameter("to");

      String subject = request.getParameter("subject");

      try {
       
          sendMessage(smtpServ, to, from, subject);
           
      } catch (Exception e) {
       
          throw new ServletException(e.getMessage()); 
           
      }
    
      out.println("</body></html>");
      out.close();

  }//doPost
     
  public void doGet(HttpServletRequest request, 
    HttpServletResponse response) throws ServletException,
        java.io.IOException {
          
      doPost(request,response);
          
  }//doGet
     
  private void sendMessage(String smtpServ, String to, String from,
    String subject) throws Exception {
     
      Multipart multipart = null;
      BodyPart bpart1 = null;
      BodyPart bpart2 = null;

      Properties properties = System.getProperties();

      //populate the 'Properties' object with the mail
      //server address, so that the default 'Session'
      //instance can use it.
      properties.put("mail.smtp.host", smtpServ);

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
        
          //This email message's content is a 'Multipart' type
          //The MIME type for the message's content is 'multipart/mixed'
          multipart = new MimeMultipart();
        
          //The text part of this multipart email message
          bpart1 = new MimeBodyPart();

          String textPart = 
          "Hello, just thought you'd be interested in this Word file.";
        
          // create the DataHandler object for the text part
          DataHandler data = new DataHandler(textPart, "text/plain");
        
          //set the text BodyPart's DataHandler
          bpart1.setDataHandler(data);
        
          //add the text BodyPart to the Multipart container
          multipart.addBodyPart( bpart1);

          //create the BodyPart that represents the attached Word file
          bpart2 = new MimeBodyPart();

          //create the DataHandler that points to a File
          FileDataSource fds = new FileDataSource( new File(
          "h:/book/chapters/chap1/chap1.doc") );
        
          //Make sure that the attached file is handled as
          //the appropriate MIME type: application/msword here
          MimetypesFileTypeMap ftm = new MimetypesFileTypeMap();
        
          //the syntax here is the MIME type followed by
          //space separated extensions
          ftm.addMimeTypes("application/msword doc DOC" );
        
          fds.setFileTypeMap(ftm);
          //The DataHandler is instantiated with the
          //FileDataSource we just created
          DataHandler fileData = new DataHandler( fds );

          //the BodyPart will contain the word processing file
          bpart2.setDataHandler(fileData);
        
          //add the second BodyPart, the one containing the attachment, to
          //the Multipart object
          multipart.addBodyPart( bpart2 );
        
          //finally, set the content of the MimeMessage to the
          //Multipart object
          mailMsg.setContent( multipart );
         
          // send the mail message; throws a 'SendFailedException' 
          //if any of the message's recipients have an invalid adress
          Transport.send(mailMsg);

        
      } catch (Exception exc) {
    
          throw exc;
        
      }//try

  }//sendMessage

}//EmailAttachServlet
