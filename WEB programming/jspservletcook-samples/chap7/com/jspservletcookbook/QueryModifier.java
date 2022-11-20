package com.jspservletcookbook;

import javax.servlet.*;
import javax.servlet.http.*;

public class QueryModifier extends HttpServlet {
  
 public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    
    String requestUrl = request.getRequestURL().toString();
    String querystr = request.getQueryString();
    if (querystr != null){
        querystr = querystr +
         "&inspector-name=Jen&inspector-email=Jenniferq@yahoo.com";
    } else {
        querystr = "inspector-name=Jen&inspector-email=Jenniferq@yahoo.com";}
        
    RequestDispatcher dispatcher =
      request.getRequestDispatcher("/viewPost.jsp?"+querystr);
     dispatcher.forward(request,response);
}

public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
        
  doGet(request,response);
        
  } 
  
}
