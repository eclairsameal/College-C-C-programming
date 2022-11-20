<%@page isErrorPage="true" %>
<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<html>
<head><title>Sorry about the error</title></head>
<body>
<h2>Sorry, We Erred Handling Your Request</h2>
<strong>Here is information about the error:</strong> <br><br>

The servlet name associated with throwing the exception: 
<%-- JSP 2.0 usage only! 
<c:out value="${pageContext.errorData.servletName}" />  --%>
<br><br>
The type of exception: <c:out value=
  "${requestScope[
   \"javax.servlet.jsp.jspException\"].class.name}" />
<br><br>
The request URI:
<%-- JSP 2.0 usage only! 
<c:out value="${pageContext.errorData.requestURI}" />  --%>
<br><br>
The exception message: 
  <c:out value="${pageContext.exception.message}" />
 </body>
</html>

