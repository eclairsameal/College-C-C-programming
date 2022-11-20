package com.jspservletcookbook;

import javax.servlet.*;
import javax.servlet.http.HttpServletResponseWrapper;
import javax.servlet.http.HttpServletResponse;

public class ResponseWrapper extends HttpServletResponseWrapper{
 
 public ResponseWrapper(HttpServletResponse response){
     
     super(response);
 }
 
 public String getWebResource(String resourceName){
 
     //Implement a method to return a String representing the output of  a web resource
	 //See recipe 13.5
	 return "resource"; //for the compiler...
	 
 }// getWebResource
}
