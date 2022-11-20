<?xml version = "1.0"?>
<!-- xslplane2.xsl 
     An XSLT Stylesheet for xslplane.xml using implicit templates 
     -->
<xsl:stylesheet version = "1.0"
                xmlns:xsl = "http://www.w3.org/1999/XSL/Transform"
                xmlns = "http://www.w3.org/1999/xhtml">

<!-- The template for the whole document (the plane element) -->

   <xsl:template match = "plane">
     <html><head><title> Style sheet for xslplane.xml </title>
     </head><body>
     <h2> Airplane Description </h2>
     <span style = "font-style: italic; color: blue;"> Year: 
     </span>
     <xsl:value-of select = "year" /> <br />
     <span style = "font-style: italic; color: blue;"> Make: 
     </span>
     <xsl:value-of select = "make" /> <br />
     <span style = "font-style: italic; color: blue;"> Model: 
     </span> 
     <xsl:value-of select = "model" /> <br />
     <span style = "font-style: italic; color: blue;"> Color: 
     </span> 
     <xsl:value-of select = "color" /> <br />
     </body></html>
   </xsl:template>
</xsl:stylesheet>
