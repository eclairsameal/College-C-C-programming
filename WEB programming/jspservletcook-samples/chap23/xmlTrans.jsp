<%@ taglib uri="http://java.sun.com/jstl/xml" prefix="x" %>
<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>

<c:import url="http://localhost:8080/home/build.xml" var="buildXml" />
<c:import url="/WEB-INF/xslt/chap23.xsl" var="xslt" />
<x:transform xml="${buildXml}" xslt="${xslt}" />
