<%@ taglib uri="http://java.sun.com/jstl/xml" prefix="x" %>
<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<html>
<head><title>Using the Core XML tags</title></head>
<body>
<h2>Here are the context-params and servlets from the XML file</h2>

<c:import url="http://localhost:8080/home/web.xml" var="webXml" />

<x:parse xml="${webXml}" var="doc" />

<h3>First the context params...</h3>

<x:forEach select="$doc//context-param">

    <x:out select="param-name"/>: <x:out select="param-value"/>

</x:forEach>

<h3>Now the servlet info...</h3>

<x:forEach select="$doc//servlet>

    <x:out select="servlet-name"/><br />
	<x:out select="servlet-class"/><br /><br />

</x:forEach>


</body>
</html>