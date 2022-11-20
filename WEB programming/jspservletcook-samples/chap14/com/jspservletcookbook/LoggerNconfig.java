package com.jspservletcookbook;           

import org.apache.log4j.Logger;
import org.apache.log4j.BasicConfigurator;

import javax.servlet.*;
import javax.servlet.http.*;

public class LoggerNconfig extends HttpServlet {

private Logger log = null;

  public void init(){
  
      log = Logger.getRootLogger();
      
      BasicConfigurator.configure();
}

  public void doGet(HttpServletRequest request, 
    HttpServletResponse response)
      throws ServletException, java.io.IOException {
    
    //display a DEBUG level message
    log.debug("Sending a DEBUG message");

    // display an INFO level message
    log.info("Sending an INFO message");
    
    //better display some HTML
      response.setContentType("text/html");
      java.io.PrintWriter out = response.getWriter();
      out.println(
        "<html><head><title>Servlet logging</title></head><body>");
      out.println("<h2>Hello from a Logger with no Config file</h2>");
      out.println("Your logger name is: " + log.getName()+"<br>");
      out.println(
        "Your logger parent is: " + log.getParent().getName()+"<br>");
      out.println("</body></html>");
   
     } //end doGet
   
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, java.io.IOException {
        
        doGet(request,response);
    } 
}
