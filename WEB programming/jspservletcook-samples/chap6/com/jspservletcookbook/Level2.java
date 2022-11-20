package com.jspservletcookbook;           

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.IOException;

public class Level2 extends HttpServlet {
  
    public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        
         java.io.PrintWriter out = response.getWriter();
        out.println("<h2>Hello from Level 2</h2>");
        out.println("This text is included at Level 2.");
        //Include the JSP file named "level3.jsp"
       try{
         RequestDispatcher dispatcher = request.getRequestDispatcher("/level3.jsp");
        dispatcher.include(request, response);
     } catch (Exception se){
            
            String context_path = (String) request.getAttribute("javax.servlet.include.context_path");
            String servlet_path = (String) request.getAttribute("javax.servlet.include.servlet_path");
            String errMessage = new StringBuffer("Exception raised during Level2 servlet include:<br>").
                append("Context path: "+context_path+"<br>").
                append("Servlet path: "+servlet_path).toString();
            throw new ServletException(errMessage);
            
        }
        
    } 
}
