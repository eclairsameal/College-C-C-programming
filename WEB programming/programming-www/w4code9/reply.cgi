#!/usr/local/bin/perl -w

# reply.cgi
# This CGI program returns a greeting to the client

print "Content-type: text/html \n\n",
      "<?xml version = '1.0'?> \n",
      "<!DOCTYPE html PUBLIC '-//w3c//DTD XHTML 1.1//EN'\n",
      "'http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd'>\n",
      "<html xmlns = 'http://www.w3.org/1999/xhtml'>\n",
      "<head><title> reply.cgi example </title></head>\n",
      "<body>\n",
      "<h1> Greetings from your Web server! </h1>\n",
      "</body></html>";
 