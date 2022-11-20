package com.jspservletcookbook;            

import javax.servlet.*;
import javax.servlet.http.*;

public class Level4 extends HttpServlet {
  
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
        
         java.io.PrintWriter out = response.getWriter();
        out.println("<h4>Hello from Level 4</h4>");
        out.println("This text is included at Level 4.");
       } 
}
