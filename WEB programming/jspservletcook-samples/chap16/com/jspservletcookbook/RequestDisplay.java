package com.jspservletcookbook;           

import javax.servlet.*;
import javax.servlet.http.*;

public class RequestDisplay extends HttpServlet {

  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    
   ContextObject obj = (ContextObject) request.getAttribute("com.jspservletcookbook.RequestObject");
    //display the attribute's Map keys
      response.setContentType("text/html");
      java.io.PrintWriter out = response.getWriter();
      out.println("<html><head><title>Request Attribute</title></head><body>");
      out.println("<h2>Request attribute values</h2>");
      if (obj != null)
      out.println( obj.getValues() );
      out.println("</body></html>");
     
      
     } //end doGet

}
