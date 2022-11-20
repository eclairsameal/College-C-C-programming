<%@ tag body-content="scriptless" description="Writes the HTML code for inserting a logo." %>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<%@ attribute name="heading" required="true" rtexprvalue=
  "true" description="The heading level for the logo."%>

<%@ attribute name="image" required="true" rtexprvalue=
  "true" description="The image name for the logo."%>

<%@ attribute name="width" required="true" rtexprvalue=
  "true" description="The image width for the logo."%>

<%@ attribute name="height" required="true" rtexprvalue=
  "true" description="The image height for the logo."%>
 
<img src="${imgDir}${image}" width=
  "${width}" height="${height}" align="left">

<H${heading}>
  <jsp:doBody/></H${heading}>
