package com.jspservletcookbook;           

import javax.servlet.*;
import javax.servlet.http.*;

import javax.security.auth.login.LoginContext;
import javax.security.auth.login.LoginException;
import javax.security.auth.callback.CallbackHandler;

public class LoginServlet extends HttpServlet {

  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    
      WebCallbackHandler webcallback = new WebCallbackHandler(request);
      LoginContext lcontext = null;
      boolean loginSuccess = true;
    
    
      try{
    
          lcontext = new LoginContext( "WebLogin",webcallback );
          
          lcontext.login();
    
      } catch (LoginException lge){
    
          loginSuccess = false;
    
      }

          response.setContentType("text/html");
          java.io.PrintWriter out = response.getWriter();
          out.println("<html><head><title>Thanks for logging in</title></head><body>");
          out.println("<h2>Your logged in status</h2>");
      
          out.println(""+ ( loginSuccess ? "Logged in" : "Failed Login" ));
      
          out.println("</body></html>");
         
      
     } //doGet
     
     public void doPost(HttpServletRequest request, 
       HttpServletResponse response) throws ServletException, 
       java.io.IOException {
	   
	     doGet(request,response);
		 
	}//doPost

}
