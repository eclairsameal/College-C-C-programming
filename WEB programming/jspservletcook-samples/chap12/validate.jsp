<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<html>
<head>

<c:import url="/WEB-INF/javascript/validate.js" />

<title>Help Page</title></head><body>
<h2>Please submit your information</h2>

<form action ="/home/displayHeaders.jsp" onSubmit=" return validate(this)">

<table border="0"><tr><td valign="top">
Your name: </td>  <td valign="top">
<input type="text" name="username" size="20">
</td></tr><tr><td valign="top">
Your email: </td>  <td valign="top">
<input type="text" name="email" size="20">
</td></tr><tr><td valign="top">
<input type="submit" value="Submit Info"></td></tr>
</table></form>
</body></html>