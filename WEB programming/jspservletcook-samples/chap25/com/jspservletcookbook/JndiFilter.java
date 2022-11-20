package com.jspservletcookbook;

import java.io.IOException;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException; 

import javax.servlet.*;
import javax.servlet.http.*;

public class JndiFilter implements Filter {
    
    private FilterConfig config;

    private Context env;
    
  public JndiFilter() {}
    
  public void  init(FilterConfig filterConfig)  throws ServletException {
    
     this.config = filterConfig;
      
     try {
           
         env = (Context) new InitialContext();
             
      } catch (NamingException ne) { 

          throw new ServletException(ne);

     }
      
    }
    
  public void  doFilter(ServletRequest request, ServletResponse response, 
    FilterChain chain) throws IOException, ServletException {
      
      javax.mail.Session mailSession = null;
 
       try {
        
           mailSession = (javax.mail.Session) env.lookup("MyEmail");
            
       } catch (NamingException ne) { }
        
       HttpServletRequest hRequest = null;
        
            
       if (request instanceof HttpServletRequest){

          hRequest = (HttpServletRequest) request;
                 
          HttpSession hSession = hRequest.getSession();
            
          if (hSession != null)
              hSession.setAttribute("MyEmail",mailSession);

       }//if
        
       chain.doFilter(request,response);

  }// doFilter
    
  public void destroy(){
        /*called before the Filter instance is removed 
        from service by the web container*/
  }
    
}
