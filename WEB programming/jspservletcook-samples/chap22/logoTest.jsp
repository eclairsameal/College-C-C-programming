<%@ taglib uri="jspservletcookbook.com.tags" prefix="cbck" %>
<html>
<head><title>Me Casa Su Casa</title></head>
<body>
<% session.setAttribute("imgDir",(request.getContextPath() + "/images/")) %>
<cbck:logo heading="2" image="stamp.gif" width="42" height="54">Thanks for visiting</cbck:logo>

Here's all the other stuff this page contains...
</body>
</html>