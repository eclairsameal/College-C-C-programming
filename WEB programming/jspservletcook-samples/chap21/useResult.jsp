<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<%@ taglib uri="http://java.sun.com/jstl/sql" prefix="sql" %>
<html>
<HEAD>
      <TITLE>Using a Result object</TITLE>
     </HEAD>
<body bgcolor="white">
<h2>View Database Data</h2>
<c:set var="resultObj" value="${sessionScope[\"javax.servlet.jsp.jstl.sql.Result\"]}" />

<table border="1" cellspacing="2">
<c:forEach items="${resultObj.rows}" var="row">
  <c:forEach items="${row}" var="column">
    <tr>
     <td align="right">
       <b><c:out value="${column.key}" /></b>
       </td>
       <td>
         <c:out value="${column.value}" />
         </td></tr>
       </c:forEach>
         </c:forEach>
         </table>
</body>
</html>