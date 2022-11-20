package com.jspservletcookbook;            

import javax.servlet.*;
import javax.servlet.http.*;

public class ErrorPage extends HttpServlet {
  
    public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
        
        response.setContentType("text/html");
        java.io.PrintWriter out = response.getWriter();
       
        out.println("<html>");
        out.println("<head>");
        out.println("<title>Error Page Servlet</title>");  
        out.println("</head>");
        out.println("<body>");
        out.println("<h2>Error Information</h2>");
        out.println("Regretably, an error occurred. Here is the information:<br><br>");
        Exception exception = (Exception) request.getAttribute("javax.servlet.error.exception");
        String servletName = (String) request.getAttribute("javax.servlet.error.servlet_name");
        out.println("The servlet name that generated the exception: "+servletName+"<br>");
        out.println("Exception message: "+exception.getMessage());
        out.println("</body>");
        out.println("</html>");
       
        out.close();
        
    } 
}
