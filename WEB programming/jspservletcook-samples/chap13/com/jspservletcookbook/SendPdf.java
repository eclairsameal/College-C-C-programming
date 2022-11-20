package com.jspservletcookbook;           

import java.io.FileInputStream;
import java.io.BufferedInputStream;
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.*;
import javax.servlet.http.*;

public class SendPdf extends HttpServlet {

  public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    
      //get the file name from the 'file' parameter
      String fileName = (String) request.getParameter("file");
      if (fileName == null || fileName.equals(""))
           throw new ServletException(
            "Invalid or non-existent file parameter in SendPdf servlet.");
      
      // add the .pdf suffix if it doesn't already exist
      if (fileName.indexOf(".pdf") == -1)
          fileName = fileName + ".pdf";
          
      //where are PDFs kept?
     String pdfDir = getServletContext().getInitParameter("pdf-dir");
     if (pdfDir == null || pdfDir.equals(""))
           throw new ServletException(
             "Invalid or non-existent 'pdf-Dir' context-param.");
          
      ServletOutputStream stream = null;
      BufferedInputStream buf = null;
     try{
     
     stream = response.getOutputStream();
     File pdf = new File(pdfDir + "/" + fileName);
     
      //set response headers
      response.setContentType("application/pdf");
      
      response.addHeader(
        "Content-Disposition","attachment; filename="+fileName );

      response.setContentLength( (int) pdf.length() );
      
     FileInputStream input = new FileInputStream(pdf);
     buf = new BufferedInputStream(input);
     int readBytes = 0;

     //read from the file; write to the ServletOutputStream
     while((readBytes = buf.read()) != -1)
        stream.write(readBytes);

     } catch (IOException ioe){
     
        throw new ServletException(ioe.getMessage());
         
     } finally {
	 
//close the input/output streams
	 if(stream != null)
	     stream.close();
	  if(buf != null)
          buf.close();
		  }
    
    } //end doGet
   
    public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
	
	doGet(request,response);
  
    } 
}
