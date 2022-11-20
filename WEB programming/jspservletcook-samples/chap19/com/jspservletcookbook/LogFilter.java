package com.jspservletcookbook;

import javax.servlet.*;
import javax.servlet.http.*;

import org.apache.log4j.Logger;
import org.apache.log4j.PropertyConfigurator;

public class LogFilter implements Filter {
    
    private FilterConfig config;
    private Logger log;
    
    /** Creates new RequestFilter */
    public LogFilter() {}
    
    public void  init(FilterConfig filterConfig)  throws ServletException{
    
        this.config = filterConfig;
        //load the configuration for this application's loggers using the servletLog.properties file
  PropertyConfigurator.configure(config.getServletContext().getRealPath("/") +
      "WEB-INF/classes/servletLog.properties");
        log = Logger.getLogger(LogFilter.class);
        log.info("Logger instantiated in "+ getClass().getName());
    }
    
    public void  doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws java.io.IOException, ServletException {
 
    HttpServletRequest req = null;
    String id = config.getInitParameter("log-id");
    
    if (id == null)
        id = "unknown";
     
    if (log != null && (request instanceof HttpServletRequest)){
        
        req = (HttpServletRequest) request;
        log.info(
            "Log id:" + id + ": Request received from: " + req.getRemoteHost() + " for " +
                req.getRequestURL()); }

        chain.doFilter(request,response);
    }// doFilter
    
    public void destroy(){
        /*called before the Filter instance is removed 
        from service by the web container*/
        log = null;
    }
}
