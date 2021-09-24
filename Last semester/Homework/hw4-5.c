//檔名:hw4-5.c
//編譯器:Dev-c++
//日期:2011/12/15
#include <stdio.h>
#include <stdlib.h>

double function(double x) {//x + cos(x) - √x的函式 
  return  x + cos(x)- sqrt(x);
}

main() {
  double a, b, dx, x, i;//X-axis的起始點 終點 間隔  X的值 控制點 
  printf("Enter a, b, dx: ");
  scanf("%lf%lf%lf", &a, &b, &dx);
  printf("                                             Y-axis\n\
      0.0   1.0   2.0   3.0   4.0   5.0   6.0   7.0   8.0   9.0  10.0  11.0  12\n\
X-axis +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+");
  for (x = a; x <= b ; x += dx){//印出X-axis 
    printf("       |\n");
	printf("   %.1f +",x);
    for(i=0;i<=function(x);i+=0.25)printf(" ");//控制點的位置 
    printf("*\n");//印出點 
}
/*  for (x = a; x <= b ; x += dx){
  printf("f(%f) = %f\n", x, function(x));
  }*/ 
  system("pause");
}
/*
Consider the function x + cos(x) - √x. Write a program to draw the function.
  1.Write a function that passes x and return the value of x + cos(x) - √x.
  2.Read a, b, and dx which represent the starting x, ending x, and x-axis interval dx respectively.
  3.Draw the X-axis and Y-axis.
  4.Plot the function.
A possible run may look like:
Enter a, b, dx: 1 7 0.25
                                        Y-axis
      0.0   1.0   2.0   3.0   4.0   5.0   6.0   7.0   8.0   9.0  10.0  11.0  12.0
X-axis +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+                 
       |
  1.0  +  *               
       | *                  
  1.5  + *
       |*                      
  2.0  +*
       |*                     
  2.5  +*                     
       |*                   
  3.0  + *                 
       | *                 
  3.5  +  *  
       |   *  
  4.0  +      *
       |          *
  4.5  +            * 
       |               * 
  5.0  +                 * 
       |                    *
  5.5  +                      *
       |                        *
  6.0  +                          *
       |                           *  
  6.5  +                            * 
       |                             * 
  7.0  +                             *

*/ 

