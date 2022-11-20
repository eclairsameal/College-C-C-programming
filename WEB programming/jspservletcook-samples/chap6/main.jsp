<%@page contentType="text/html"%>
<%@ include file="/WEB-INF/jspf/taglib-inc.jspf" %>

<html>
<head>
<title>Main Content</title>
</head>
<body>
<h1>Here is the main content</h1>
This web application is using the following Servlet API: 
    <c:out value="${pageContext.servletContext.majorVersion}"/>.
	<c:out value="${pageContext.servletContext.minorVersion}"/><br><br>

    <jsp:useBean id="timeValues" class="java.util.Date"/>
    <c:set target="${timeValues}" value="${pageContext.session.creationTime}" 
           property="time"/>
    The session creation time: <fmt:formatDate value="${timeValues}" type="both" 
           dateStyle="medium" /><br><br>
    Hello, this page is using the toxml tag to look at its XML View.
<t:toXml filename="include-xmlview"/>
</body>
</html>


