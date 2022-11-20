package com.jspservletcookbook;

import java.io.IOException;
import java.util.Enumeration;

import javax.servlet.*;
import javax.servlet.http.*;

public class CheckFilter implements Filter {
    
    private FilterConfig config;
    
    public CheckFilter() {}
    
    public void  init(FilterConfig filterConfig)  throws ServletException {
    
      this.config = filterConfig;
      
    }
    
    public void  doFilter(ServletRequest request, ServletResponse response, 
      FilterChain chain) throws IOException, ServletException {
        
         Enumeration params = request.getParameterNames();
         boolean rejected = false;
         
         while (params.hasMoreElements()){
         
             if (isEmpty( request.getParameter( (String) params.nextElement()) ) ){
                 reject(request,response);
                 rejected = true;
            }
         
          }
         
          if (! rejected)
              chain.doFilter(request,response);
        
    }// doFilter
    
    private boolean isEmpty(String param){
    
        if (param == null || param.length() < 1){
            return true;
        }
        
        return false;
    
    }
    
    private void reject(ServletRequest request, ServletResponse response) 
       throws IOException, ServletException {
        
        request.setAttribute(
            "errorMsg","Please make sure to provide a valid value for all of the text fields.");
        
        Enumeration params = request.getParameterNames();
        String paramN = null;
		 
		 while (params.hasMoreElements()){
		 
		    paramN = (String) params.nextElement();
		 
		    request.setAttribute(
		        paramN, request.getParameter(paramN));
         
         }
         
        
        RequestDispatcher dispatcher = request.getRequestDispatcher("/form.jsp"); 
        dispatcher.forward(request,response);
    
    }
    
    public void destroy(){
        /*called before the Filter instance is removed 
        from service by the web container*/
    }
    
}
