package com.jspservletcookbook;           

import javax.servlet.*;
import javax.servlet.http.*;
import com.oreilly.servlet.MultipartRequest;
import com.oreilly.servlet.multipart.DefaultFileRenamePolicy;
import java.util.Enumeration;

public class UploadServlet extends HttpServlet {
   
    private String webTempPath;

public void init(){
   
webTempPath =   getServletContext().getRealPath("/") + "data"; 
   
}
    public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
        
       //file limit size of five megabytes
        MultipartRequest mpr = new MultipartRequest(request,webTempPath,
		(5 * 1024 * 1024));
        Enumeration enum = mpr.getFileNames();
        
        response.setContentType("text/html");
        java.io.PrintWriter out = response.getWriter();
    
        out.println("<html>");
        out.println("<head>");
        out.println("<title>Servlet upload</title>");  
        out.println("</head>");
        out.println("<body>");
        
        for (int i = 1; enum.hasMoreElements();i++)
            out.println("The name of uploaded file " + i +" is: " + mpr.getFilesystemName((String) enum.nextElement()) + "<br><br>");
        
        out.println("</body>");
        out.println("</html>");
    
    } 

    public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
        
		throw new ServletException("GET method used with " + getClass().getName()+": POST method required.");
    } 
}
