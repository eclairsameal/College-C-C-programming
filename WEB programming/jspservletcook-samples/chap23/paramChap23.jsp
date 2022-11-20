<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>

<html>
<head><title>Accessing a Request Parameter</title></head>
<body>
<h2>Hello
<c:choose>
<c:when test="${empty param.name}">
 Esteemed Visitor
 </c:when>
 <c:otherwise>
 <c:out value="${param.name}" />
 </c:otherwise>
 </c:choose>
</h2>

</body>
</html>