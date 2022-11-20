<%@page contentType="text/html"%>
<%@ include file="/WEB-INF/jspf/taglib-inc.jspf" %>
    <html>
   <c:import url="/header_tag.jspf" context="/dbproj" />

    <body>
    <h2>Welcome to our Portal <c:out value="
        ${param.fname}" />
          <c:out value="${param.lname}" /></h2>
    <jsp:useBean id="dateString" class="java.util.Date"/>
    The time is  <c:out value="${dateString}" />.
    <br /><br />
    </body>
    </html>
 