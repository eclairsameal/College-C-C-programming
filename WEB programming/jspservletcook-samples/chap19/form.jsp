<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
<head>
    <title>Personal Information</title>
</head>
<body bgcolor="#ffffff">
<c:if test="${! (empty errorMsg)}">
<font color="red"> <c:out value="${errorMsg}"/> </font>
</c:if>
<h2>Please enter your name and email address</h2>
<table>

<form action="/home/thanks.jsp">
<tr><td valign="top">First name: </td>
<td valign="top"> <input type="text" name="first" size="15" value='<c:out value="${first}" />'></td>
<td valign="top">Middle initial: </td>
<td valign="top"> <input type="text" name="middle" size="2" value='<c:out value="${middle}"/>'></td>
</tr>
<tr>
<td valign="top">Last name: </td>
<td valign="top"> <input type="last" name="last" size="20" value='<c:out value="${last}"/>'></td></tr>
<tr>
<td valign="top">Your email: </td>
<td valign="top"> <input type="text" name="email" size="20" value='<c:out value="${email}"/>'></td></tr>

<tr><td valign="top"><input type="submit" value="Submit"> </td>
<td></td></tr>
</form>
</table>

</body>
</html>
