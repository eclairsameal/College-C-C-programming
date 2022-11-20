<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<html>
<head><title>Jndi Bean</title></head>
<body>
<h2>Getting a StockPriceBean object via JNDI...</h2>

<c:set var="priceBean" value="${MyBean}"/>

<c:set target="${priceBean}" property="symbol" value="${param.symbol}"/>

The latest price: <c:out value="${priceBean.latestPrice}" />


</body>
</html>