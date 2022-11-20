package com.jspservletcookbook;           

import org.apache.log4j.Logger;
import org.apache.log4j.PropertyConfigurator;

import javax.servlet.*;
import javax.servlet.http.*;

public class LoggerServlet2 extends HttpServlet {

private Logger log = null;

  public void init(){
  
  //load the configuration for this application's loggers using the servletLog.properties file
//  PropertyConfigurator.configure(getServletContext().getRealPath("/") + "WEB-INF/classes/servletLog.properties");
//create the logger for this servlet class
//it will use the configuration for the logger com.jspservletcookbook.LoggerServlet
//or inherit from the logger com.jspservletcookbook ifn one exists, and so on
  log = Logger.getLogger(LoggerServlet2.class);
  
  }

  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    
    //display a DEBUG level message
    log.debug("Sending a DEBUG message from logger2");
    //display an INFO level message
    log.info("Sending an INFO message from logger2");
    
    //better display something
      response.setContentType("text/html");
      java.io.PrintWriter out = response.getWriter();
      out.println("<html><head><title>Servlet logging</title></head><body>");
      out.println("<h2>Hello from LoggerServlet</h2>");
      out.println("Your logger name is: " + log.getName()+"<br>");
	  out.println("Your logger parent is: " + log.getParent().getName()+"<br>");
      out.println("</body></html>");
      out.close();
     } //end doGet
   
    public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
        
        doGet(request,response);
    } 
}
