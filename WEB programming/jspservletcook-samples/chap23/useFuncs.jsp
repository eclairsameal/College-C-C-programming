<%@ taglib uri="http://java.sun.com/jsp/jstl/functions" prefix="fn" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<html>
<head><title>Using the JSTL functions</title></head>
<body>
<h2>Using various JSTL 1.1 functions</h2>

<c:set var="tempStr" value="I am a test String"/>

The length of the test String: ${fn:length(tempStr)}<br />

Does the test String contain "test"? ${fn:contains(tempStr,"test")}<br />

Putting the String into upper case using fn:toUpperCase(): ${fn:toUpperCase(tempStr)}<br />

Splitting the String into a String array using fn:split(), and returning the array length: ${fn:length(fn:split(tempStr," "))}<br />

</body>
</html>