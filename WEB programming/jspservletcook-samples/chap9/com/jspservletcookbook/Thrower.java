package com.jspservletcookbook;

import javax.servlet.*;
import javax.servlet.http.*;

public class Thrower extends HttpServlet {
  
 public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
        
/* Use the ServletRequest.getParameter(String name), getParameterMap(), getParameterNames(), or getParameterValues() methods in the servlet's doPost method*/

      throw new java.io.IOException("IO thrown");
	  //  throw new java.lang.IllegalStateException("IllegalStateException thrown by thrower.");
	   //response.sendError(403);
  } 
  
  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {

    doPost(request,response);
}
}
