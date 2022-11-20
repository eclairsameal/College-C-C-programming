<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<html>
<head><title>Request Headers</title></head>
<body>
<h2>Here are the Request Header names and values</h2>

<c:forEach var="req" items="${header}>
    <strong><c:out value="req.key"/></strong>: <c:out value="req.value"/>
</c:forEach>

</body>
</html>