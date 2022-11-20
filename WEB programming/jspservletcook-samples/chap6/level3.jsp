<%@page errorPage="/error"%>
<h3>Hello from Level 3</h3>
This text is included at Level 3.
<jsp:include page="/level4"/>
<% throw new javax.servlet.ServletException(); %>