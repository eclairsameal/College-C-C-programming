package com.jspservletcookbook;

import java.io.IOException;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException; 

import javax.servlet.*;
import javax.servlet.http.*;

public class JndiTFilter implements Filter {
    
    private FilterConfig config;
    private Context env;
    
    public JndiTFilter() {}
    
    public void  init(FilterConfig filterConfig)  throws ServletException {
    
      this.config = filterConfig;
      
       try {
           
               env = (Context) new InitialContext().lookup("java:comp/env");
			   
			   env.close();
             
      } catch (NamingException ne) { 
        
          try{ env.close(); } catch (NamingException nex) {}

          throw new ServletException(ne);


        }
      
    }
    
    public void  doFilter(ServletRequest request, ServletResponse response, 
      FilterChain chain) throws IOException, ServletException {
      
        StockPriceBean spbean = null;
        
        try {
        
            spbean = (StockPriceBean) env.lookup("bean/pricebean");
            
        } catch (NamingException ne) { }
        
        HttpServletRequest hRequest = null;
        
            
        if (request instanceof HttpServletRequest)
            hRequest = (HttpServletRequest) request;
                 
        HttpSession hSession = hRequest.getSession();
            
        if (hSession != null)
            hSession.setAttribute("MyBean",spbean);
        
        
        chain.doFilter(request,response);

    }// doFilter
    
    public void destroy(){
        /*called before the Filter instance is removed 
        from service by the web container*/
    }
    
}
