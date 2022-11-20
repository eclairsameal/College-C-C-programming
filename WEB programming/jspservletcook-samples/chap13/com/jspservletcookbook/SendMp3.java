package com.jspservletcookbook;           

import java.io.FileInputStream;
import java.io.BufferedInputStream;
import java.io.File;
import java.io.IOException;

import javax.servlet.*;
import javax.servlet.http.*;

public class SendMp3 extends HttpServlet {

  public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    
      //get the file name from the 'file' parameter
      String fileName = (String) request.getParameter("file");
      if (fileName == null || fileName.equals(""))
           throw new ServletException(
            "Invalid or non-existent file parameter in SendMp3 servlet.");
      
      // add the .mp3 suffix if it doesn't already exist
      if (fileName.indexOf(".mp3") == -1)
          fileName = fileName + ".mp3";
          
      //where are MP3 files kept?
     String mp3Dir = getServletContext().getInitParameter("mp3-dir");
     if (mp3Dir == null || mp3Dir.equals(""))
           throw new ServletException(
             "Invalid or non-existent mp3Dir context-param.");
          
      ServletOutputStream stream = null;
      BufferedInputStream buf = null;
     try{
     
     stream = response.getOutputStream();
     File mp3 = new File(mp3Dir + "/" + fileName);
     
      //set response headers
      response.setContentType("audio/mpeg");
      
      response.addHeader(
        "Content-Disposition","attachment; filename="+fileName );

      response.setContentLength( (int) mp3.length() );
      
     FileInputStream input = new FileInputStream(mp3);
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
