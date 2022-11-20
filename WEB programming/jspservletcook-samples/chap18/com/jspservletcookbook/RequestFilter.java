package com.jspservletcookbook;

import javax.servlet.*;
import javax.servlet.http.*;

public class RequestFilter implements Filter {
    
    private FilterConfig config;
    
    /** Creates new RequestFilter */
    public RequestFilter() {
    }
    
    public void  init(FilterConfig filterConfig)  throws ServletException{
    
        this.config = filterConfig;
    }
    
    public void  doFilter(ServletRequest request, ServletResponse response, FilterChain chain)
        throws java.io.IOException, ServletException {
 
          ReqWrapper wrapper = null;
          ServletContext context = null;
          
          if (request instanceof HttpServletRequest)
              wrapper = new ReqWrapper((HttpServletRequest)request);
              
          /* use the ServletContext.log method to log 
          param names/values */
          if (wrapper != null){
           context = config.getServletContext();
           context.log("Query: " + wrapper.getQueryString());}

       
         //continue the request, response to next filter or servlet
        //destination
        if (wrapper != null)
            chain.doFilter(wrapper,response);
        else
            chain.doFilter(request,response);
    }
    
    public void destroy(){
        /*called before the Filter instance is removed 
        from service by the web container*/
    }
}
