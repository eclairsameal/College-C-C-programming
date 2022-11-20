<!-- ex2.aspx
     A simple example of an ASP.NET document with a code-behind file
     It has the same functionality as ex1.aspx
     -->     
<%@ Page language="C#"  Inherits = "ex2"  Src = "ex2.aspx.cs" %>

<html>
  <head> <title> Ex2 </title>
  </head>
  <body>
    
<!-- Code to call the fillArray method and display the array

    <% string msg;
       fillArray();
       Response.Write(
          "<br /> <b>The array's contents are: </b><br /><br />");
       for (int index = 0; index < 10; index++) {
         msg = string.Format("The element at {0} is: {1} <br />", 
                              index, myArray[index]);
         Response.Write(msg);
       }
    %>
  </body>
</html>
