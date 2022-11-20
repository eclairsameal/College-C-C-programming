package com.jspservletcookbook;           

import java.util.Enumeration;

import javax.servlet.*;
import javax.servlet.http.*;

public class RequestHeaderView extends HttpServlet {

  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    
    //get an Enumeration of all the request header names
    Enumeration enum = request.getHeaderNames();
    
        
    //display 
      response.setContentType("text/html");
      java.io.PrintWriter out = response.getWriter();
      out.println("<html><head><title>Request Header View</title></head><body>");
      out.println("<h2>Request Headers</h2>");
      String header = null;
      
      while (enum.hasMoreElements()){
          header = (String) enum.nextElement();
          //getHeader returns null if a request header of that name does not exist in the request
         out.println( "<strong>"+header+"</strong>"+": "+request.getHeader(header)+"<br>" );
		 }
    
      out.println("</body></html>");
     
     } //end doGet
	 
	 public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
	    doGet(request,response);
	}

}
