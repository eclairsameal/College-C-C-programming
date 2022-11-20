package com.jspservletcookbook;           

import javax.servlet.*;
import javax.servlet.http.*;

public class ModuleServlet extends HttpServlet {
    
  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    
     response.setContentType("text/html");
      java.io.PrintWriter out = response.getWriter();
      out.println("<html><head>");
      RequestDispatcher dispatcher = request.getRequestDispatcher("/WEB-INF/javascript/functions.js");
      dispatcher.include(request, response);
      
      out.println("<title>Client Forms</title></head><body>");

      out.println("<h2>Enter Your Name and Email</h2>");
      out.println("<form action=\"/home/displayHeaders.jsp\" name=\"entryForm\" onSubmit=\" return CheckEmail(this.email.value)\">");
      out.println("<table border=\"0\"><tr><td valign=\"top\">");
      out.println("First and last name: </td>  <td valign=\"top\"><input type=\"text\" name=\"name\" size=\"20\"></td></tr>");
      out.println("<tr><td valign=\"top\">");
      out.println("Email: </td>  <td valign=\"top\"><input type=\"text\" name=\"email\" size=\"20\"></td>");
      out.println("<tr><td valign=\"top\"><input type=\"submit\" value=\"Submit\" ></td>");
      out.println("</tr></table></form>");
     
      out.println("</body></html>");
  
     } //end doGet
}
