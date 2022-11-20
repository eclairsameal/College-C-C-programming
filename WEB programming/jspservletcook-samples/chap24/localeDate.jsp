<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<%@ taglib uri="http://java.sun.com/jstl/fmt" prefix="fmt" %>
<jsp:useBean id="date" class="java.util.Date" />

<html>
<head><title><fmt:message key="Welcome" /></title></head>
<body>
<h2><fmt:message key="Hello" /> <fmt:message key="and" /> <fmt:message key="Welcome" /></h2>

<fmt:formatDate value="${date}" type="both" dateStyle="full" timeStyle="short" /> <br />
Locale: <c:out value="${pageContext.request.locale.language}" />_<c:out value="${pageContext.request.locale.country}" /> 
</body>
</html>