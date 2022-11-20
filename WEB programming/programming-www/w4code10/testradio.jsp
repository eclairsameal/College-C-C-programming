<?xml version = "1.0"?>
<!DOCTYPE html PUBLIC "-//w3c//DTD XHTML 1.1//EN"
  "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">

<!-- testradio.jsp 
     Display radio buttons and use JSP to display which is
     pressed when the form is submitted
     -->

<%@ page contentType = "text/html" %>
<%@ taglib prefix = "c"  
           uri = "http://java.sun.com/jsp/jstl/core" %>

<html xmlns = "http://www.w3.org/1999/xhtml">
<head> <title> Test Radio buttons </title>
</head>
<body>
  <form method = "post">
    <p>
      <input type = "radio"  name = "payment"  
             value = "visa"  checked = "checked" /> 
        Visa 
      <input type = "radio"  name = "payment"  
             value = "mc" /> 
        Master Charge 
      <input type = "radio"  name = "payment"  
             value = "discover" /> 
        Discover
      <input type = "radio"  name = "payment"  
             value = "check" /> Check <br/> 
      <input type = "submit"  value = "Submit" />
    </p>
  </form>

<!-- If the form has been submitted, display the payment method -->

  <c:if test = "${pageContext.request.method == 'POST'}">
    You have chosen the following payment method:
    <c:choose>
      <c:when test = "${param.payment == 'visa'}">
        Visa
      </c:when>
      <c:when test = "${param.payment == 'mc'}">
        Master Charge
      </c:when>
      <c:when test = "${param.payment == 'discover'}">
        Discover
      </c:when>
      <c:otherwise>
        Check
      </c:otherwise>
    </c:choose>
  </c:if>
</body>
</html>