package com.jspservletcookbook;    

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Properties;

import javax.mail.*;
import javax.mail.internet.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class EmailBeanServlet extends HttpServlet {

  public void doGet(HttpServletRequest request, HttpServletResponse response)
  throws ServletException, java.io.IOException {
    
    response.setContentType("text/html");
    java.io.PrintWriter out = response.getWriter();
    out.println(
    "<html><head><title>Email message sender</title></head><body>");
    
    EmailBean emailer = new EmailBean();

    emailer.setSubject("This is not spam!");

    emailer.setContent("Please call ASAP.");    
	
	emailer.setTo("myfriend@yahoo.com");
	emailer.setFrom("author@jspservletcookbook.com");
	emailer.setSmtpHost("smtp.comcast.net");

	try{
        emailer.sendMessage();
	} catch (Exception e) {throw new ServletException(e);}
    
    out.println("</body></html>");
    

} //doGet

    
    public void doPost(HttpServletRequest request, 
      HttpServletResponse response) throws ServletException,
          java.io.IOException {
		  
		      doGet(request, response);
			  
	}
    
}//EmailServlet
