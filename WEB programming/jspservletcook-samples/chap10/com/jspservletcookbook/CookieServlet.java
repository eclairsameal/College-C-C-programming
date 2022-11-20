package com.jspservletcookbook;           

import javax.servlet.*;
import javax.servlet.http.*;

public class CookieServlet extends HttpServlet {

    public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    
    Cookie cookie = null;
    //Get an array of Cookies associated with this domain
    Cookie[] cookies = request.getCookies();
    boolean newCookie = false;
    
    //Get the 'mycookie' Cookie if it exists
    if (cookies != null){
        for (int i = 0; i < cookies.length; i++){
            if (cookies[i].getName().equals("mycookie")){
              cookie = cookies[i];
             } 
        }//end for
    }//end if
       
    if (cookie == null){
       newCookie=true;
      //Get the cookie's Max-Age from a context-param element
      //If the 'cookie-age' param is not set properly
      //then set the cookie to a default of -1, 'never expires'
      int maxAge;
      try{
           maxAge = new Integer(getServletContext().getInitParameter("cookie-age")).intValue();
           } catch (Exception e) {
            maxAge = -1;
           }
      
       //Create the Cookie object
     
        cookie = new Cookie("mycookie",""+getNextCookieValue());
        cookie.setPath(request.getContextPath());
        cookie.setMaxAge(maxAge);
        response.addCookie(cookie);
        
        }//end if
        // get some info about the cookie
        response.setContentType("text/html");
        java.io.PrintWriter out = response.getWriter();
    
        out.println("<html>");
        out.println("<head>");
        out.println("<title>Cookie info</title>");  
        out.println("</head>");
        out.println("<body>");
        
        out.println("<h2> Information about the cookie named \"mycookie\"</h2>");
        
        out.println("Cookie value: "+cookie.getValue()+"<br>");
        if (newCookie){
        out.println("Cookie Max-Age: "+cookie.getMaxAge()+"<br>");
        out.println("Cookie Path: "+cookie.getPath()+"<br>");
        }
        
        out.println("</body>");
        out.println("</html>");
    
        out.close();
    } 
    private long getNextCookieValue(){
    
    /*This produces a cookie value to show how to create Cookie objects. If 
      this method was heavily used in a production environment it may
      produce too many objects; synchronization of a single Date object
      might be better, based on performance testing. At any rate a
      production environment would produce a unique cookie value in a
      different manner such as from a unique database ID. */

    //returns the number of milleseconds since Jan 1, 1970
    return new java.util.Date().getTime();
    
    }


    public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
        
        doGet(request,response);
    } 
}
