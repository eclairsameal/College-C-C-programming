package com.jspservletcookbook;     

import org.apache.log4j.Logger;
import org.apache.log4j.PropertyConfigurator;

import javax.servlet.*;
import javax.servlet.http.*;

public class ContextLogger implements ServletContextListener
 {

  private Logger log;

  public ContextLogger(){}
  
  public void contextDestroyed(ServletContextEvent sce)  {
  
  String name = sce.getServletContext().getServletContextName();
    
    //log request of the INFO level
    log.info("ServletContext shut down: " + (name == null ? "" : name ));
      
    } 
    
public void contextInitialized(ServletContextEvent sce) {

  ServletContext context = sce.getServletContext();
  
 String realPath = context.getRealPath("/");
 String fileSep = System.getProperty("file.separator" );
  
  if (realPath != null && (! realPath.endsWith(fileSep)))
      realPath = realPath + fileSep;
   //Initialize logger here:
  PropertyConfigurator.configure(realPath + "WEB-INF/classes/" + context.getInitParameter("logger-config"));
  log = Logger.getLogger(ContextLogger.class);

 String name = context.getServletContextName();
    //log request about servlet context being initialized
    log.info("ServletContext ready: " + (name == null ? "" : name ));
      
    } 
   
}
