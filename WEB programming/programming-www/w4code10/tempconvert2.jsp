<!-- tempconvert2.jsp 
     Convert a given temperature in Celsius to Fahrenheit.
     Called by tempconvert2.html
     -->
<%@ page contentType = "text/html" %>
<%@ taglib prefix = "c"  
           uri = "http://java.sun.com/jsp/jstl/core" %>
<html xmlns = "http://www.w3.org/1999/xhtml">
  <head>
    <title> Temperature converter </title>
  </head>
  <body>
    <p>   
      Given temperature in Celsius: 
      <c:out value = "${param.ctemp}" /> 
      <br /> <br />
      Temperature in Fahrenheit: 
      <c:out value = "${(1.8 * param.ctemp) + 32}" /> 
    </p>     
  </body>
</html>