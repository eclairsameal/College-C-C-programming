package com.jspservletcookbook;           

import java.sql.*;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.sql.*;

import javax.servlet.jsp.jstl.sql.Result;
import javax.servlet.jsp.jstl.sql.ResultSupport;

import javax.servlet.*;
import javax.servlet.http.*;

public class DbServletResult extends HttpServlet {

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
        
        try{
        
        Result jspResult = select(sql);
        
        HttpSession session = request.getSession();
        
        session.setAttribute("javax.servlet.jsp.jstl.sql.Result",jspResult);
        
        RequestDispatcher dispatcher = request.getRequestDispatcher("/useResult.jsp");
        
        dispatcher.forward(request,response);
        
            } catch (SQLException sqle){ throw new ServletException(sqle.getMessage());}
 
     } //doGet

  public Result select(String sql) throws SQLException{

    if (sql == null || sql.equals(""))
        throw new SQLException("Invalid parameter in select method");
        
    ResultSet rs = null;
    Connection conn = null;
    Result res = null;
    
    conn = pool.getConnection();
    
    if (conn == null )
        throw new SQLException("Invalid Connection in select method");
        
    PreparedStatement stmt = conn.prepareStatement(sql);
    
    rs = stmt.executeQuery();
    
    res=ResultSupport.toResult(rs);
    
    rs.close();
    conn.close();
    return res;

  }
}
