package com.jspservletcookbook;    

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import javax.servlet.jsp.tagext.*;

/** This tag generates a thumbnail image using HTML img tag, next to text message. The user specifies the content of the message and the Heading level (i.e., <H1>-<H2>) */

public class LogoTag extends BodyTagSupport implements TryCatchFinally{

    private String heading = null;
	private String image =null;
    //stamp.gif, 42 x 54
	private String width =null;
	private String height =null;

  public int doStartTag() throws JspException{
  
    //this method assumes that attribute properties have been set.
	try {
    
	int h = new Integer(heading).intValue();
    
	if(! (h > 0 && h < 7))
        throw new JspException("The 'heading' attribute value must between 1 and 6 inclusive.");
        
    } catch (Exception e) { throw new JspException(e.getMessage()); }
  
    return EVAL_BODY_BUFFERED;
  
  }

public int doEndTag() throws JspException {

   JspWriter out = pageContext.getOut();
   String imgDir = ((HttpServletRequest) pageContext.getRequest()).getContextPath() + "/images/";
   String message = getBodyContent().getString().trim();
   try{
   out.println(new StringBuffer("<img src=\"").append(imgDir).append(image).append("\" width=\"").append(width).append("\" height=\"").append(height).append("\" align=\"left\">").append("<H").append(heading).append(">").append(message).append("</H").append(heading).append(">").toString());
    
    } catch (java.io.IOException io) {}

    
   return EVAL_PAGE;
     } 
     
  public void doCatch(Throwable t){
      
      try{
      
      pageContext.getOut().println(t.getMessage()+"<br />");
      
      } catch (java.io.IOException io) {}
  }
  
  public void doFinally(){
  
     //do nothing here, since we don't have any resources open 
     //like database connections
  
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
     public void release(){ 
     
    heading = null;
	image =null;
	width =null;
	height =null;
    
     }
     
   
}
