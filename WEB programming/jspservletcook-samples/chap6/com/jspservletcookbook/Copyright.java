package com.jspservletcookbook;          

import javax.servlet.*;
import javax.servlet.http.*;

public class Copyright extends HttpServlet {
  
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
       
        java.io.PrintWriter out = response.getWriter();
        out.println("Copyright&copy; 2003-2004 EmbraceAndExtend Corp.");
        out.close();
        
    } 
}
