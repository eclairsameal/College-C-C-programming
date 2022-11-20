package com.jspservletcookbook;           

import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;


public class ContextObject  {

private Map map;

public ContextObject(){

 map = Collections.synchronizedMap(new HashMap());
}

public void put(Object key, Object value){

 if (key == null || value == null)
   throw new IllegalArgumentException("Invalid parameters passed to ContextObject.put");
   
  map.put(key,value);
}

public Map getMap(){

return map;

}
 
public String getValues(){

 StringBuffer buf = new StringBuffer("");
 Set set = map.keySet();  
  
  synchronized(map) {  
  
      Iterator i = set.iterator(); 
      while (i.hasNext())
          buf.append((String) i.next() + "<br>");
  }
  
  return buf.toString();
 
}

public String toString(){

return getClass().getName() + "[ " + map+ " ]";
}

}