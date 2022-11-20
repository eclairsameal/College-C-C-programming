package com.jspservletcookbook;           

import javax.servlet.*;
import javax.servlet.http.*;

public class ContextBinder extends HttpServlet {

  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    
    //bind an object to the servlet context
    getServletContext().setAttribute(
	    "com.jspservletcookbook.ContextObject", new ContextObject());
    
    //better display something
      response.setContentType("text/html");
      java.io.PrintWriter out = response.getWriter();
      out.println("<html><head><title>Servlet Context Attribute</title></head><body>");
      out.println("<h2>Servlet Context Attribute Bound</h2>");
	  out.println("Object: " + getServletContext().getAttribute(
	    "com.jspservletcookbook.ContextObject"));
      out.println("</body></html>");
     
	  
     } //end doGet

}
