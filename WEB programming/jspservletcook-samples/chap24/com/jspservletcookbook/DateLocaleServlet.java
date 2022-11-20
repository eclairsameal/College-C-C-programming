package com.jspservletcookbook;           

import java.text.DateFormat;

import java.util.Date;
import java.util.Locale;
import java.util.ResourceBundle;

import javax.servlet.*;
import javax.servlet.http.*;

public class DateLocaleServlet extends HttpServlet {

  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    
    //Get the client's Locale
   Locale locale = request.getLocale();
   ResourceBundle bundle = ResourceBundle.getBundle("i18n.WelcomeBundle",locale);
   String welcome =  bundle.getString("Welcome");
   String date = DateFormat.getDateTimeInstance(DateFormat.FULL, 
                         DateFormat.SHORT, locale).format(new Date());
   
    
    //Display the locale
      response.setContentType("text/html");
      java.io.PrintWriter out = response.getWriter();
      out.println("<html><head><title>"+welcome+"</title></head><body>");
      
      out.println("<h2>"+bundle.getString("Hello") + " " +
        bundle.getString("and") + " " +
          welcome+"</h2>");
        
        out.println(date+  "<br /><br />");
		
		java.util.Enumeration enum = bundle.getKeys();
		while (enum.hasMoreElements()){
		
		    out.println((String) enum.nextElement());
			out.println("<br /><br />");
		
		}
      
      out.println("Locale: ");
      out.println( locale.getLanguage()+"_"+locale.getCountry() );
      
      out.println("</body></html>");
     
      
     } //end doGet

}
