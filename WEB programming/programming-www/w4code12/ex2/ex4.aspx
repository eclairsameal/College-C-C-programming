<!-- ex4.aspx
     A simple example of an ASP.NET document with a code behind file
     
     -->     
<%@ Page language="c#"  Inherits = "ex4"  Src = "ex4.aspx.cs" %>

<html>
  <head> <title> Ex4 </title>
  </head>
  <body>
    <form runat = "server">
      <asp:DropDownList runat = "server"  id = "color" />
      <asp:TextBox runat = "server"  id = "name" />
      <asp:button  onclick = "SubmitButtonClick"  id = "submit"  
                   runat = "server" />
      <asp:label id = "message"  runat = "server" />
  
  </body>
</html>
