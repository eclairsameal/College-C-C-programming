package com.jspservletcookbook;           

import javax.servlet.*;
import javax.servlet.http.*;

public class IncludeServlet extends HttpServlet {
    
    public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
        
        response.setContentType("text/html");
        java.io.PrintWriter out = response.getWriter();
        
        out.println("<html>");
        out.println("<head>");
        out.println("<title>Include Servlet</title>");  
        out.println("</head>");
        out.println("<body>");
        out.println("<h1>Welcome To Our Universe</h1>");
        out.println("Imagine the rest of the page here.<br><br>");
        //Include the copyright information
        RequestDispatcher dispatcher = request.getRequestDispatcher("/copyright");
        dispatcher.include(request, response);

        out.println("</body>");
        out.println("</html>");
      
        out.close();
        
    } 
}
