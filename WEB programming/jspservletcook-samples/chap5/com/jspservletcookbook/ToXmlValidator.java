package com.jspservletcookbook;

import javax.servlet.jsp.tagext.TagLibraryValidator;
import javax.servlet.jsp.tagext.ValidationMessage;
import javax.servlet.jsp.tagext.PageData;
import java.io.*;
import java.util.ResourceBundle;
import java.util.MissingResourceException;
import java.util.Date;

public class ToXmlValidator extends TagLibraryValidator {

    /** Creates new ToXmlValidator */
    public ToXmlValidator() {
    }
    
    public ValidationMessage[] validate(java.lang.String prefix,
      java.lang.String uri,PageData page){
        
        ValidationMessage[] vam = null;
       try{

       ResourceBundle bundle = 
          ResourceBundle.getBundle("com.jspservletcookbook.validator");
       String directory = bundle.getString("directory");
       String fileName = getFilename(page);

       //throw an Exception if the directory is invalid
       if (directory == null)
         throw new Exception(
           "Received a null directory for the XML view file.");
       //throw an Exception if the file name is invalid	   
       if (fileName == null)
          throw new IOException(
            "Received a null filename for the XML view file.");
       File file = new File(directory + "/" + fileName + ".xml");
       FileWriter writer = new FileWriter(file);
       BufferedReader in = new BufferedReader(
         new InputStreamReader(page.getInputStream()));
        String line = "";
        //write the XML view to the specified file
        while ((line = in.readLine()) != null ){
            writer.write(line);
         }
        
        in.close();
        writer.close();
        
        } catch (IOException io){
        
            //return a validation message
            ValidationMessage vmsg = new 
              ValidationMessage(null,io.getMessage());
            vam = new ValidationMessage[1];
            vam[0] = vmsg;
            return vam;
            
        } catch (MissingResourceException mre){
            //return a validation message
            ValidationMessage vmsg = new
              ValidationMessage(null,mre.getMessage());
            vam = new ValidationMessage[1];
            vam[0] = vmsg;
            return vam;
        } catch (Exception e){
            //return a validation message
            ValidationMessage vmsg = new 
              ValidationMessage(null,e.getMessage());
            vam = new ValidationMessage[1];
            vam[0] = vmsg;
            return vam;
        }
 
        //return empty array
         vam = new ValidationMessage[0];
        return vam;
    }

    private String getFilename(PageData page) throws Exception {
        try{
          ValidateHandler handler = new ValidateHandler();
          return handler.getFilename(page);
          } catch (Exception e){
           throw e; }
          }
}
