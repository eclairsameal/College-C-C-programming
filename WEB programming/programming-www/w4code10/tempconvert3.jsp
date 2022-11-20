<!-- tempconvert3.jsp 
     Convert a given temperature in Celsius to Fahrenheit
     This is both the request and the response document
     -->
<%@ page contentType = "text/html" %>
<%@ taglib prefix = "c"  
           uri = "http://java.sun.com/jsp/jstl/core" %>
<html xmlns = "http://www.w3.org/1999/xhtml">
  <head>
    <title> Temperature converter </title>
  </head>
  <body>
    
      <c:if test = "${pageContext.request.method != 'POST'}"> 
        <form action = "tempconvert3.jsp"  method = "post" >
          
            Celsius temperature: 
            <input type = "text"  name = "ctemp" /> <br />
            <input type = "submit"  
                   value = "Convert to Fahrenheit" /> 
          
        </form>
      </c:if> 

      <c:if test = "${pageContext.request.method == 'POST'}"> 
        Given temperature in Celsius: 
             <c:out value = "${param.ctemp}" /> 
        <br /> <br />
        Temperature in Fahrenheit: 
             <c:out value = "${(1.8 * param.ctemp) + 32}" /> 
      </c:if> 
     
  </body>
</html>