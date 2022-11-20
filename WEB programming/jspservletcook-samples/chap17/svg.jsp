<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>

<jsp:useBean id="date" class="java.util.Date" />

<html>
<head><title>SVG in a JSP</title></head>
<body>
<h2>A Scaleable Vector Graphics example</h2>

<embed src=
    "testLogo.svg" width="200" height="200" type=
    "image/svg-xml" pluginspage="http://www.adobe.com/svg/viewer/install/"
>

<br /><c:out value="${date}"/>

</body>
</html>
