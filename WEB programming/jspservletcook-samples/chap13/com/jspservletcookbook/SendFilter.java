package com.jspservletcookbook;

import java.io.FileInputStream;
import java.io.BufferedInputStream;
import java.io.File;
import java.io.IOException;

import javax.servlet.*;
import javax.servlet.http.*;

public class SendFilter implements Filter {
    
	private final static String PDF_DIR = "h:\\book\\distribute";
    private final static String PDF_CONTENT_TYPE = "application/pdf";
	
    private FilterConfig config;
    
    /** Creates new SessionFilter */
    public SendFilter() {
    }
    
    public void  init(FilterConfig filterConfig)  throws ServletException{
        
        System.out.println("Instance created of "+getClass().getName());
        this.config = filterConfig;
    }
    
    public void  doFilter(ServletRequest request, ServletResponse response, FilterChain chain)
    throws java.io.IOException, ServletException {
        
         //get the file name from the 'file' parameter
	  String fileName = request.getParameter("file");
	  if (fileName == null || fileName.equals(""))
	       throw new ServletException("Invalid or non-existent file parameter in SendPdf component.");
	  
	  if (fileName.indexOf(".pdf") == -1)
	      fileName = fileName + ".pdf";
		  
	  ServletOutputStream stream = null;
	  BufferedInputStream buf = null;
	  HttpServletResponse httpResp = null;
	 try{
	 
	 httpResp = (HttpServletResponse) response;
	 stream = httpResp.getOutputStream();
	 File pdf = new File(PDF_DIR + "/" + fileName);
	 
	  //set response headers
	  httpResp.setContentType(PDF_CONTENT_TYPE);
	  httpResp.addHeader("Content-Disposition","attachment; filename="+fileName );
	  httpResp.setContentLength( (int) pdf.length() );
	  
	 FileInputStream input = new FileInputStream(pdf);
	 buf = new BufferedInputStream(input);
	 int readBytes = 0;
	 //read from the file; write to the ServletOutputStream
	   while((readBytes = buf.read()) != -1)
	       stream.write(readBytes);
		
	 
	 } catch (Exception ioe){
	 
	  //  throw new ServletException(ioe.getMessage());
	  System.out.println(ioe.getMessage());
		 
	 } finally {
	 
	 if (buf != null)
	     buf.close();
     if (stream != null){
	     stream.flush();
		 //stream.close();
		}
	 
	 }//end finally
        chain.doFilter(request,httpResp);
    }
    
    public void destroy(){
        /*called before the Filter instance is removed 
        from service by the web container*/
    }
}
