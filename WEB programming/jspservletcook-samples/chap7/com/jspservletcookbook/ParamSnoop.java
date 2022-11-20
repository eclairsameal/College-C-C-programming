package com.jspservletcookbook;

import javax.servlet.*;
import javax.servlet.http.*;

import java.util.Map;
import java.util.Iterator;
import java.util.Map.Entry;

public class ParamSnoop implements Filter {
    
    private FilterConfig config;
    
    /** Creates new ParamSnoop */
    public ParamSnoop() {
    }
    
    public void  init(FilterConfig filterConfig)  throws ServletException{
    
        this.config = filterConfig;
		
    }
    
    public void  doFilter(ServletRequest request, ServletResponse response, FilterChain chain)
    throws java.io.IOException, ServletException {
    
	    
        Map paramMap = request.getParameterMap();
        ServletContext context = config.getServletContext();
        /* use the ServletContext.log method to log 
        param names/values */
         context.log("doFilter called in: " + config.getFilterName() +  
          " on " + (new java.util.Date()));
        context.log("Snooping the parameters in request: " + 
            ((HttpServletRequest) request).getRequestURI());
            
         Iterator iter = paramMap.entrySet().iterator();
          while (iter.hasNext()){
             
             Map.Entry me = (Map.Entry) iter.next();
             context.log((String)me.getKey() + ": " + ((String[]) me.getValue())[0]);
          }

        chain.doFilter(request,response); 
		
    }
    
    public void destroy(){
        /*called before the Filter instance is removed 
        from service by the web container*/
    }
}
