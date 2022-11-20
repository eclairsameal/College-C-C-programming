<%@page contentType="text/html"%><%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<html>
<head><title>Post Data Viewer</title></head>
<body>
<h2>Here is your posted data</h2>
<c:forEach var="map_entry" items="${param}">
    <strong><c:out value="${map_entry.key}" /></strong>: 
	<c:out value="${map_entry.value}" /><br><br>
</c:forEach>
</body>
</html>
