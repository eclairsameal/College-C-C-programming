<!-- tempconvert1.jsp 
     A document that collects a Celsius temperature from a
     client and uses a scriptlet to convert it to Fahrenheit
     -->

<html xmlns = "http://www.w3.org/1999/xhtml">
  <head>
    <title> Temperature converter </title>
  </head>
  <body>
    <p>
      <%

// Get the Celsius temperature from the form 

         String strCtemp = request.getParameter("ctemp");
         float ftemp;

// If this is not the first request (there was a form value),
// convert the value to Fahrenheit

         if (strCtemp != null) {  
           ftemp = 1.8f * Integer.parseInt(strCtemp) + 32.0f;
       %>

<!-- Use an expression to display the value of the 
     Fahrenheit temperature -->

     Fahrenheit temperature:

       <%= ftemp %>

<!-- Code for the end of the then clause compound 
     statement -->

       <%
         }  //** end of if (strCtemp != ...
         else {
       %>

<!-- This is the first request, so display the form
     to collect the Celsius temperature -->

       <form action = "tempconvert1.jsp"  method = "get" >
         Celsius temperature: 
         <input type = "text"  name = "ctemp" />
         <input type = "submit" />
       </form>
     </p>

<!-- Code for the end of the else clause compound
     statement -->

     <%
         } //** end of else clause
     %>
  </body>
</html>