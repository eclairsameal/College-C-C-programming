Thanks for visiting 
    <%= request.getParameter("fname") %> 
    <%= request.getParameter("lname") %><br>
Session ID: 
    <% if (request.getSession() != null)  {%>
        <%= request.getSession().getId() %>
    <% } else {%>
        Unknown
    <% } %> <br><br>
<a href="/index.html">Main</a> | <a href="/service.html">Services</a> | 
  <a href="/sitemap.html">Site Map</a> | 
    <a href="/resources.html">Resources</a> | 
      <a href="/contacts.html">Contact Us</a>| 
        <a href="/prns_privacy.html">Privacy</a>
