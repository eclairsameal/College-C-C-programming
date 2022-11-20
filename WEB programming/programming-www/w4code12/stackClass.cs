// stackClass.cs - a file containing two class definitions
//  1. A class, StackClass, that implements a stack in an 
//     array of length 100
//  2. A class, TstStack, to test the StackClass

using System;

public class StackClass {
  private int [] stackRef;
  private int maxLen,
              topIndex;

// A constructor for StackClass
  public StackClass() {  
    stackRef = new int [100]; 
    maxLen = 99;
    topIndex = -1;
  }

// The push method
  public void push(int number) {
    if (topIndex == maxLen)
      Console.WriteLine("Error in push—stack is full");
    else stackRef[++topIndex] = number;
  }

// The pop method
  public void pop() {
    if (topIndex == -1)
      Console.WriteLine("Error in pop—stack is empty");
    else --topIndex;
  }

// The top method
  public int top() {return (stackRef[topIndex]);}

// The empty predicate method
  public bool empty() {return (topIndex == -1);}
}

// A class to test StackClass 
public class TstStack {
  public static void Main() {

// Create an instance of StackClass
    StackClass myStack = new StackClass();

// Test push, top, pop, and empty
    myStack.push(42);
    myStack.push(29);
    Console.WriteLine("29 is: " + myStack.top());
    myStack.pop();
    Console.WriteLine("42 is: " + myStack.top());
    myStack.pop();
    myStack.pop();  // Produces an error message
  }
}
