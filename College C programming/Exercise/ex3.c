//檔名:ex3.c//
//編輯器:Dev-C++//
//日期:2011/9/27//
#include <stdio.h>
#include <stdlib.h>

int main(void){
     float a,b,c,s,area;
    
     printf("Enter three sides of a triangle: ");
     area = scanf("%f%f%f",&a,&b,&c);
     s = (a + b + c)/2;
     area = sqrt(s*(s - a)*(s - b)*(s - c));
     
     if (a+b<=c){printf("此三數不合三角形邊長\n");}
     if (b+c<=a){printf("此三數不合三角形邊長\n");}
     if (a+c<=b){printf("此三數不合三角形邊長\n");}
     else
     printf("The triangle area is %f\n", area);
     
     system("pause");
     return 0; 
}
/*
Write a program to read three sides of a triangle. Decide if they can form
a triangle or not. If so, calcuate the area of the triangle. A possible run
may look like:

Enter three sides of a triangle: 3 4 5
The area of the triangle is 6.0000.

Enter three sides of a triangle: 1 1 2
The triangle cannot be formed.
*/ 
