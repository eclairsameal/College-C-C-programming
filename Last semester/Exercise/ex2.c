//檔名:ex2.c//
//編輯器:Dev-C++//
//日期:2011/9/20//
 
#include <stdio.h>
#include <stdlib.h>
int main( void )
{
float a,b,c,d,e,g;
printf ("Enter the line ax + by = c:");
scanf ("%f%f%f",&a ,&b ,&c);
d=c/a;
e=c/b;
g=(d*e)/2;
printf("%f*%f\2 =%f\n",d,e,g );

system("pause");

return 0;

}
/*
Write a program with a function that passes a line equation and returns the
triangle area formed by the line, x-axis, and y-axis.

A possibe run may look like:

Enter the line ax + by = c: 12 5 60
The triangle area is 30.000000.

Enter the line ax + by = c: 3 4 12
The triangle area is 6.000000.
*/ 
