package com.jspservletcookbook;              

import javax.servlet.*;
import javax.servlet.http.*;

public class MultipleInc extends HttpServlet {
  
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
        
        response.setContentType("text/html");
        java.io.PrintWriter out = response.getWriter();
        
        out.println("<html>");
        out.println("<head>");
        out.println("<title>Multiple Includes</title>");  
        out.println("</head>");
        out.println("<body>");
        out.println("<h1>Hello from Level 1</h1>");
        out.println("This text is displayed at Level 1.");
        RequestDispatcher dispatcher = request.getRequestDispatcher("/level2");
        dispatcher.include(request, response);
        out.println("</body>");
        out.println("</html>");
        out.close();
        
    } 
}
