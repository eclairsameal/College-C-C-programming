<%@page contentType="text/html"%>
<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<%@ taglib uri="http://java.sun.com/jstl/fmt" prefix="fmt" %>
<html>
<head><title>View Session JSP </title></head>
<body>
<h2>Session Info From A JSP</h2>
The session id: <c:out value="${pageContext.session.id}"/>
<h3>Session date values formatted as Dates</h3>
<jsp:useBean id="timeValues" class="java.util.Date"/>
<c:set target="${timeValues}" value="${pageContext.session.creationTime}" property="time"/>
The creation time: <fmt:formatDate value="${timeValues}" type="both" dateStyle="medium" /><br><br>
<c:set target="${timeValues}" value="${pageContext.session.lastAccessedTime}" property="time"/>
The last accessed time:  <fmt:formatDate value="${timeValues}" type="both" dateStyle="short" />
<c:out value="${timeValues}"/>
</body>
</html>
