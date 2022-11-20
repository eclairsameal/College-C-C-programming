package com.jspservletcookbook;

import javax.servlet.*;
import javax.servlet.http.*;

import org.apache.commons.httpclient.HttpClient;
import org.apache.commons.httpclient.HttpStatus;
import org.apache.commons.httpclient.methods.PostMethod;
import org.apache.commons.httpclient.NameValuePair;
import org.apache.commons.httpclient.Header;

public class DebugPost extends HttpServlet {
  
 public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
	
	String file = request.getParameter("file");
	
    HttpClient httpClient = new HttpClient();
    PostMethod postMethod = new PostMethod(
        "http://localhost:8080/home/sendpdf");
    NameValuePair[] postData = {
          new NameValuePair("file", file),
        };
	//the 2.0 beta1 version has a PostMethod.setRequestBody(NameValuePair[])
	//method, as addParameters is deprecated
    postMethod.addParameters(postData);
	postMethod.addRequestHeader( new Header("Referer","http://localhost:8080/home/sendpdf?file="+file));
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
    out.close(); 
  } 
  
  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {

    doPost(request,response);
}
}