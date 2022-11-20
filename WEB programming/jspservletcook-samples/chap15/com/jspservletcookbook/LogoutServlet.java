package com.jspservletcookbook;           

import javax.servlet.*;
import javax.servlet.http.*;

public class LogoutServlet extends HttpServlet {

  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    
       HttpSession session = request.getSession();
       response.setContentType("text/html");
       java.io.PrintWriter out = response.getWriter();
       out.println("<html><head><title>Authenticated User Info</title></head><body>");
	   out.println("<h2>Logging out a user</h2>");
       out.println("request.getRemoteUser() returns: ");
       String remUser = request.getRemoteUser();
       out.println(remUser == null ? "Not authenticated." : remUser );
       out.println("<br>");
       out.println("request.isUserInRole(\"dbadmin\")  returns: ");
       boolean isInRole = request.isUserInRole("dbadmin");
       out.println(isInRole);
       out.println("<br>");
       //log out the user
       session.invalidate();
       out.println("</body></html>");
       out.close();
      
     } //doGet
     
     public void doPost(HttpServletRequest request, 
       HttpServletResponse response) throws ServletException, 
       java.io.IOException {
       
         doGet(request,response);
         
    }//doPost

}
