package com.jspservletcookbook;           

import java.sql.*;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.sql.*;


public class StoredProcUtil {

  private static DataSource pool;
  private static Context env;
  
 static {
 
      try{
           
             env = (Context) new InitialContext().lookup("java:comp/env");
             
             pool  = (DataSource) env.lookup("jdbc/oracle-8i-athletes");
             
             if (pool == null)
                 throw new Exception("'oracle-8i-athletes' is an unknown DataSource");
             
        } catch (Exception e) { 
        
            System.out.println(e);

        }
 
 }//static

    public static void addRaceEvent(String name,String location,String date) {
    
        if( (! check(name)) || (! check(location)) || (! check(date)))
            throw new IllegalArgumentException("Invalid param values passed to addRaceEvent()");
            
        Connection conn = null;
        
        try{
        
        conn = pool.getConnection();
        
        if (conn == null )
           throw new SQLException("Invalid Connection in addRaceEvent method");
        
        CallableStatement cs = null;
        
        //Create an instance of the CallableStatement
        cs = conn.prepareCall( "{call addEvent (?,?,?)}" );
        
        cs.setString(1,name); 
        cs.setString(2,location); 
        cs.setString(3,date); 
        
        //Call the inherited PreparedStatement.executeUpdate() method
        cs.executeUpdate();
        
       // return the connection to the pool
       conn.close();
       
       } catch (SQLException sqle) { }
       

  }//addRaceEvent
  
  private static boolean check(String value){
    
        if(value == null || value.equals(""))
            return false;
            
        return true;
    }


}
