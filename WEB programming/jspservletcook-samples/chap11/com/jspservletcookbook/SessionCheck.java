package com.jspservletcookbook;

import javax.servlet.*;
import javax.servlet.http.*;

public class SessionCheck extends HttpServlet {
  
 public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
        
		HttpSession session = request.getSession(false);
		if (session == null){
		    response.sendRedirect("/dbproj/login.jsp");
	    } else {
		    response.sendRedirect("/dbproj/menu.jsp");
		}
       
	   
  } 
}
