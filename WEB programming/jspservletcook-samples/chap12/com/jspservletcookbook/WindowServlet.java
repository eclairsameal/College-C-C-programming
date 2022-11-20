package com.jspservletcookbook;           

import javax.servlet.*;
import javax.servlet.http.*;

public class WindowServlet extends HttpServlet {
    
  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    
    //URL for the pop-up window is configured
     String url = getInitParameter("popup-url");
    
     if (url == null || url.equals(""))
         url = "/displayHeaders.jsp"; //just in case the initParameter is misconfigured
    
     //add the context path as a prefix to the url, as in /home
     url = request.getContextPath() + url;
     
      response.setContentType("text/html");
      java.io.PrintWriter out = response.getWriter();
      out.println("<html><head>");
      RequestDispatcher dispatcher = request.getRequestDispatcher(
          "/WEB-INF/javascript/functions.js");
      dispatcher.include(request, response);
      
      out.println("<title>Help Page</title></head><body>");
     out.println("<h2>Cookie Info</h2>");
      out.println("<form action =\"\" onSubmit=\" return false\">");
      out.println("<table border=\"0\"><tr><td valign=\"top\">");
      out.println(
      "Click on the button to get more info on cookies: </td>  <td valign=\"top\">" +
       "<input type=\"button\" name=\"button1\" value=\"More Info\" onClick=\"CreateWindow('" +
	    url + "')\"></td></tr>");
      out.println("</table></form>");
     
      out.println("</body></html>");
      out.close();
     } //end doGet
}
