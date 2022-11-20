<%-- use the 'taglib' directive to make the JSTL 1.0 core tags available --%>
<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<%-- use the 'jsp:useBean' standard action to make the Date object available in page scope --%>
<jsp:useBean id="date" class="java.util.Date" />
<html>
<head><title>First JSP</title></head>
<body>
<h2>Here is today's date</h2>
<c:out value="Date: ${date}" />
</body>
</html>