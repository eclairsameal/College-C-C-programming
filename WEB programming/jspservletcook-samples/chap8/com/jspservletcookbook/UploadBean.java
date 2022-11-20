package com.jspservletcookbook;

import java.util.Enumeration;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.ServletRequest;

import com.oreilly.servlet.MultipartRequest;
import com.oreilly.servlet.multipart.DefaultFileRenamePolicy;

public class UploadBean {
   
    private String webTempPath;
    private HttpServletRequest req;
    private String dir;
    
public UploadBean() {}

  public void setDir(String dirName) {

      if (dirName == null || dirName.equals(""))
        throw new IllegalArgumentException(
           "invalid value passed to " + getClass().getName()+".setDir");

      webTempPath = dirName;

  }

  public void setReq(ServletRequest request) {

      if (request != null && request instanceof HttpServletRequest){

          req = (HttpServletRequest) request;

      } else {
  
          throw new IllegalArgumentException(
            "Invalid value passed to " + getClass().getName()+".setReq");
      }

}
    
  public String getUploadedFiles() throws java.io.IOException{
   
      //file limit size of five megabytes
      MultipartRequest mpr = new MultipartRequest(
        req,webTempPath,5 * 1024 * 1024,new MyFileRenamePolicy());

      Enumeration enum = mpr.getFileNames();

      StringBuffer buff = new StringBuffer("");
        
      for (int i = 1; enum.hasMoreElements();i++){

            buff.append("The name of uploaded file ").append(i).
              append(" is: ").
                append(mpr.getFilesystemName((String)enum.nextElement())).
                  append("<br><br>");
      }//for
        
      //return the String
      return buff.toString();

  } // getUploadedFiles

}
