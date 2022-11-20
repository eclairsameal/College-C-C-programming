<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<%@ taglib uri="http://java.sun.com/jstl/fmt" prefix="fmt" %>

<html>
<head><title><fmt:message key="Welcome" /></title></head>
<body>
<h2><fmt:message key="Hello" /> <fmt:message key="and" /> <fmt:message key="Welcome" /></h2>


Locale: <c:out value="${pageContext.request.locale.language}" />_<c:out value="${pageContext.request.locale.country}" /> 

<br /><br />

<fmt:formatNumber value=".51" type="percent" />
      
</body>
</html>