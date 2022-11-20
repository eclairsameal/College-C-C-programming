<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>

<html>
<head><title>Search Google from a JSP</title></head>
<body>

<c:choose>

   <c:when test="${empty param.query}">

   <h2>Please enter your search terms...</h2>

   <%-- Display the HTML form... --%>
   
   <form method="POST" action ='<c:out value=
  "${pageContext.request.contextPath}" />/google.jsp'>    

<table border="0">

<tr><td valign="top">    

Search terms: </td>  <td valign="top">    
<input type="text" name="query" size="15">    
</td></tr>

<tr><td valign="top">    
Restrict to Google sub-site... </td>  <td valign="top">    
<select name="restrict">
<option selected>none</option><option>unclesam</option>
<option>linux</option>
<option>mac</option><option>bsd</option></select>    
</td></tr>

<tr><td valign="top">    
<input type="submit" value="Submit Info"></td></tr>    
</table></form>    

<%-- End of the HTML form... --%>
   
    </c:when>

	<c:otherwise>
    
    <jsp:useBean id="gBean" class="com.jspservletcookbook.GoogleBean" />

    <h2>Here are your search results</h2>

    <%-- Set the query, restrict, and lineSep properties of the GoogleBean --%>

	<jsp:setProperty name="gBean" property="query" param="query"/>
	<jsp:setProperty name="gBean" property="restrict" param="restrict"/>
	<jsp:setProperty name="gBean" property="lineSep" value="<br /><br />"/>
	
	<%-- Now display any results of the search --%>

	<jsp:getProperty name="gBean" property="searchResults" />
	
	</c:otherwise>
</c:choose>

</body>
</html>
