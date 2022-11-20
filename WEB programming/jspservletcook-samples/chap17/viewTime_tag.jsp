<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>

<jsp:useBean id="date" class="java.util.Date" />

<html>
<head><title>A Clock in a JSP</title></head>
<body>
<h2>The time...</h2>

<jsp:plugin type="applet" code="Clock.class" codebase=
    "http://localhost:8080/home/applets" jreversion="1.4.1">

<jsp:params>

    <jsp:param name="scriptable" value="false"/>

</jsp:params>

<jsp:fallback>
Sorry, we are unable to start the Java plugin <br />
</jsp:fallback>

</jsp:plugin>

<br /><c:out value="${date}"/>
</body>
</html>
