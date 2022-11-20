package com.jspservletcookbook;        

import javax.servlet.*;
import javax.servlet.http.*;

public class IncludeFilter extends HttpServlet {

   public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    
    RequestDispatcher dispatch = request.getRequestDispatcher("/requestheaders");
    dispatch.include(request,response);
    
     } //end doGet
}
