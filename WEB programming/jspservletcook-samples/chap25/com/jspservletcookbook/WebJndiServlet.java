package com.jspservletcookbook;    

import java.io.IOException;  
import java.io.PrintWriter;   

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;  

import javax.rmi.PortableRemoteObject;

import javax.servlet.*;
import javax.servlet.http.*;

public class WebJndiServlet extends HttpServlet {

  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    
    String state = request.getParameter("state");
    Context env = null;
    Abbrev abbrev = null;
    AbbrevHome home = null;
        
       try{
            
             env = (Context) new InitialContext();
             
             Object localH  = env.lookup("AbbrevHome");
             
            home = (AbbrevHome) PortableRemoteObject.narrow(localH, AbbrevHome.class);
             
              //close the InitialContext
             env.close();
             
             if (home == null)
             throw new ServletException("AbbrevHome is an unknown JNDI object");
             
             abbrev = (Abbrev) PortableRemoteObject.narrow(home.create(), Abbrev.class);
             
        } catch (NamingException ne) { 
        
            try{ env.close();} catch (NamingException nex) { }
            
           throw new ServletException(ne);
           
         } catch (javax.ejb.CreateException ce) { 
         
             throw new ServletException(ce);
         
         }
    
    
    
    //set the MIME type of the response, "text/html"
    response.setContentType("text/html");
    
    //use a PrintWriter send text data to the client who has requested the servlet
    java.io.PrintWriter out = response.getWriter();
    
    //Begin assembling the HTML content
    out.println("<html><head>");
    
    out.println("<title>State abbreviations</title></head><body>");
    out.println("<h2>Here is the state's abbreviation</h2>");
    
    if (state != null)
        out.println( abbrev.getAbbreviation(state.toUpperCase()) );
	
	try{
		
        abbrev.remove();
		
	} catch (javax.ejb.RemoveException re){}
   
    out.println("</body></html>");
    
    out.close();
     } //end doGet
     
     public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
       
         doGet(request, response);
    
    }// doPost
    
}//BeanServlet
