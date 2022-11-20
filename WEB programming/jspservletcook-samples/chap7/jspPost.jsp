<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<c:set var="mapParams" value="${param}" />
<jsp:useBean id="postBean" class="com.jspservletcookbook.PostBean" >
<jsp:setProperty name="parameters" value="${mapParams}" />
<jsp:setProperty name="url" value="http://localhost:8080/home/viewPost.jsp" />
</jsp:useBean>
<jsp:getProperty id="postBean" property="post"/>

