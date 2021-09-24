//檔名: hw-1-5.c
//編譯器: Dev-C++
//日期:2011/10/12
#include <stdio.h>
#include <stdlib.h>
int main(){
    int x1,x2,y1,y2;
    float a,b,c,d,e,area; //x前的數  y前的數  方程式之常數
    
    printf("輸入兩個點:");
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
   
    a = y1 - y2;
    b = x2 - x1;
    c = x1*(y1 - y2)+ y1*(x2 - x1);
    printf("%fx%fy=%f\n",a,b,c);  //方程式
    
    d = c / a;
    printf("和x軸的交點座標(%f,0)\n",d);
    e = c / b;
    printf("和y軸的交點座標(0,%f)\n",e);
    
    area = (d*e)/2;
    printf("方程式.X軸.Y軸形成的三角形的面積為%f",area);  //面積
    
    
    
system("pause");
return 0;
}
/*
Write a program for the line calculation.
1.(2 points) Read the two points.
2.(3 points) Calculate the distance between two points. Hint:
    1.The distance between two points (x1, y1) and (x2, y2) is √(x2 - x1)(x2 - x1) + (y2 - y1)(y2 - y1).
    2.sqrt is a function for square root calculation.
3.(8 points) Calculate the line formed by these two points in the form of ax + by = c.
4.(4 points) Calculate the intersection of the line with x-axis and the intersection of the line with y-axis respectively.
5.(3 points) Calculate the area of the triangle formed by the line, x-axis, and y-axis.
A possible run may look like:

Enter two points: -4 6 8 -3
The line is 3.00x + 4.00y = 12.00
The intersection of the line with x-axis is (4.00, 0.00).
The intersection of the line with y-axis is (0.00, 3.00).
The area of the triangle formed by the line, x-axis, and y-axis is 6.00.
*/ 
