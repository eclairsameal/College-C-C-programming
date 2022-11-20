<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<%@ taglib uri="http://java.sun.com/jstl/sql" prefix="sql" %>
<html>
<HEAD>
      <TITLE>Using a Transaction with a JSP</TITLE>
     </HEAD>
<body bgcolor="white">
          <h2>View Athlete Data</h2>
  
<sql:transaction>  
    
	<sql:update>
	insert into athlete values(2, 'Rachel Perry','rlpbwp1996','Feb-24-1996','F')
	</sql:update>
	
    <sql:query var="resultObj">
    select * from athlete
    </sql:query>

</sql:transaction>  
<table>
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