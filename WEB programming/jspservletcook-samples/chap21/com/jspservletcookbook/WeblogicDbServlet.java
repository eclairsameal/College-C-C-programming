package com.jspservletcookbook;       

import java.util.Hashtable;    

import java.sql.*;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.sql.*;

import javax.servlet.*;
import javax.servlet.http.*;

public class WeblogicDbServlet extends HttpServlet {

 DataSource pool;
   
 
  public void init() throws ServletException {
        
       Context env = null;
         
       Hashtable ht = new Hashtable();
       ht.put(Context.INITIAL_CONTEXT_FACTORY,"weblogic.jndi.WLInitialContextFactory");
       //ht.put(Context.PROVIDER_URL,"t3://localhost:7001");
    
      try {
    
         env = new InitialContext(ht);
         pool = (javax.sql.DataSource) env.lookup ("oracle-8i-athletes");
            
        if (pool == null)
            throw new ServletException("'oracle-8i-athletes' is an unknown DataSource");
             
        } catch (NamingException ne) { 
        
           throw new ServletException(ne);

        }
      
   }

  public void doGet(HttpServletRequest request, 
    HttpServletResponse response)
      throws ServletException, java.io.IOException {
    
        String sql = "select * from athlete";
        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;
        ResultSetMetaData rsm = null;
        
        response.setContentType("text/html");
        java.io.PrintWriter out = response.getWriter();
        out.println("<html><head><title>Weblogic Database Access</title></head><body>");
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
