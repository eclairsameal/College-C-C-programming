<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<jsp:useBean id="date" class="java.util.Date" />
<html>
<head><title>A Clock in a JSP</title></head>
<body>
<h2>The time...</h2>
<OBJECT CLASSID="clsid:02BF25D5-8C17-4B23-BC80-D3488ABDDC6B" WIDTH="320"
HEIGHT="256" CODEBASE="http://www.apple.com/qtactivex/qtplugin.cab">
<PARAM name="SRC" VALUE="http://www.parkerriver.com/films/who_bene2.mov">
<PARAM name="AUTOPLAY" VALUE="true">
<PARAM name="CONTROLLER" VALUE="true">
<EMBED SRC="http://www.parkerriver.com/films/who_baba.mov" WIDTH="240" HEIGHT="196" AUTOPLAY="true"
CONTROLLER="true" PLUGINSPAGE="http://www.apple.com/quicktime/download/">
</EMBED>
</OBJECT>
<br /><c:out value="${date}"/>
</body>
</html>