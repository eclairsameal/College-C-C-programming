package com.jspservletcookbook;           

import org.apache.log4j.Logger;
import org.apache.log4j.PropertyConfigurator;

import java.lang.reflect.Method;

import javax.servlet.jsp.*;
import javax.servlet.jsp.tagext.*;

public class LoggerTag extends BodyTagSupport {

private Logger log = null;
private String configFile = null;
private String level = null;
private final static String[] LEVELS =  { "debug","info","warn","error","fatal"};

public void setConfigFile(String fileName){

this.configFile = fileName;

}

public void setLevel(String level){

this.level = level;

}

public int doEndTag() throws JspException {

  if (configFile != null)
     PropertyConfigurator.configure(pageContext.getServletContext().getRealPath("/") + "WEB-INF/classes/" + configFile);

  level = level.toLowerCase();
  if (! contains(level))
        throw new JspException("The value given for the level attribute is invalid.");

  log = Logger.getLogger(LoggerTag.class);
  String message = getBodyContent().getString().trim();
  Method method = null;

  try{
            
            method = log.getClass().getMethod(level,new Class[]{ Object.class });
            method.invoke(log,new String[]{message});

 } catch (Exception e){}
    
 return EVAL_PAGE;
     } 
     
     public void release(){ 
     
         log = null;
         configFile = null;
         level = null;
     }
     
     private boolean contains(String str){
     
         for (int i = 0; i < LEVELS.length; i++){
         
             if(LEVELS[i].equals(str))
                 return true;
         }
         return false;
     }
   
   
}
