<%@ taglib prefix="cbck" tagdir="/WEB-INF/tags" %>
<html>
<head><title>Me Casa Su Casa</title></head>
<body>
<% session.setAttribute("imgDir",(request.getContextPath() + "/images/")); %>
<cbck:logo heading="<%=request.getParameter(\"level\") %>" image="stamp.gif" width="42" height="54">Thanks for visiting here and using the tag file</cbck:logo>

Here's all the other stuff this page contains...
</body>
</html>