<!-- ex3.aspx
     A simple example of an ASP.NET document with HTML controls.
     It uses textboxes to get the name and age of the client,
     which are then displayed.
     -->     
<%@ Page language="c#" %>

<html>
  <head> <title> Ex3 </title>
  </head>
  <body>
    <form runat = "server">
      <p>
        Your name: 
        <input type = "text"  id = "name"  runat = "server" />
        <br />
        Your age:
        <input type = "text"  id = "age"  runat = "server" />
        <br />
        <input type = "submit"  value = "Submit" />
      <br />
      <% if (IsPostBack) { %>
        Hello <%= name.Value %> <br />
        You are <%= age.Value %> years old <br />
        <% } %>
      </p>
    </form>
  </body>
</html>

