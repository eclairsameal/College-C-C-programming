<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<html>
<head>

<c:import url="/WEB-INF/javascript/functions.js" />

<title>Client Forms</title></head><body>

<h2>Enter Your Name and Email</h2>

<form action="/home/displayHeaders.jsp" name="entryForm" onSubmit="return CheckEmail(this.email.value)">

<table border="0"><tr><td valign="top">
First and last name: </td>  <td valign="top"><input type="text" name="name" size="20"></td></tr>
<tr><td valign="top">
Email: </td>  <td valign="top"><input type="text" name="email" size="20"></td>
<tr><td valign="top"><input type="submit" value="Submit"></td>
</tr></table>

</form>
</body></html>