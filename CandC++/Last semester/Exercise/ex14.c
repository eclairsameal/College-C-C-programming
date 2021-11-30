//檔名:ex14.c
//編譯器:Dev-c++
//日期:2011/12/13
#include<stdio.h>
#include<stdlib.h>
float a(float x,float y,int *sum,float *p){//函式 
      *sum = x * y;//整數
      *p =(x * y)-*sum;//小數
      }

int main(){
    float x,y,p;
    int sum=0;
    printf("Enter two numbers:");
    scanf("%f%f",&x,&y);
    a( x, y, &sum, &p);
    printf("Integer part of the product:%d\n",sum);//整數
    printf("Fraction part of the product:%f\n",p);//小數
    system("pause");
    }
    
/*
 Write a f unction that passes two floating-point numbers and returns the integer 
 and fraction parts of the product of two numbers. A possible session may look like:

 Enter two numbers: 3.28 2.5
 Integer part of the product : 8
 Fraction part of the product: 0.2

*/ 
