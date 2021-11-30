//檔名: ex4.c
//編譯器: Dev-C++
//日期: 2010/10/5
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i=1,n;
    float sum=0;

    printf("Enter n:");
    scanf("%d", &n);
    while (i <= n) {
          
          if (i<= 10){
                sum=1.0/i+sum;
                i = i + 1;
          }
          if (i>10 && i<=100){
                sum=i*i+sum;
                i = i + 1; 
          }
           if (i>100){
                sum=sum+i;
                i = i + 1;
          }
    
}
    
    printf("sum = %f\n", sum);

    system("pause");
    return 0;
}
/*
 Write a program that reads an integer n and calculates the value of
 following series:

 s = 1/1 + 1/2 + 1/3 + 1/4 + .... + 1/n   if n <= 10
     11 * 11 + 12 * 12 + ...... + n * n   if 10 < n <= 100
     101 + 102 + 103 + ... + (n - 1) + n  if n > 100

A possible run may look like:

Enter n: 8
sum = 2.717857
Enter n: 76
sum = 148843.937500
Enter n: 122
sum = 340420.937500
*/ 
