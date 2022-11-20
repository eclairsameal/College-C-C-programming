package com.jspservletcookbook;           

import javax.servlet.*;
import javax.servlet.http.HttpServletRequestWrapper;
import javax.servlet.http.HttpServletRequest;

public class ReqWrapper extends HttpServletRequestWrapper{

 private static final String AMP = "&";
 
 public ReqWrapper(HttpServletRequest request){
     
     super(request);
 }
 
 public String getQueryString(){
 
     String query = null;
     //get the query string from the wrapped request object
     query = ((HttpServletRequest)getRequest()).getQueryString();
     if (query != null)
         return query +AMP+"filter="+getClass().getName();
     else
         return "filter="+getClass().getName();
 
 }
}
