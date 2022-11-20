<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>

<html>
<head><title>Search Amazon.com for a Book</title></head>
<body>

<c:choose>

   <c:when test="${empty param.keyword}">
   
   <h2>Please enter your Amazon search terms...</h2>  

   <%-- Display the HTML form... --%>

   <form method="POST" action =
   '<c:out value="${pageContext.request.contextPath}" />/amazon.jsp'>    

   <%-- form and table tags... --%>
   <table border="0"><tr><td valign="top">    
   Search terms: </td>  <td valign="top">    
   <input type="text" name="keyword" size="15">    
   </td></tr><tr><td valign="top">    
    
   <tr><td valign="top">    

   <input type="submit" value="Submit Info"></td></tr>    
   </table></form>    
   </body></html>    
   
    </c:when>

    <c:otherwise>

    <jsp:useBean id="aBean" class="com.jspservletcookbook.AmazonBean" />

    <jsp:setProperty name="aBean" property="keyword" param="keyword"/>

    <jsp:setProperty name="aBean" property="mode" value="books"/>

    <jsp:setProperty name="aBean" property="page" value="1"/>

    <jsp:setProperty name="aBean" property="type" value="lite"/>

    <jsp:setProperty name="aBean" property="lineSep" value="<br />"/>
    
    <h2>Here are your search results</h2>

	<c:catch var="excep">
    <%-- Now display any results of the search --%>
    <jsp:getProperty name="aBean" property="searchResults" />
		
	</c:catch >
	
	    <c:out value="${excep.message}"/>
    
    </c:otherwise>

</c:choose>

</body>
</html>
