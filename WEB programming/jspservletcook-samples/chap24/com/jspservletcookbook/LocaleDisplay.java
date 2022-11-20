package com.jspservletcookbook;           

import java.util.Enumeration;
import java.util.Locale;

import javax.servlet.*;
import javax.servlet.http.*;

public class LocaleDisplay extends HttpServlet {

  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    
      //Get the client's Locales
     Enumeration enum = request.getLocales();
	 //Get the preferred Locale
	 Locale preferred = request.getLocale();
	 String prefDisplay = "";
	 if (preferred != null)
	     prefDisplay = preferred.getDisplayName(); 
    
     //Display the preferred and any other locales
     response.setContentType("text/html");
     java.io.PrintWriter out = response.getWriter();
     out.println("<html><head><title>Locale Display</title></head><body>");
      
     out.println("<h2>Here is your Locale info...</h2>");
	 out.println("<b>Preferred Locale:</b> ");
     out.println( prefDisplay );
	 out.println("<br />");
     out.println("Locale country: ");
	 if (preferred != null)
     out.println( preferred.getDisplayCountry() );
	 
     out.println("<br />");
     out.println("Locale language: ");
     if (preferred != null)
     out.println( preferred.getDisplayLanguage() );
     out.println("<br /><br />");
	 out.println("<h3>Lower priority Locales...</h3>");
	 Locale loc = null;
	 while (enum.hasMoreElements()){
	     loc = (Locale)enum.nextElement();
         if (! (loc.getDisplayName().equals( prefDisplay ))){
             out.println("Locale: ");
             out.println( loc.getDisplayName() );
             out.println("<br />");
             out.println("Locale country: ");
             out.println( loc.getDisplayCountry() );
             out.println("<br />");
             out.println("Locale language: ");
             out.println( loc.getDisplayLanguage() );
			 out.println("<br /><br />");
		 }//if
     }//while
      out.println("</body></html>");
     
      
     } //end doGet

}
