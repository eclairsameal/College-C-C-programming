// ex2.aspx.cs
//   The code behind file for ex2.aspx
//   Includes a function to build an array of ten pseudorandom
//   numbers
          
using System;
using System.Web;
using System.Web.UI;

public class ex2 : Page {
 
// Build a pseudorandom number method

  Random randomGen = new Random();
  protected int [] myArray = new int[10];

// A method to fill the array with pseudorandom numbers

  public void fillArray() { 
    for (int index = 0; index < 10; index++)

// Generate a pseudorandom number in the range of 0 to 100
 
      myArray[index] = randomGen.Next(0, 100);
  }
}
