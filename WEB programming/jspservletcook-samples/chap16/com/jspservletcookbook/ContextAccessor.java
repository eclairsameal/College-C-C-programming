package com.jspservletcookbook;           

import javax.servlet.*;
import javax.servlet.http.*;

public class ContextAccessor extends HttpServlet {

  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    
    //get a servlet context attribute
    ContextObject contextObj = (ContextObject)
   getServletContext().getAttribute(
        "com.jspservletcookbook.ContextObject");
        
        if (contextObj != null)
            contextObj.put(request.getRemoteAddr(),""+new java.util.Date());
        
    //display 
      response.setContentType("text/html");
      java.io.PrintWriter out = response.getWriter();
      out.println("<html><head><title>Servlet Context Attribute</title></head><body>");
      if (contextObj != null){
      out.println("<h2>Servlet Context Attribute Values</h2>");
      out.println(contextObj.getValues());
      } else {
       out.println("<h2>Servlet Context Attribute is Null</h2>");
      }
      out.println("</body></html>");
      
     } //end doGet

}
