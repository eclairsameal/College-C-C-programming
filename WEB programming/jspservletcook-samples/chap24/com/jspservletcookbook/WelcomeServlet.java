package com.jspservletcookbook;           

import java.util.Locale;
import java.util.ResourceBundle;

import javax.servlet.*;
import javax.servlet.http.*;

public class WelcomeServlet extends HttpServlet {

  public void doGet(HttpServletRequest request, 
    HttpServletResponse response) throws ServletException,
    java.io.IOException {
    
      //Get the client's Locale
      Locale locale = request.getLocale();

      ResourceBundle bundle = ResourceBundle.getBundle(
        "i18n.WelcomeBundle",locale);

      String welcome =  bundle.getString("Welcome");
   
    
      //Display the locale
      response.setContentType("text/html");
      java.io.PrintWriter out = response.getWriter();

      out.println("<html><head><title>"+welcome+"</title></head><body>");
      
      out.println("<h2>"+welcome+"</h2>");
          
      out.println("Locale: ");
      out.println( locale.getLanguage()+"_"+locale.getCountry() );
      
      out.println("</body></html>");
      out.close();
      
     } //end doGet

  // doPost method ... 

}//WelcomeServlet
