<jsp:useBean id="uploader" class="com.jspservletcookbook.UploadBean" />

<jsp:setProperty name="uploader" property="dir"
    value="<%=application.getInitParameter(\"save-dir\")%>" />

<jsp:setProperty name="uploader" property="req"  value="<%= request %>" />

<html>
<head><title>file uploads</title></head>
<body>
<h2>Here is information about the uploaded files</h2>

<jsp:getProperty name="uploader" property="uploadedFiles" />

</body>
</html>
