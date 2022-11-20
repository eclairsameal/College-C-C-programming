package com.jspservletcookbook;           

import javax.servlet.*;
import javax.servlet.http.*;

public class FlashServlet extends HttpServlet {
    
  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    

      response.setContentType("text/html");
      java.io.PrintWriter out = response.getWriter();
      out.println("<html><head><title>Embedded flash content</title></head><body>");
      
      RequestDispatcher dispatcher = request.getRequestDispatcher("/flash.txt");
      dispatcher.include(request, response);

      out.println("</body></html>");
     
     } //doGet
     
     public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    
        doGet(request,response);
    
    }//doPost
}
