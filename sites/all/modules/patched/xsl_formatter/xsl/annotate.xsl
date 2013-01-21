<?xml version="1.0" encoding="ISO-8859-1"?>

<!--

  Pull out annotation markup and convert to span tags that can be made to do popups and stuff
  
-->

<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform" >

   <xsl:output method="html" omit-xml-declaration="yes" indent="no"/>


   <!-- metaphor, etc -->
   <xsl:template match="metaphor|definition">
    <span>
      <xsl:attribute name='class' >anno-<xsl:value-of select="name()" /></xsl:attribute>
			<span class='anno-popup' style='display:none' >
			 <xsl:value-of select="@popup" />
			  <xsl:copy-of select="popup/node()" />
			</span>
	    <span class='anno-text' >
	     <xsl:value-of select="text()" />
	    </span>
    </span>
   </xsl:template>

  <!--  breakify newlines -->
	<xsl:template match="text()" name="insertBreaks">
	  <xsl:param name="pText" select="."/>
	
	  <xsl:choose>
	    <xsl:when test="not(contains($pText, '&#xA;'))">
	      <xsl:copy-of select="$pText"/>
	    </xsl:when>
	    <xsl:otherwise>
	      <xsl:value-of select="substring-before($pText, '&#xA;')"/>
	      <br />
	      <xsl:call-template name="insertBreaks">
	        <xsl:with-param name="pText" select=
	          "substring-after($pText, '&#xA;')"/>
	      </xsl:call-template>
	    </xsl:otherwise>
	  </xsl:choose>
	</xsl:template>
 
  <!-- Fallba -->
  <xsl:template match="@*|node()">
	    <xsl:copy>
	        <xsl:apply-templates select="@*|node()"/>
	    </xsl:copy>
	</xsl:template>


</xsl:stylesheet>
