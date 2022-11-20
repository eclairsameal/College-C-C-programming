<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>

<html>
<head><title>Accessing a Scoped Value</title></head>
<body>
<h2>Here is the value of the Session-Scoped Attribute</h2>

<c:set var="com.jspservletcookbook.SessionObject" value="My object attribute.<br />" scope="session" />

<c:out value="${sessionScope[\"com.jspservletcookbook.SessionObject\"]}" escapeXml="false" />

</body>
</html>