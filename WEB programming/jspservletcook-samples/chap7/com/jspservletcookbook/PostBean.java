package com.jspservletcookbook;

import java.util.Map;
import java.util.Iterator;
import java.util.Map.Entry;

import org.apache.commons.httpclient.HttpClient;
import org.apache.commons.httpclient.HttpStatus;
import org.apache.commons.httpclient.methods.PostMethod;
import org.apache.commons.httpclient.NameValuePair;
import org.apache.commons.httpclient.HttpException;

public class PostBean implements java.io.Serializable {

private Map parameters;
private String url;

public PostBean(){
}

public void setParameters(Map param){

  if (param != null)
      parameters = param;
} 

public Map getParameters(){

    return parameters;
    }
    
public void setUrl(String url){

  if (url != null && !(url.equals("")))
      this.url=url;
} 

public String getUrl(){

    return url;
    }

  
public String getPost() throws java.io.IOException,HttpException{

    if (url == null || url.equals("") || parameters == null)
        throw new IllegalStateException("Invalid url or parameters in PostBean.getPost method.");

    String returnData = "";
    HttpClient httpClient = new HttpClient();
    PostMethod postMethod = new PostMethod(url);
    //convert the Map passed into the bean to a NameValuePair[] type
    NameValuePair[] postData = getParams(parameters);  
    //the 2.0 beta1 version has a
   //PostMethod.setRequestBody(NameValuePair[])
    //method, as addParameters is deprecated
    postMethod.addParameters(postData);
    httpClient.executeMethod(postMethod);
     //A "200 OK" HTTP Status Code
    if (postMethod.getStatusCode() == HttpStatus.SC_OK) {
        returnData= postMethod.getResponseBodyAsString();
    } else {
        returnData= "The POST action raised an error: " + postMethod.getStatusLine();
    }
    //release the connection used by the method
    postMethod.releaseConnection();
    return returnData;
  
}//end getPost

 private NameValuePair[] getParams(Map map){
 
          NameValuePair[] pairs = new NameValuePair[map.size()];
          //Use an Iterator to put name/value pairs from the Map 
            //into the array
          Iterator iter = map.entrySet().iterator();
          int i = 0;
          while (iter.hasNext()){
             
            Map.Entry me = (Map.Entry) iter.next();
             pairs[i] = new NameValuePair(
                       (String)me.getKey(),((String[]) me.getValue())[0]);
            i++;
          }
          return pairs;
 }//end getParams

}
