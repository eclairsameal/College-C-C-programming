package com.jspservletcookbook;           

import org.apache.log4j.Logger;
import org.apache.log4j.PropertyConfigurator;

import javax.servlet.*;
import javax.servlet.http.*;

public class LoggerServlet extends HttpServlet {

private Logger log = null;

  public void init(){
  
 String realPath = getServletContext().getRealPath("/");
 String fileSep = System.getProperty("file.separator" );
  
  if (realPath != null && (! realPath.endsWith(fileSep)))
      realPath = realPath + fileSep;
	  
	  System.out.println(realPath);
  
  //load the configuration for this application's loggers using the servletLog.properties file
  PropertyConfigurator.configure(realPath + "WEB-INF/classes/servletLog.properties");
//create the logger for this servlet class
//it will use the configuration for the logger com.jspservletcookbook.LoggerServlet
//or inherit from the logger com.jspservletcookbook if one exists, and so on
  log = Logger.getLogger(LoggerServlet.class);
   log.info("LoggerServlet started.");
  
  }

  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    
    //display a DEBUG level message
    log.debug("Sending a DEBUG message");
    //display an INFO level message
    log.info("Sending an INFO message");
    
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
