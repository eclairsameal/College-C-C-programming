<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<html>
<head><title>Authenticating JSP</title></head>
<body>
<h2>Here is your login status...</h2>

<jsp:useBean id="jaasBean" class="com.jspservletcookbook.LoginBean" /> 

<c:set target="${jaasBean}" value="${pageContext.request}" property="${req}"/>

<c:out value="${jaasBean.loginSuccess}" escapeXml="false" />

</body>
</html>