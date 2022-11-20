<%@page contentType="text/html"%>
<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<jsp:useBean id="chk" class="com.jspservletcookbook.ClientValidator" >
<jsp:setProperty name="chk" property="*" />
</jsp:useBean>
<%-- get valid property from ClientValidator bean --%>
<c:set var="isValid" value="${chk.valid}" />
<c:if test="${isValid}">
    <c:set var="email" value="${chk.email}" scope="request" />
	<c:set var="password" value="${chk.password}" scope="request" />
</c:if>
<html>
<head><title>Client Checker</title></head>
<body>
<h2>Welcome</h2>
   
     <strong>Email</strong>: 
    <c:out value="${email}" /><br><br>
	  <strong>Password</strong>: 
    <c:out value="${password}" />

</body>
</html>
