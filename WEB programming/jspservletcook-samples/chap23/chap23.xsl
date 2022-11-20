<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">

<xsl:output method="html"/>

<xsl:template match="/">
    <html><head><title>List of build.xml targets
    </title></head><body bgcolor="white"><h2>Build.xml targets</h2>
    <xsl:apply-templates />
    </body></html>
</xsl:template>

<xsl:template match="/project">
<dl>
    <xsl:for-each select="./target">
    <dt><b><xsl:value-of select="@name" /></b>&#xA0;</dt>
            <xsl:if test="@depends">
            <dd>depends=<xsl:value-of select="@depends" />&#xA0;</dd></xsl:if>        
    </xsl:for-each><!--end for-each contact -->
</dl>
</xsl:template>

        
<xsl:template match="text()">
    <xsl:value-of select="normalize-space()" />
</xsl:template>
    
    
</xsl:stylesheet>



