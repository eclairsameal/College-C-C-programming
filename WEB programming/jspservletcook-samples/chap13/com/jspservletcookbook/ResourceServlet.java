package com.jspservletcookbook;           

import java.io.BufferedInputStream;
import java.io.PrintWriter;
import java.io.IOException;

import java.net.URL;
import java.net.URLConnection;
import java.net.MalformedURLException;

import javax.servlet.*;
import javax.servlet.http.*;

public class ResourceServlet extends HttpServlet {

  public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    
      //get web.xml for display by a servlet
      String file = "/WEB-INF/web.xml";
     
      URL url = null;
      URLConnection urlConn = null;  
      PrintWriter out = null;
      BufferedInputStream buf = null;
     try{
     out = response.getWriter();
     url = getServletContext().getResource(file);
     //set response header
      response.setContentType("text/xml");
    
      urlConn = url.openConnection();
     //establish connection with URL presenting web.xml
     urlConn.connect();
     buf = new BufferedInputStream(urlConn.getInputStream());
     int readBytes = 0;

     //read from the file; write to the PrintWriter
     while((readBytes = buf.read()) != -1)
        out.write(readBytes);

     } catch (MalformedURLException mue){
    
           throw new ServletException(mue.getMessage());
           
     } catch (IOException ioe){
     
        throw new ServletException(ioe.getMessage());
         
     } finally {
     
//close the input/output streams
     if(out != null)
         out.close();
      if(buf != null)
          buf.close();
          }
    
    } //end doGet
   
    public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        
        doGet(request,response);
    } 
}
