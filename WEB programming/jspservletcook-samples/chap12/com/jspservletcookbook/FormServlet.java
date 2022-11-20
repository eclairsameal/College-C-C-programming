package com.jspservletcookbook;           

import javax.servlet.*;
import javax.servlet.http.*;

public class FormServlet extends HttpServlet {
    
  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    
     
    response.setContentType("text/html");
    java.io.PrintWriter out = response.getWriter();
    out.println("<html><head>");
      
    RequestDispatcher dispatcher = request.getRequestDispatcher(
        "/WEB-INF/javascript/validate.js");

    dispatcher.include(request, response);
      
    out.println("<title>Help Page</title></head><body>");
    out.println("<h2>Please submit your information</h2>");
   
    out.println(
        "<form action =\"" + request.getContextPath() +
            "/displayHeaders.jsp\" onSubmit=\" return validate(this)\">");

    out.println("<table border=\"0\"><tr><td valign=\"top\">");
    out.println("Your name: </td>  <td valign=\"top\">");
    out.println("<input type=\"text\" name=\"username\" size=\"20\">");
    out.println("</td></tr><tr><td valign=\"top\">");
    out.println("Your email: </td>  <td valign=\"top\">");
    out.println("<input type=\"text\" name=\"email\" size=\"20\">");
    out.println("</td></tr><tr><td valign=\"top\">");

    out.println("<input type=\"submit\" value=\"Submit Info\"></td></tr>");
    out.println("</table></form>");
    out.println("</body></html>");
    out.close();
     } //end doGet
}
