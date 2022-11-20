package com.jspservletcookbook;           

import javax.servlet.*;
import javax.servlet.http.*;

public class RequestBinder extends HttpServlet {

  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    
    //bind an object to the servlet context
    ContextObject contextObj = new ContextObject();
    contextObj.put( request.getRemoteAddr(), ""+new java.util.Date());
    request.setAttribute(
        "com.jspservletcookbook.RequestObject",contextObj );
    
    //better display something
    RequestDispatcher dispatcher = request.getRequestDispatcher("/displayAttr");
    dispatcher.forward(request,response);
	
	  
     } //end doGet

}
