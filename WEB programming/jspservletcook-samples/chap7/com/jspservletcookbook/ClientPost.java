package com.jspservletcookbook;

import javax.servlet.*;
import javax.servlet.http.*;

import org.apache.commons.httpclient.HttpClient;
import org.apache.commons.httpclient.HttpStatus;
import org.apache.commons.httpclient.methods.PostMethod;
import org.apache.commons.httpclient.NameValuePair;

public class ClientPost extends HttpServlet {
  
 public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
	
    HttpClient httpClient = new HttpClient();
    PostMethod postMethod = new PostMethod(
        "http://localhost:8080/home/viewPost.jsp");
    NameValuePair[] postData = {
          new NameValuePair("username", "devgal"),
          new NameValuePair("department", "development"),
          new NameValuePair("email", "devgal@yahoo.com")
        };
	//the 2.0 beta1 version has a PostMethod.setRequestBody(NameValuePair[])
	//method, as addParameters is deprecated
    postMethod.addParameters(postData);
    httpClient.executeMethod(postMethod);
    //display the response to the POST method
    response.setContentType("text/html");
     java.io.PrintWriter out = response.getWriter();
     //A "200 OK" HTTP Status Code
    if (postMethod.getStatusCode() == HttpStatus.SC_OK) {
        out.println(postMethod.getResponseBodyAsString());
    } else {
        out.println("The POST action raised an error: " + postMethod.getStatusLine());
    }
	//release the connection used by the method
    postMethod.releaseConnection();
    
  } 
  
  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {

    doPost(request,response);
}
}