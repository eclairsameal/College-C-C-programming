<!-- ex1.aspx
     A simple example of an ASP.NET document
     It uses a function to fill an array with pseudorandom numbers,
     which are then displayed
     -->     
<%@ Page language="c#" %>

<html>
  <head> <title> Ex1 </title>

    <script runat = "server">

// Build a pseudorandom number method

      Random randomGen = new Random();
      string msg;
      private int [] myArray = new int[10];

// A method to fill the array with pseudorandom numbers

      public void fillArray() { 
        for (int index = 0; index < 10; index++)

// Generate a pseudorandom number in the range of 0 to 100
 
          myArray[index] = randomGen.Next(0, 100);
      }
    </script>
  </head>
  <body>

<!-- Code to call the fillArray method and display the array

    <% fillArray();
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
