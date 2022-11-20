package com.jspservletcookbook;

import java.io.PrintWriter;
import java.io.IOException;

import javax.servlet.*;
import javax.servlet.http.*;

public class BlockFilter implements Filter {
    
    private FilterConfig config;
    
    /** Creates new BlockFilter */
    public BlockFilter() {}
    
    public void  init(FilterConfig filterConfig)  throws ServletException{
    
        this.config = filterConfig;
    }
    
    public void  doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
 
    HttpServletRequest req = null;
    boolean authenticated = false;
    PrintWriter out = null;
     
    if (request instanceof HttpServletRequest){
        
         req = (HttpServletRequest) request;
         String user = req.getParameter("user");
         authenticated = authenticateUser(user);
        }

        if (authenticated){
            chain.doFilter(request,response);
        } else {
            
          response.setContentType("text/html");
          out = response.getWriter();
          out.println("<html><head><title>Authentication Response</title></head><body>");
          out.println("<h2>Sorry your authentication attempt failed</h2>");
          
          out.println("</body></html>");
          out.close();
            
        }
    }// doFilter
    
    public void destroy(){
        /*called before the Filter instance is removed 
        from service by the web container*/
    }
    
    private boolean authenticateUser(String userName){
    
        //authenticate the user using JNDI and a database, for instance
        return false;
    
    }
}
