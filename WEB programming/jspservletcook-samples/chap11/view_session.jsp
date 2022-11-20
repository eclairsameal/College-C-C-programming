<%@page contentType="text/html"%>
<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<%@ taglib uri="http://java.sun.com/jstl/fmt" prefix="fmt" %>
<html>
<head><title>View Session JSP </title></head>
<body>
<h2>Session Info From A JSP</h2>
The session id: <c:out value="${pageContext.session.id}"/><br><br>
The session creation time as a long value: <c:out value="${pageContext.session.creationTime}"/><br><br>
The last accessed time as a long value: <c:out value="${pageContext.session.lastAccessedTime}"/><br><br>
</body>
</html>
