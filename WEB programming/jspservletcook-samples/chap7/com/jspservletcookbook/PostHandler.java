package com.jspservletcookbook;

import javax.servlet.*;
import javax.servlet.http.*;
import java.util.Map;
import java.util.Iterator;
import java.util.Map.Entry;

public class PostHandler extends HttpServlet {
  
 public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {
        
/* Use the ServletRequest.getParameter(String name), getParameterMap(), getParameterNames(), or getParameterValues() methods in the servlet's doPost method*/

        String name = request.getParameter("username");
        String depart = request.getParameter("department");
        String email = request.getParameter("email");
        response.setContentType("text/html");
        java.io.PrintWriter out = response.getWriter();
      
        out.println("<html>");
        out.println("<head>");
        out.println("<title>Welcome</title>");  
        out.println("</head>");
        out.println("<body>");
        out.println("<h1>Your Identity</h1>");
        out.println("Your name is: " + ( (name == null ||  name.equals("")) ? "Unknown" : name));
         out.println("<br><br>");
         out.println("Your department is: " + ( (depart == null ||  depart.equals("")) ? "Unknown" : depart));
         out.println("<br><br>");
         out.println("Your email address is: " + ( (email == null ||  email.equals("")) ? "Unknown" : email));
        out.println("<h2>Using ServletRequest.getParameterMap</h2>");
        Map param_map = request.getParameterMap();
        if (param_map == null)
            throw new ServletException(
              "getParameterMap returned null in: " + getClass().getName());

         //iterate through the java.util.Map and display posted parameter values
        //the keys of the Map.Entry objects ae type String; the values are type String[],
        //or String array
        Iterator iterator = param_map.entrySet().iterator();
        while(iterator.hasNext()){
            Map.Entry me = (Map.Entry)iterator.next();
            out.println(me.getKey() + ": ");
            String[] arr = (String[]) me.getValue();
            for(int i=0;i<arr.length;i++){
              out.println(arr[i]);
              //print commas after multiple values, 
              //except for the last one
              if (i > 0 && i != arr.length-1)
                out.println(", ");}//end for
                out.println("<br><br>");
            }//end while

        out.println("</body>");
        out.println("</html>");
        out.close();
  } 
  
  public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, java.io.IOException {

    doPost(request,response);
}
}
