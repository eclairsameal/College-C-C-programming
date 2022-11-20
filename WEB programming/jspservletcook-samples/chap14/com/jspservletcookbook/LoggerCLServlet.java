package com.jspservletcookbook;           

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import javax.servlet.*;
import javax.servlet.http.*;

public class LoggerCLServlet extends HttpServlet {

private Log log = null;

  public void init(){
  
  //System.setProperty("org.apache.commons.logging.Log","org.apache.commons.logging.impl.Log4JLogger");
	  
  log = LogFactory.getLog(LoggerCLServlet.class);
  log.info("LoggerCLServlet started.");
  
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
      out.println("<h2>Hello from LoggerCLServlet: " + log.getClass().getName() + "</h2>");
      out.println("Is the log info enabled? " + log.isInfoEnabled() +"<br>");
	  out.println("Is the log debug enabled?" + log.isDebugEnabled()+"<br>");
      out.println("</body></html>");
      out.close();
     } //end doGet
   
    public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
        
        doGet(request,response);
    } 
}
