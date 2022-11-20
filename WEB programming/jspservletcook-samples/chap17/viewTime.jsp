<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<jsp:useBean id="date" class="java.util.Date" />
<html>
<head><title>A Clock in a JSP</title></head>
<body>
<h2>The time...</h2>
<!--"CONVERTED_APPLET"-->
<!-- HTML CONVERTER -->
<OBJECT 
    classid = "clsid:8AD9C840-044E-11D1-B3E9-00805F499D93"
    codebase = "http://java.sun.com/products/plugin/autodl/jinstall-1_4-windows-i586.cab#Version=1,4,0,0"
    >
    <PARAM NAME = CODE VALUE = "Clock.class" >
    <PARAM NAME = CODEBASE VALUE = "http://localhost:8080/home/applets" >
    <PARAM NAME = "type" VALUE = "application/x-java-applet;version=1.4">
    <PARAM NAME = "scriptable" VALUE = "false">

    <COMMENT>
	<EMBED 
            type = "application/x-java-applet;version=1.4" 
            CODE = "Clock.class"
            JAVA_CODEBASE = "http://localhost:8080/home/applets"  
	    scriptable = false 
	    pluginspage = "http://java.sun.com/products/plugin/index.html#download">
	    <NOEMBED>
            
            </NOEMBED>
	</EMBED>
    </COMMENT>
</OBJECT>

<!--
<APPLET CODE = "Clock.class" JAVA_CODEBASE = "http://localhost:8080/home/applets">


</APPLET>
-->


<!--"END_CONVERTED_APPLET"-->


<br /><c:out value="${date}"/>
</body>
</html>