<%@page contentType="text/html"%>
<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<jsp:useBean id="userB" class="com.jspservletcookbook.UserBean" >
    <jsp:setProperty name="userB" property="*" />
</jsp:useBean>
<html>
<head><title>Post Data Viewer</title></head>
<body>
<h2>Here is your posted data</h2>

    <strong>User name</strong>: 
	<c:out value="${userB.username}" /><br><br>
	 <strong>Department</strong>: 
	<c:out value="${userB.department}" /><br><br>
	 <strong>Email</strong>: 
	<c:out value="${userB.email}" />

</body>
</html>
