<!-- ex5.aspx
     An example of an ASP.NET document to illustrate server-side
     validation Web controls.
     It uses Web control textboxes to get the name, phone number,
     and age of the client. These three are validated on the 
     server
     1. The name must be present
     2. The phone number must be in the form ddd-ddd-dddd
     3. The range of the age must be 10 to 110
     -->     
<%@ Page language="c#" %>

<html>
  <head> <title> Ex5 </title>
  </head>
  <body>
    <form runat = "server">
      <p>
        Your name: 
        <asp:TextBox  id = "name"  runat = "server" />
        <asp:RequiredFieldValidator
          ControlToValidate = "name"
          Display = "Static"
          runat = "server"
          ErrorMessage = "Please enter your name">
        </asp:RequiredFieldValidator>
        <br />

        Your phone number:
        <asp:TextBox  id = "phone"  runat = "server" />
        <asp:RegularExpressionValidator
          ControlToValidate = "phone"
          Display = "Static"
          runat = "server"
          ErrorMessage = "Phone number form must be ddd-ddd-dddd"
          ValidationExpression = "\d{3}-\d{3}-\d{4}">
        </asp:RegularExpressionValidator>
        <br />

        Your age:
        <asp:TextBox  id = "age"  runat = "server" />
        <asp:RangeValidator
          ControlToValidate = "age"
          Display = "Static"
          runat = "server"
          MaximumValue = "110"
          MinimumValue = "10"
          Type = "Integer"
          ErrorMessage = "Age must be in the range of 10 to 110">
        </asp:RangeValidator>
        <br />
     
        <input type = "submit"  value = "Submit" />
      </p>
    </form>
  </body>
</html>

