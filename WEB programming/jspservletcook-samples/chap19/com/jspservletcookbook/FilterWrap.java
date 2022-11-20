package com.jspservletcookbook;

import javax.servlet.*;
import javax.servlet.http.*;

public class FilterWrap implements Filter {
    
    private FilterConfig config;

    
    /** Creates new RequestFilter */
    public FilterWrap() {}
    
    public void  init(FilterConfig filterConfig)  throws ServletException{
    
        this.config = filterConfig;
       
    }
    
    public void  doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws java.io.IOException, ServletException {
 
        if(response instanceof HttpServletResponse){
            chain.doFilter(request,new ResponseWrapper((HttpServletResponse)response));
		} else {
		    chain.doFilter(request,response);
		}
    }// doFilter
    
    public void destroy(){
        /*called before the Filter instance is removed 
        from service by the web container*/

    }
}
