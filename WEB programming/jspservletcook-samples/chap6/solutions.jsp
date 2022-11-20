<%@page contentType="text/html"%>
<html>
<jsp:include page="/WEB-INF/jspf/header.jsp" />
<body bgcolor="white">
<table width="660" border="0" summary="A two-column table in which resides a 
logo and navigation bar">
      <tr><td valign="top">
            Organization image goes here...<p>
      <u>Main</u>
      </td>
      <td align="right" valign="top">
      Navbar goes here...
      </td></tr><tr><td></td>
      <td valign="top">
      <h2>Thanks for registering at this site</h2> 
     Here is the info you submitted:
	 <c:out value="${request.param.fname}"/> <c:out value="${request.param.lname}"/><br><br>
	 Email: <c:out value="${param.eaddress}"/>
      
      </td></tr><tr><td></td>
	 <td><jsp:include page="/WEB-INF/jspf/footer.jsp" /></td></tr>
</table>
</body>
</html>