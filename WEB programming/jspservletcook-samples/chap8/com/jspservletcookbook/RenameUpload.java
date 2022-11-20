package com.jspservletcookbook;

import javax.servlet.*;
import javax.servlet.http.*;

import com.oreilly.servlet.multipart.MultipartParser;
import com.oreilly.servlet.multipart.Part;
import com.oreilly.servlet.multipart.FilePart;

public class RenameUpload extends HttpServlet {
   
    private String fileSavePath;

public void init(){
   
    fileSavePath =   getServletContext().getRealPath("/") + "data"; 
   
}
    public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {

    response.setContentType("text/html");
        java.io.PrintWriter out = response.getWriter();
    
        out.println("<html>");
        out.println("<head>");
        out.println("<title>File uploads</title>");  
        out.println("</head>");
        out.println("<body>");

        out.println("<h2>Here is information about any uploaded files</h2>");

try{
       // file limit size of five megabytes
      MultipartParser parser = new MultipartParser(request,5 * 1024 * 1024);
      Part _part = null;

 while ((_part = parser.readNextPart()) != null) {
       
       if (_part.isFile()) {

           // get some info about the file
          FilePart fPart = (FilePart) _part;
          String name = fPart.getFileName();
     
      if (name != null) {

          long fileSize = fPart.writeTo(new java.io.File(fileSavePath));
         out.println("The name of the file: " +  name + "<br>");
         out.println("The content type of the file: " +   fPart.getContentType()+ "<br>");
         out.println("The file size: " +fileSize+ "<br><br>");

       //commence with another file, if there is one
       } else {
  
     out.println("The user did not upload a file for this part.");
    }
}    else if (_part.isParam()) {
              // do something else if it is a non-file type parameter, such as a user name
  }
  
  }// end while


        out.println("</body>");
        out.println("</html>");

        out.close();

} catch (java.io.IOException ioe){
       
   //an error-page in the deployment descriptor is 
   //mapped to the java.io.IOException
   throw new java.io.IOException(
       "IOException occurred in: " + getClass().getName());
}
    } 

    public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
        
    throw new ServletException(
        "GET method used with " + getClass().getName()+": POST method required.");
    }
}
