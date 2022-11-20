package com.jspservletcookbook;           

import java.sql.*;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.sql.*;

import javax.servlet.*;
import javax.servlet.http.*;

public class DbServletTrans extends HttpServlet {

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
    
        Connection conn = null;
        Statement stmt = null;
       
        response.setContentType("text/html");
        java.io.PrintWriter out = response.getWriter();
        out.println("<html><head><title>Using transactions</title></head><body>");
        out.println("<h2>These SQL statements are part of a transaction</h2>");
        out.println("CallableStatement.executeUpdate()");
        out.println("<br><br>");
        out.println("Statement.executeUpdate()");
        out.println("<br><br>");
        
        try{ 
        
           conn = pool.getConnection();
           
           out.println("AutoCommit before setAutoCommit(): " + conn.getAutoCommit() + "<br><br>");
           
           out.println("Transaction isolation level: ");
           
           switch(conn.getTransactionIsolation()){
           
               case 0 : out.println("TRANSACTION_NONE<br><br>"); break;
               case 1 : out.println("TRANSACTION_READ_UNCOMMITTED<br><br>"); break;
               case 2 : out.println("TRANSACTION_READ_COMMITTED<br><br>"); break;
               case 4 : out.println("TRANSACTION_REPEATABLE_READ<br><br>"); break;
               case 8 : out.println("TRANSACTION_SERIALIZABLE<br><br>"); break;
               default: out.println("UNKNOWN<br><br>");
           
           
           }
           conn.setAutoCommit(false);
           
           
          CallableStatement cs = null;
        
        //Create an instance of the CallableStatement
        cs = conn.prepareCall( "{call addEvent (?,?,?)}" );
			
		cs.setString(1,"Salisbury Beach 5-Miler");
		cs.setString(2,"Salisbury MA");
		cs.setString(3,"14-Aug-2003");
        
        //Call the inherited PreparedStatement.executeUpdate() method
        cs.executeUpdate();
        
        String sql = "update raceevent set racedate='13-Aug-2003' "+
        "where name='Salisbury Beach 5-Miler'";
        
        int res = 0;
        
        stmt = conn.createStatement();
      
        res = stmt.executeUpdate(sql);
        
        //commit the two SQL statements
        conn.commit();
      
        } catch (Exception e){
            
         try{
          //rollback the transaction in case of a problem
           conn.rollback();
           
          } catch (SQLException sqle){ }
          
           throw new ServletException(e.getMessage());
            
        } finally {
            
            try{
                
                if (stmt != null)
                    stmt.close();
                    
                if (conn != null)
                     conn.close();//this returns the Connection to the Connection pool
                
            } catch (SQLException sqle){ }
            
    }
      out.println("</table></body></html>");
      out.close();
      
     } //doGet

}
