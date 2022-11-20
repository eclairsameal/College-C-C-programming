package com.jspservletcookbook;           

import javax.servlet.ServletRequest;

import javax.security.auth.login.LoginContext;
import javax.security.auth.login.LoginException;

public class LoginBean {

    private ServletRequest req;
    boolean loginSuccess;
    

  public LoginBean(){ }

  public boolean getLoginSuccess() throws LoginException {
    
      if (req == null)
          throw new IllegalStateException(
          "The ServletRequest cannot be null in getLogin()");
          
      WebCallbackHandler webcallback = new WebCallbackHandler(req);
      
     try{
    
          LoginContext lcontext = new LoginContext("WebLogin",webcallback );
          
          lcontext.login();
          
          return true;
    
      } catch (LoginException lge){
    
         return false;
    
      }

   } //getLoginSuccess
     
     public void setReq(ServletRequest request) {
       
         if (request == null)
             throw new IllegalArgumentException(
               "ServletRequest argument was null in: "+getClass().getName());
			   
		 this.req = request;
		 
	}//setReq

}
