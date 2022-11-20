<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>

<html>
<head><title>Cookie display</title></head>
<body>
<h2>Here are all the Available Cookies</h2>

<c:forEach var="cookies" items="${cookie}">

    <strong><c:out value=
        "${cookies.key}"/></strong>: Object=<c:out value="${cookies.value}"/>, value=<c:out value="${cookies.value.value}"/><br />
        
</c:forEach>


</body>
</html>