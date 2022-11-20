<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<jsp:useBean id="priceFetcher" class="com.jspservletcookbook.StockPriceBean" />
<html>
<head><title>Price Fetch</title></head>
<body>
<c:choose>
    <c:when test="${empty param.symbol}">
   <h2>Please submit a valid stock symbol</h2>
   <form method="POST" action ='<c:out value="${pageContext.request.contextPath}" />/priceFetch.jsp'>
   <table border="0"><tr><td valign="top">

   Stock symbol: </td>  <td valign="top"><input type="text" name="symbol" size="10"></td></tr><tr><td valign="top"><input type="submit" value="Submit Info"></td></tr></table></form>
   </c:when>
   <c:otherwise>
   <h2>Here is the latest value of <c:out value="${param.symbol}" /></h2>
       <jsp:setProperty name="priceFetcher" property="symbol" value="<%= request.getParameter(\"symbol\") %>" />
       <jsp:getProperty name="priceFetcher" property="latestPrice"/>
   </c:otherwise>
 </c:choose> 

</body>
</html>