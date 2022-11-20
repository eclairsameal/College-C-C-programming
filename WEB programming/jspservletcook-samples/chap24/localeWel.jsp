<%@ taglib uri="http://java.sun.com/jstl/core" prefix="c" %>
<html>
<head><title><fmt:message key="Welcome" bundle="i18n.WelcomeBundle" /></title></head>
<body>
<h2>Here is your Locale info...</h2>

<fmt:message key="Welcome" bundle="i18n.WelcomeBundle" />

<%--  <c:set var="clientLocale" value="${pageContext.request.locale}" />
Locale: <c:out value="${clientLocale.displayName}" />
 <br />
Locale country: <c:out value="${clientLocale.displayCountry}" />
<br />
Locale language: <c:out value="${clientLocale.displayLanguage}" />--%>

</body>
</html>