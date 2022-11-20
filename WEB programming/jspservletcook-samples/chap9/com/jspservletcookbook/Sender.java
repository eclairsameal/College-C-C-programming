package com.jspservletcookbook;

import javax.servlet.*;
import javax.servlet.http.*;

public class Sender extends HttpServlet {
  
 public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {

/* if the servlet tries to access a resource and finds out that the client is not authorized to access it - "401 Unauthorized" */
        response.sendError(401,"You are not authorized to view the requested component");

  /* if the servlet tries to access a resource that is forbidden for this client and there is no further information on it - "403 Forbidden" */
        //response.sendError(403);

/* if the servlet tries to access a resource that is not found given the client's provided URL - "404 Not Found" */
        //response.sendError(404);

  } 
  
  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {

    doPost(request,response);
}
}
