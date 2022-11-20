package com.jspservletcookbook;

import org.xml.sax.Attributes;
import org.xml.sax.SAXParseException;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;
import javax.xml.parsers.SAXParserFactory;
import javax.xml.parsers.FactoryConfigurationError;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;

import java.io.IOException;

import javax.servlet.jsp.tagext.PageData;

public class ValidateHandler extends DefaultHandler {

private String fileName = "";

public void startElement(String nameSpaceuri,
        String sname, String qname, Attributes attrs){
           for(int i=0; i<attrs.getLength();i++)
             if("filename".equals(attrs.getLocalName(i)))
              this.fileName=attrs.getValue(i);
}

public String getFilename(PageData page) 
    throws FactoryConfigurationError, ParserConfigurationException, 
      SAXException, IOException {
       try{
              SAXParserFactory factory = SAXParserFactory.newInstance();
              factory.setNamespaceAware(true);
              SAXParser saxparser = factory.newSAXParser();
              saxparser.parse(page.getInputStream(),this);
      } catch (FactoryConfigurationError fe){
              throw fe;
      } catch (ParserConfigurationException pce){
              throw pce;
      } catch( SAXException se){
              throw se;
      } catch( java.io.IOException io){
              throw io;
      } finally {
              return this.fileName; }
 }

public void error(SAXParseException e)
    throws SAXParseException
{
    throw e;
}
}