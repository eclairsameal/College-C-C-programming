<!-- ex4.aspx
     An example of an ASP.NET document that creates a textbox, 
      a drop down list, a submit button, and a label. 
     A code-behind file is used to populate the drop down list and
      handle the button clicks. The label is used for the return
      message
      -->     
<%@ Page language="c#"  Inherits = "ex4"  Src = "ex4.aspx.cs" %>

<html>
  <head> <title> Ex4 </title>
  </head>
  <body>
    <form runat = "server">
      Name: <asp:TextBox runat = "server"  id = "name" />
      <br /><br />
      Favorite Color:<asp:DropDownList runat = "server"  
                                       id = "color" />
      <br /><br />
      <asp:button  runat = "server"  id = "submit"
                   text = "Submit"  OnClick = "OnClickHandler" />
      <br /><br />
      <asp:label id = "message"  runat = "server" />
    </form>
  </body>
</html>
