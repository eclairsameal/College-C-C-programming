//�ɦW:ex14.c
//�sĶ��:Dev-c++
//���:2011/12/13
#include<stdio.h>
#include<stdlib.h>
float a(float x,float y,int *sum,float *p){//�禡 
      *sum = x * y;//���
      *p =(x * y)-*sum;//�p��
      }

int main(){
    float x,y,p;
    int sum=0;
    printf("Enter two numbers:");
    scanf("%f%f",&x,&y);
    a( x, y, &sum, &p);
    printf("Integer part of the product:%d\n",sum);//���
    printf("Fraction part of the product:%f\n",p);//�p��
    system("pause");
    }
    
/*
 Write a f unction that passes two floating-point numbers and returns the integer 
 and fraction parts of the product of two numbers. A possible session may look like:

 Enter two numbers: 3.28 2.5
 Integer part of the product : 8
 Fraction part of the product: 0.2

*/ 
