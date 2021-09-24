//檔名:ex11.c
//編譯器:Dev-c++
//日期:2011/11/22
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a[6],b[2],c;    //A,B座標    A,B長度  A x B
    //輸入 
    printf("Enter the vector A:");
    scanf("%f%f%f",&a[0],&a[1],&a[2]);
    printf("Enter the vector B:");
    scanf("%f%f%f",&a[3],&a[4],&a[5]);
    //印出 
    printf("Vector A:(%.3f,%.3f,%.3f)\n",a[0],a[1],a[2]);
    printf("Vector B:(%.3f,%.3f,%.3f)\n",a[3],a[4],a[5]);
    b[0]=sqrt(a[0]*a[0]+a[1]*a[1]+a[2]*a[2]);   //A長度 
    b[1]=sqrt(a[3]*a[3]+a[4]*a[4]+a[5]*a[5]);   //B長度 
    printf("The length of the vector A is %f\n",b[0]);
    printf("The length of the vector B is %f\n",b[1]);
    //判斷長度 
    if(b[0]==b[1])printf("A is  equal to B\n");   
    else printf("A is not equal to B\n");
    
    printf("A + B = (%.3f, %.3f, %.3f)\n",a[0]+a[3],a[1]+a[4],a[2]+a[5]);//A + B 
    printf("A - B = (%.3f, %.3f, %.3f)\n",a[0]-a[3],a[1]-a[4],a[2]-a[5]);//A - B
    c=a[0]*a[3]+a[1]*a[4]+a[2]*a[5];      // A x B
    printf("A x B = %.3f\n",c);
    
    system("pause"); 
}
/*
In Cartesian coordinates a vector can be represented by the coordinates of
its initial and terminal point. For example, consider the point A is at
(3, 1, 2) and B at (1, 2, 5) a vector from A to B can be represented by
(-2, 1, 3). The examples of addition, substraction and multiplicaton
operatons of two vectors are shown as follows:

(1, 2, 3) + (-2, 0, 4) = (1 - 2, 2 + 0, 3 + 4) = (-1, 2, 7)
(1, 2, 3) - (-2, 0, 4) = (1 + 2, 2 - 0, 3 - 4) = (3, 2, -1)
(1, 2, 3) x (-2, 0, 4) = 1 x -2 + 2 x 0 + 3 x 4 = -2 + 0 + 12 = 10

The length of the vector (1, 2, 3) = sqrt(1^2 + 2^2 + 3^2) = 3.742.

Write a program to compare if two vectors are equal, add, substract, and
multiply two vectors.

Enter the vector A: 1 2 3
Enter the vector B: -2 0 4
Vector A: (1.000, 2.000, 3.000)
Vector B: (-2.000, 0.000, 4.000)
=====================================
The length of the vector A is 3.742.
The length of the vector B is 4.472.
A is not equal to B.
A + B = (-1.000, 2.000, 7.000)
A - B = (3.000, 2.000, -1.000)
A x B = 10.000
*/ 
