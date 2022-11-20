<?xml version = "1.0" encoding = "utf-8"?>
<!-- xslplane1.xsl 
     An XSLT stylesheet for xslplane.xml using child templates
     -->
<xsl:stylesheet version = "1.0"
                xmlns:xsl = "http://www.w3.org/1999/XSL/Transform"
                xmlns = "http://www.w3.org/1999/xhtml">

<!-- The template for the whole document (the plane element) -->

   <xsl:template match = "plane">
     <html><head><title> Style sheet for xslplane.xml </title>
     </head><body>
     <h2> Airplane Description </h2>

<!-- Apply the matching templates to the elements in plane -->

     <xsl:apply-templates />
     </body></html>
   </xsl:template>

<!-- The templates to be applied (by apply-templates) to the
     elements in the plane element -->

   <xsl:template match = "year">
     <span style = "font-style: italic; color: blue;"> Year: 
     </span>
     <xsl:value-of select = "." /> <br />
   </xsl:template>
   <xsl:template match = "make">
     <span style = "font-style: italic; color: blue;"> Make: 
     </span>
     <xsl:value-of select = "." /> <br />
   </xsl:template>
   <xsl:template match = "model">
     <span style = "font-style: italic; color: blue;"> Model: 
     </span>
     <xsl:value-of select = "." /> <br />
   </xsl:template>
   <xsl:template match = "color">
     <span style = "font-style: italic; color: blue;"> Color: 
     </span>
     <xsl:value-of select = "." /> <br />
   </xsl:template>
</xsl:stylesheet>


