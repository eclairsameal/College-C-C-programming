<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<c:set var="artist" value="${param.artist}" />
<html>
<head><title>Choose Your Tunes</title></head>
<body>
<h2>You chose music from the artist <c:out value="${artist}" /></h2>
<embed src="ConstantCraving.mp3" width="240" height="160" >
</embed>
</body>
</html>