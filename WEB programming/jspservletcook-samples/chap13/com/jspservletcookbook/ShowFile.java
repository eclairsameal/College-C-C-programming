package com.jspservletcookbook;           

import java.io.FileInputStream;
import java.io.BufferedInputStream;
import java.io.File;
import java.io.IOException;

import javax.servlet.*;
import javax.servlet.http.*;

public class ShowFile extends HttpServlet {

    public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
	
	  ServletOutputStream out = response.getOutputStream();
	  String fileName = request.getParameter("file");
      
        out.println("<html>");
        out.println("<head>");
        out.println("<title>Welcome</title>");  
        out.println("</head>");
        out.println("<body>");
        out.println("<h2>The File</h2>");
        out.println(fileName);
        out.println("</body>");
        out.println("</html>");
        out.close();
    
    } //end doGet
   
    public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        
        doGet(request,response);
    } 
}
