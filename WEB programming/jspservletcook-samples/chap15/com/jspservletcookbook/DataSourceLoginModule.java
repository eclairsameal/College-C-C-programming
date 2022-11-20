package com.jspservletcookbook;  

import java.util.Map;
import java.sql.*;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;

import javax.security.auth.spi.LoginModule;
import javax.security.auth.*;
import javax.security.auth.callback.*;
import javax.security.auth.login.*;

import javax.sql.*;

public class DataSourceLoginModule implements LoginModule {

    CallbackHandler handler;
    Subject  subject;
    Map      sharedState;
    Map      options;
    private boolean loginPassed = false;

  public DataSourceLoginModule(){}
  
  public void initialize(Subject subject, CallbackHandler handler, Map sharedState, Map options){
  
      this.subject = subject;
      this.handler = handler;
      this.sharedState = sharedState;
      this.options = options;
  
  }
  
  public boolean login() throws LoginException {
  
     String name = "";
     String pass = "";
     
     Context env = null;
     Connection conn = null;
     Statement stmt = null;
     ResultSet rs = null;
     DataSource pool = null;
     
     boolean passed = false;
     
    try{
     
        //Create the CallBack array to pass to the CallbackHandler.handle() method
        Callback[] callbacks = new Callback[2];
    
        callbacks[0] = new NameCallback("Username:");
        
        callbacks[1] = new PasswordCallback("Password:", false);
  
        handler.handle(callbacks);
        
        //Get the user name and password from the CallBacks
        NameCallback nameCall = (NameCallback) callbacks[0];
        
        name = nameCall.getName();

        PasswordCallback passCall = (PasswordCallback) callbacks[1];
        
        pass = new String ( passCall.getPassword() );
    
       //Look up our DataSource so that we can check the user name and
       //password
        env = (Context) new InitialContext().lookup("java:comp/env");
        
        pool  = (DataSource) env.lookup("jdbc/oracle-8i-athletes");
        
        if (pool == null)
             throw new LoginException("Initializing the DataSource failed.");
			 
			 System.out.println("name: "+name);
           
        //The SQL for checking a name and password in a table named 'athlete'
        String sql = "select * from athlete where name='"+name+"'";
        String sqlpass = "select * from athlete where passwrd='"+pass+"'";
           
        //Get a Connection from the connection pool
        conn = pool.getConnection();
        
        stmt = conn.createStatement();
      
         //Check the user name
         rs = stmt.executeQuery(sql);
           
         //If the ResultSet has rows then the user name/passowrd were correct and
         //next() returns true
         passed = rs.next();
         
         rs.close();
           
         if (! passed){
           
             loginPassed = false;
             throw new FailedLoginException(
			   "The user name was not successfully authenticated");
             
          }
           
           //Check the password
          rs = stmt.executeQuery(sqlpass);
            
          passed = rs.next();
            
          if (! passed){
               
              loginPassed = false;
               throw new FailedLoginException(
			   "The password was not successfully authenticated");
                 
           } else {
                 
               loginPassed = true;
               return true;
             
             }
           
       } catch (Exception e){
            
           throw new LoginException(e.getMessage());
            
        } finally {
            
            try{
                
                //close the Statement
                stmt.close();
                
                //Return the Connection to the pool
                conn.close();
                
            } catch (SQLException sqle){ }
         }//finally
  
 }//login
 
 public boolean commit() throws LoginException {
   
       //We're not doing anything special here, since this class represents a simple
       //example of login authentication with JAAS. Just return what login() returned.
       return loginPassed;
  }
  
  public boolean abort() throws LoginException {
      
      //Reset state
      boolean bool = loginPassed;
      loginPassed = false;
      
      return bool;
  }
  
  public boolean logout() throws LoginException {
  
      //Reset state
      loginPassed = false;
      return true;
 
  }

}