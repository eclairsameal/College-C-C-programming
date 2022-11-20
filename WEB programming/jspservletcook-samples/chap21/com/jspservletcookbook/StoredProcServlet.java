package com.jspservletcookbook;           

import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Iterator;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.sql.*;

import javax.servlet.*;
import javax.servlet.http.*;

public class StoredProcServlet extends HttpServlet {

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
    
        String eventName = request.getParameter("eName");
        String location = request.getParameter("eLocation");
        String date = request.getParameter("eDate");
        
        List paramList = new ArrayList();
        paramList.add(eventName);
        paramList.add(location);
		paramList.add(date);

		try{
        
        addRaceEvent(paramList);
        
        } catch (SQLException sqle){  throw new ServletException(sqle.getMessage()); }
        
        response.setContentType("text/html");
        java.io.PrintWriter out = response.getWriter();
        out.println("<html><head><title>Add an Event</title></head><body>");
        out.println("<h2>The Event named "+ eventName +" has been added to the database</h2>");
        
        out.println("</body>");
        out.println("</html>");
    
        out.close();
      
     } //doGet
     
  public Connection getConnection(){

    Connection  conn = null;
    
    try{
    
         conn = pool.getConnection();
         
    } catch (SQLException sqle){
    
        throw new ServletException(sqle.getMessage());
    
    } finally {
    
      return conn;
      
      }
    
    }
    
    public void addRaceEvent(List values) throws SQLException{

        if (values == null)
            throw new SQLException("Invalid parameter in addRaceEvent method.");
            
        Connection conn = null;
        
        conn = getConnection();
        
        if (conn == null )
        throw new SQLException("Invalid Connection in addRaceEvent method");
        
        java.util.Iterator it = values.iterator(); 
        
        CallableStatement cs = null;
        
        //Create an instance of the CallableStatement
        cs = conn.prepareCall( "{call addEvent (?,?,?)}" );
    
        for (int i = 1; i <= values.size(); i++)
            cs.setString(i,(String) it.next()); 
        
        //Call the inherited PreparedStatement.executeUpdate() method
        cs.executeUpdate();
        
       // return the connection to the pool
       conn.close();

  }//addRaceEvent


}
