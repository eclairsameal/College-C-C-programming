<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<% response.addHeader("Refresh","10"); %>
<%! long times = 0; %>
<html>
<head><title>Auto Refresh</title></head>
<body>
<h2>You've viewed this featureless page...</h2>
<%= ++times %> times.
</body>
</html>