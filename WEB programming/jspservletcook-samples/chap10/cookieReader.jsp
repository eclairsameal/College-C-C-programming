<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<html>
<body>
<c:choose>
  <c:when test="${empty cookie}" >
  <h2>We did not find any cookies in the request</h2>
  </c:when>
  <c:otherwise>
<h2>The name and value of each found cookie</h2>
<c:forEach var="cookieVal" items="${cookie}">
<strong>Cookie name:</strong> <c:out value="${cookieVal.key}" /><br>
<strong>Cookie value:</strong> <c:out value="${cookieVal.value.value}" /><br><br>
</c:forEach>
</c:otherwise>
</c:choose>

</body>
</html>