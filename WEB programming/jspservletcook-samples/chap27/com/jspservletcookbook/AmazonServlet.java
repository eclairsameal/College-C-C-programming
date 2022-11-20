package com.jspservletcookbook;    

import java.io.IOException;  
import java.io.PrintWriter;     

import javax.servlet.*;
import javax.servlet.http.*;

public class AmazonServlet extends HttpServlet {
    
  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    
    //set the MIME type of the response, "text/html"
    response.setContentType("text/html");
    
    //use a PrintWriter send text data to the client who has requested the servlet
    java.io.PrintWriter out = response.getWriter();
    
    //Begin assembling the HTML content
    out.println("<html><head>");
    
    out.println("<title>Initiate an Amazon Book Search</title></head><body>");
    out.println("<h2>Please enter your Amazon search terms</h2>");
   
   //make sure method="POST" so that the servlet service method
   //calls doPost in the response to this form submit
    out.println(
        "<form method=\"POST\" action =\"" + request.getContextPath() +
            "/amazonservlet\" >");

    out.println("<table border=\"0\"><tr><td valign=\"top\">");
    out.println("Search terms: </td>  <td valign=\"top\">");
    out.println("<input type=\"text\" name=\"query\" size=\"15\">");
    out.println("</td></tr>");
    
    //out.println("<tr><td valign=\"top\">Restrict to Google sub-site... </td>  <td valign=\"top\">");
    //out.println("<select name=\"restrict\"><option selected>none</option><option>unclesam</option><option>linux</option><option>mac</option><option>bsd</option></select></td></tr>");
    out.println("<tr><td valign=\"top\">");

    out.println("<input type=\"submit\" value=\"Submit Info\"></td></tr>");
    out.println("</table></form>");
    out.println("</body></html>");
    
     } //end doGet
     
     public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException,java.io.IOException{
       
    String query = request.getParameter("query");
    //String restrict = request.getParameter("restrict");
    
    boolean isValid = (query == null || query.length() < 1) ? false : true;

    //set the MIME type of the response, "text/html"
    response.setContentType("text/html");
    
    //use a PrintWriter send text data to the client who has requested the servlet
    java.io.PrintWriter out = response.getWriter();
    
    //Begin assembling the HTML content
    out.println("<html><head>");
    out.println("<title>Amazon book results</title></head><body>");
    
    if (! isValid){
        out.println("<h2>Sorry, the query parameter was either empty or null</h2>");
    } else {
    
        AmazonBean amBean = new AmazonBean();
        amBean.setKeyword(query);
	   amBean.setType("heavy");
	   amBean.setMode("books");
	   amBean.setPage("1");
      
        amBean.setLineSep("<br />");
    
        out.println("<h2>Here are your search results</h2>");
        
        
        
        
        try {
        
         out.println( amBean.getSearchResults() );
        
        } catch (Exception e){
        
            
			out.println(
            "The search terms either returned zero results "+
            "or were invalid.");

        
        }
        
        
    }
    
        
    out.println("</body></html>");
    
    
    }// doPost
    
}//HttpServlet
