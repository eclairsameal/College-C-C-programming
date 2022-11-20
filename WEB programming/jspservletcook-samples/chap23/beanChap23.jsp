<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>

<jsp:useBean id="emailer" class="com.jspservletcookbook.EmailBean"/>
<jsp:setProperty name="emailer" property="*" />
<html>
<head><title>Bean property display</title></head>
<body>
<h2>Here are the EmailBean properties</h2>

<strong>SMTP host: </strong><c:out value="${emailer.smtpHost}" /><br />
<strong>Email recipient: </strong><c:out value="${emailer.to}" /><br />
<strong>Email sender: </strong><c:out value="${emailer.from}" /><br />
<strong>Email subject: </strong><c:out value="${emailer.subject}" /><br />
<strong>Email content: </strong><c:out value="${emailer.content}" /><br />

</body>
</html>