<%@ taglib uri="http://java.sun.com/jstl/core" prefix="rt_c" %>

<jsp:useBean id="date" class="java.util.Date" />

<html>
<head><title>Windows Media in a JSP</title></head>
<body>
<h2>Ladies and Gentlemen, The Who</h2>

<OBJECT CLASSID=
    "clsid:22D6f312-B0F6-11D0-94AB-0080C74C7E95"
CODEBASE="http://activex.microsoft.com/activex/controls/mplayer/en/nsmp2inf.cab#version=6,4,7,1112">

<PARAM name="autoStart" VALUE="true">

<PARAM name="URL" VALUE="http://localhost:8080/home/faithhill_yourestillhere_56-v[1].asx">

<!-- <EMBED SRC=
   "http://www.parkerriver.com/films/who_baba.mov" WIDTH="240" HEIGHT="196" 
    AUTOPLAY="true" CONTROLLER=
    "true" PLUGINSPAGE="http://www.apple.com/quicktime/download/">

</EMBED> -->

</OBJECT>

<br /><rt_c:out value="${date}"/>

</body>
</html>
