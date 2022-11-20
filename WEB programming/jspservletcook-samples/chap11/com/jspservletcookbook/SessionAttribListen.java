package com.jspservletcookbook;

import javax.servlet.*;
import javax.servlet.http.*;

public class SessionAttribListen implements HttpSessionAttributeListener {

    /** Creates new SessionAttribListen */
    public SessionAttribListen() {
        
        System.out.println(getClass().getName());
    }
    
   public void attributeAdded(HttpSessionBindingEvent se) {
       
        HttpSession session = se.getSession();
        String id = session.getId();
        String name = se.getName();
        String value = (String) se.getValue();
        String source = se.getSource().getClass().getName();
        String message = new StringBuffer(
         "Attribute bound to session in ").append(source).
           append("\nThe attribute name: ").append(name).
             append("\n").append("The attribute value:").
               append(value).append("\n").
                 append("The session ID: ").
                   append(id).toString();
        System.out.println(message);
   }
   
     public void attributeRemoved(HttpSessionBindingEvent se) {
         
         HttpSession session = se.getSession();
         String id = session.getId();
         String name = se.getName();
         if(name == null)
             name = "Unknown";
         String value = (String) se.getValue();
         String source = se.getSource().getClass().getName();
         String message = new StringBuffer(
           "Attribute unbound from session in ").append(source).
              append("\nThe attribute name: ").append(name).
                append("\n").append("The attribute value: ").
                  append(value).append("\n").append(
                    "The session ID: ").append(id).toString();
         System.out.println(message);
   }
   
     public void attributeReplaced(HttpSessionBindingEvent se) {
         
          String source = se.getSource().getClass().getName();
          String message = new StringBuffer(
            "Attribute replaced in session  ").
              append(source).toString();
          System.out.println(message);
   }
}
