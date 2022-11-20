package com.jspservletcookbook;

 import java.io.File;
 import java.util.Date;
 
import com.oreilly.servlet.multipart.FileRenamePolicy;

public class MyFileRenamePolicy implements FileRenamePolicy {
   
    public File rename(File f){
    
      //Get the parent directory path as in h:/home/user or /home/user
      String parentDir = f.getParent();
      
      //Get file name without its path location, such as 'index.txt'
      String fname = f.getName();
      
      //Get the extension if the file has one
      String fileExt = "";
      int i = -1;
      if(( i = fname.indexOf(".")) != -1){
      
          fileExt = fname.substring(i);
          fname = fname.substring(0,i);
      }
      
      //add the timestamp
      fname = fname + (""+( new Date().getTime() / 1000));
      
      //piece together the file name
      fname = parentDir + System.getProperty("file.separator") + fname + fileExt;
      
      File temp = new File(fname);
		 
	 return temp;
    }

}
