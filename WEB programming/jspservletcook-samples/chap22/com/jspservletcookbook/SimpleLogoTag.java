package com.jspservletcookbook;    

import java.io.IOException;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import javax.servlet.jsp.tagext.*;

/** This tag generates a thumbnail image using HTML img tag, next to text message. The user specifies the content of the message and the Heading level (i.e., <H1>-<H2>) */

public class SimpleLogoTag extends SimpleTagSupport{

    private String heading = null;
    private String image =null;
    private String width =null;
    private String height =null;

  public void doTag() throws JspException, IOException{
  
  JspContext jspContext = getJspContext();
  
    //this method assumes that attribute properties have been set.
    try {
    
    int h = new Integer(heading).intValue();
    
    if(! (h > 0 && h < 7))
        throw new JspException("The 'heading' attribute value must between 1 and 6 inclusive.");
        
    } catch (Exception e) { throw new JspException(e.getMessage()); }
    
    
    JspWriter out = jspContext.getOut();
    
    String imgDir = (String) jspContext.findAttribute("imgDir");
    
    if (imgDir == null || "".equals(imgDir))
         throw new JspException(
         "No attribute provided specifying the application's image directory.");
    

   
   out.println(new StringBuffer("<img src=\"").append(imgDir).append(image).append("\" width=\"").append(width).append("\" height=\"").append(height).append("\" align=\"left\">").append("<H").append(heading).append(">").toString()); 
getJspBody().invoke(null);
out.println(new StringBuffer("</H").append(heading).append(">").toString());

  
  }

 
  public void setHeading(String level){

    this.heading= level;

  }
  
  public void setImage(String name){

    this.image = name;

  }
  
  public void setWidth(String width){

    this.width = width;

  }
  
  public void setHeight(String height){

    this.height = height;

  }
  
}
