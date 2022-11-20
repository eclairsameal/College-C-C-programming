package com.jspservletcookbook;           

import javax.servlet.*;
import javax.servlet.http.*;

public class ContextLog extends HttpServlet {


  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    
    String yourMessage = request.getParameter("mine");
    //Call the two ServletContext.log methods
    //the javax.servlet.GenericServlet.getServletContext method
    ServletContext context = getServletContext();
    if (yourMessage == null || yourMessage.equals(""))
    //log version with Throwable parameter
      context.log("No message received:",new IllegalStateException("Missing parameter"));
    else
      context.log("Here is the visitor's message: " + yourMessage);
      
    response.setContentType("text/html");
    java.io.PrintWriter out = response.getWriter();
    //logging servlets probably want to display more HTML; this is 'lazy HTML'
    out.println("<html><head><title>ServletContext logging</title></head><body>");
    out.println("<h2>Messages sent</h2>");
    out.println("</body></html>");
    } //end doGet
}
