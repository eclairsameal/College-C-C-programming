package com.jspservletcookbook;

import javax.servlet.*;
import javax.servlet.http.*;

public class ReqListener implements ServletRequestListener {

private static long reqCount;

public void requestInitialized(ServletRequestEvent sre){

    
   ServletContext context = sre.getServletContext();
   ServletRequest request = sre.getServletRequest();
   
  synchronized (context){
   context.log("Request for "+
       (request instanceof HttpServletRequest ? ((HttpServletRequest) request).getRequestURI() : "Unknown")+"; Count="+ ++reqCount);
   } 

}

public void requestDestroyed(ServletRequestEvent sre){

}

}