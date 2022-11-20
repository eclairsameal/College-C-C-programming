package com.jspservletcookbook;    

import java.io.IOException;
import java.io.PrintWriter;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;  

import javax.mail.*;
import javax.mail.internet.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class EmailJndiServlet extends HttpServlet {

  private Session mailSession;

  public void init() throws ServletException {
        
         Context env = null;
    
       try{
           
             env = (Context) new InitialContext();
             
             mailSession = (Session) env.lookup("MyEmail");
             
             if (mailSession == null)
                 throw new ServletException(
                   "MyEmail is an unknown JNDI object");
                   
             //close the InitialContext
             env.close();
             
        } catch (NamingException ne) { 
        
          try{ env.close();} catch (NamingException nex) { }
        
           throw new ServletException(ne);

        }
      

    }

  public void doPost(HttpServletRequest request, 
      HttpServletResponse response) throws ServletException,
          java.io.IOException {
    
      response.setContentType("text/html");
      java.io.PrintWriter out = response.getWriter();
      out.println(
      "<html><head><title>Email message sender</title></head><body>");
     
      String to = request.getParameter("to");
	  
	   String from = request.getParameter("from");

      String subject = request.getParameter("subject");

      String emailContent = request.getParameter("emailContent");
         
      try{
      
          sendMessage(to,from,subject,emailContent);
          
      } catch(Exception exc){
      
          throw new ServletException(exc.getMessage());
          
      }
    
    
        out.println(
        "<h2>The message was sent successfully</h2></body></html>");
    
    out.println("</body></html>");
    out.close();

     } //doPost
     
     public void doGet(HttpServletRequest request, 
      HttpServletResponse response) throws ServletException,
          java.io.IOException {
          
              doPost(request,response);
          
    }
     
  private void sendMessage(String to, String from,String subject, 
    String bodyContent) throws Exception {
    
      Message mailMsg = null;
     
       synchronized(mailSession){
       
          mailMsg = new MimeMessage(mailSession);//a new email message
       }

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
          
		   if (from != null)
		       mailMsg.setFrom(new InternetAddress(from));
       
           if (subject != null)
               mailMsg.setSubject(subject);

           if (bodyContent != null)
               mailMsg.setText(bodyContent);
        
           //Finally, send the mail message; throws a 'SendFailedException' 
           //if any of the message's recipients have an invalid adress
           Transport.send(mailMsg);
        
            } catch (Exception exc) {
    
                throw exc;
           }
    }//sendMessage
    
}//EmailJndiServlet
