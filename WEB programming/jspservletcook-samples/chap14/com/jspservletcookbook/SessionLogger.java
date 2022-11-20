package com.jspservletcookbook;     

import org.apache.log4j.Logger;
import org.apache.log4j.PropertyConfigurator;

import javax.servlet.*;
import javax.servlet.http.*;

public class SessionLogger implements HttpSessionListener
{

  private Logger log;

  public SessionLogger(){
  
      /*The loggers are typically initialized by a special initialization 
   listener or servlet.  If this is not the case, then initialize the
    logger here:
	
    java.util.ResourceBundle bundle =
    java.util.ResourceBundle.getBundle(
    "com.jspservletcookbook.global");
    PropertyConfigurator.configure(bundle.getString(
    "log-configure-path"));*/

  log = Logger.getLogger(SessionLogger.class);

  }
  
  public void sessionCreated(HttpSessionEvent se)   {
    
    //log request of the INFO level
    log.info("HttpSession created: " + se.getSession().getId());
    
      
    } 
    
public void sessionDestroyed(HttpSessionEvent se) {
    
    //log request about session's that are invalidated
    log.info("HttpSession invalidated: " + se.getSession().getId());
      
    } 
   
}
