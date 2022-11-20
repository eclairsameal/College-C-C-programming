<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>

<html>
<head><title>Request header display</title></head>
<body>
<h2>Here are all the Request Headers</h2>

<c:forEach var="reqHead" items="${header}">

    <strong><c:out value=
        "${reqHead.key}"/></strong>: <c:out value="${reqHead.value}"/><br />
        
</c:forEach>


</body>
</html>