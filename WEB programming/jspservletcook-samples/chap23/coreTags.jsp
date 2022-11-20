<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<html>
<head><title>Using the Core JSTL tags</title></head>
<body>
<h2>Here are the available Time Zone IDs on your system</h2>
<jsp:useBean id="zone" class="com.jspservletcookbook.ZoneWrapper" /> 
<jsp:useBean id="date" class="java.util.Date" /> 

<c:if test="${date.time != 0}" >

    <c:out value="Phew, time has not stopped yet...<br /><br />" escapeXml="false" />

</c:if>

<c:set var="zones" value="${zone.availableIDs}" scope="session" />

    <c:forEach var="id" items="${zones}">

        <c:out value="${id}<br />" escapeXml="false" />


    </c:forEach>

</body>
</html>