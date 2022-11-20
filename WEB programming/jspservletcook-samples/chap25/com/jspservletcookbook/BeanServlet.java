package com.jspservletcookbook;    

import java.io.IOException;  
import java.io.PrintWriter;   

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;  

import javax.servlet.*;
import javax.servlet.http.*;

public class BeanServlet extends HttpServlet {

    private StockPriceBean spbean;

  public void init() throws ServletException {
        
         Context env = null;
        
       try{
           
             env = (Context) new InitialContext().lookup("java:comp/env");
             spbean = (StockPriceBean) env.lookup("bean/pricebean");
             
              //close the InitialContext
             env.close();
             
             if (spbean == null)
             throw new ServletException("bean/pricebean is an unknown JNDI object");
             
        } catch (NamingException ne) { 
        
            try{ env.close();} catch (NamingException nex) { }
            
           throw new ServletException(ne);

        }
      

    }
    
  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    
    //set the MIME type of the response, "text/html"
    response.setContentType("text/html");
    
    //use a PrintWriter send text data to the client who has requested the servlet
    java.io.PrintWriter out = response.getWriter();
    
    //Begin assembling the HTML content
    out.println("<html><head>");
    
    out.println("<title>Stock Price Fetcher</title></head><body>");
    out.println("<h2>Please submit a valid stock symbol</h2>");
   
   //make sure method="post" so that the servlet service method
   //calls doPost in the response to this form submit
    out.println(
        "<form method=\"post\" action =\"" + request.getContextPath() +
            "/namingbean\" >");

    out.println("<table border=\"0\"><tr><td valign=\"top\">");
    out.println("Stock symbol: </td>  <td valign=\"top\">");
    out.println("<input type=\"text\" name=\"symbol\" size=\"10\">");
    out.println("</td></tr><tr><td valign=\"top\">");

    out.println("<input type=\"submit\" value=\"Submit Info\"></td></tr>");
    out.println("</table></form>");
    out.println("</body></html>");
    
    out.close();
     } //end doGet
     
     public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws java.io.IOException{
       
    
    String symbol;//this will hold the stock symbol
    float price = 0f;
    
    symbol = request.getParameter("symbol");
    
    boolean isValid = (symbol == null || symbol.length() < 1) ? false : true;

    //set the MIME type of the response, "text/html"
    response.setContentType("text/html");
    
    //use a PrintWriter send text data to the client who has requested the servlet
    java.io.PrintWriter out = response.getWriter();
    
    //Begin assembling the HTML content
    out.println("<html><head>");
    out.println("<title>Latest stock value</title></head><body>");
    
    if ((! isValid) || spbean == null){
    
        out.println("<h2>Sorry, the stock symbol parameter was either empty or null</h2>");
        
    } else {
    
        out.println("<h2>Here is the latest value of "+ symbol +"</h2>");
        
        
        spbean.setSymbol(symbol);
        price = spbean.getLatestPrice();
        
        
        out.println( (price < 1 ? "The symbol is probably invalid." : ""+price) );
        
    }
    
        
    out.println("</body></html>");
    
    
    
    }// doPost
    
}//BeanServlet
