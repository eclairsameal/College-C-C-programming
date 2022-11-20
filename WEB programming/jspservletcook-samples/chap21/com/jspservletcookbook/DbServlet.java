package com.jspservletcookbook;           

import java.sql.*;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.sql.*;

import javax.servlet.*;
import javax.servlet.http.*;

public class DbServlet extends HttpServlet {

 DataSource pool;
   
 
    public void init() throws ServletException {
        
         Context env = null;
        
       try{
           
             env = (Context) new InitialContext().lookup("java:comp/env");
             pool  = (DataSource) env.lookup("jdbc/oracle-8i-athletes");
             if (pool == null)
             throw new ServletException("'oracle-8i-athletes' is an unknown DataSource");
             
        } catch (NamingException ne) { 
        
           throw new ServletException(ne);

        }
      

    }

  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
    
        String sql = "select * from athlete";
        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;
        ResultSetMetaData rsm = null;
        
        response.setContentType("text/html");
        java.io.PrintWriter out = response.getWriter();
        out.println("<html><head><title>Typical Database Access</title></head><body>");
        out.println("<h2>Database info</h2>");
        out.println("<table border='1'><tr>");
        
        try{ 
           conn = pool.getConnection();
           stmt = conn.createStatement();
      
           rs = stmt.executeQuery(sql);
           rsm = rs.getMetaData();
          int colCount =  rsm.getColumnCount();
            
           //print column names
           for (int i = 1; i <=colCount; ++i){
                
               out.println("<th>" + rsm.getColumnName(i) + "</th>");
           }
            
            // colCount= colCount -1;
            out.println("</tr>");
          
            while( rs.next()){
                
                out.println("<tr>");
                
                for (int i = 1;  i <=colCount; ++i)
                    out.println("<td>" + rs.getString(i) + "</td>");
                
                  out.println("</tr>");
                }
        } catch (Exception e){
            
           throw new ServletException(e.getMessage());
            
        } finally {
            
            try{
                
                stmt.close();
                conn.close();
                
            } catch (SQLException sqle){ }
            
    }
      out.println("</table></body></html>");
      out.close();
      
     } //doGet

}
