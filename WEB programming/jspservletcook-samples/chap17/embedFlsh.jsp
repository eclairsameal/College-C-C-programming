<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>

<jsp:useBean id="date" class="java.util.Date" />

<html>
<head><title>Flash in a JSP</title></head>
<body>
<h2>Enjoy the Flash Movie</h2>

<OBJECT CLASSID=
    "clsid:D27CDB6E-AE6D-11cf-96B8-444553540000" CODEBASE=
    "http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#
     version=6,040,0" width="293" height="423"
>

<PARAM name="movie" VALUE="coolFlashMov.swf">

<PARAM name="quality" VALUE="high">

<PARAM name="bgcolor" VALUE="#FFFFFF">

<EMBED SRC=
   "coolFlashMov.swf" quality="high" width="293" height="423" 
   bgcolor="#FFFFFF" type="application/x-shockwave-flash" PLUGINSPAGE=
   "http://www.macromedia.com/go/getflashplayer"
>

</EMBED>

</OBJECT>

<br /><c:out value="${date}"/>

</body>
</html>

