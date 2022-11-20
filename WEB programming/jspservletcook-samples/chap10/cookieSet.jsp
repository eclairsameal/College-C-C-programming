<jsp:useBean id="cookieBean" class="com.jspservletcookbook.CookieBean" />
<jsp:setProperty name="cookieBean" property="name"  value="bakedcookie" />
<jsp:setProperty name="cookieBean" property="maxAge"  value="<%=(365*24*60*60) %>" />
<jsp:setProperty name="cookieBean" property="path"  value="<%= request.getContextPath() %>" />
<jsp:setProperty name="cookieBean" property="cookieHeader"  value="<%= response %>" />
<html>
<head><title>Cookie Maker</title></head>
<body>
<h2>Here is information about the new cookie</h2>
Name: <jsp:getProperty name="cookieBean" property="name" /><br>
Value: <jsp:getProperty name="cookieBean" property="value" /><br>
Path: <jsp:getProperty name="cookieBean" property="path" />
</body>
</html>