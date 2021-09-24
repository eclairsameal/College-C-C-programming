//檔名:ex8.c 
//編譯器:Dev-C++ 
//日期:2010/11/3           
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double function(int n){
int i,x;
float s=0;
for(i=1;i<=n;i++)
s=s+(1.0/i);
return s;
//1/1 + 1/2 + ... + 1/n的函數
}
double function2(int n){
int j,a;
float x=0;
for(j=1;j<=n;j++){
a=rand()%100+1;
printf(" %d ",a);
x+=(1.0/a);
}
//n/(1/x1 + 1/x2 + ... + 1/xn)的函數
return x;
       }

int main(){
int n;
srand(time(NULL));

printf("Enter n:");
scanf("%d",&n);
printf("1/1 + ... + 1/%d=%lf\n",n,function(n));
printf("The random numbers are:");

printf("\nThe harmonic mean is %lf\n",n/function2(n));
system("pause");
return 0;
}





/*
Write the following functions:
1. (3 points) A function that passes n and return 1/1 + 1/2 + ... + 1/n.
2. (6 points) A function that passes n and generates n random integer
numbers between 1 and 100, print the random numbers and show their harmonic
mean.
Hint:
The harmonic mean is defined by the following formula:
n/(1/x1 + 1/x2 + ... + 1/xn) where x1, x2, x3, ..., xn is a set of n numbers.
3. (1 points) Write a main function that reads n and uses the above two functions.

A possible session may look like:

Input n: 10
1/1 + ... + 1/10 = 2.9289682540
The random numbers are:
83 68 2 16 10 91 52 22 6 23
The harmonic mean is 10.255639.
*/
