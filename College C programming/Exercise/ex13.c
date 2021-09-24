//檔名:ex13.c
//編譯器:Dev-c++
//日期:2011/12/08
#include <stdio.h>
#include <stdlib.h>
int suma(int n) {//遞迴轉非遞迴 
    if (n < 2) return 1;
    else return suma(n - 1) + suma(n - 2) + n;
  }
int sumar(int n) {//1 1 4 8 16 29 51 87 146 242 398
    int i,sum=0,a=1,b=1;// 值 前前項 前項 
    for(i = 2; i <= n; i++){
    sum=a+b+i;
    a=b;
    b=sum;}
	return sum;
  } 
int sumb(int n) {//非遞迴轉遞迴
    int i, sum = 0;
    for (i = 1; i <= n; i++) sum += i * i - i;
    return sum;
  }
int sumbr(int n) {//0 2 8 20 40 70 112 168 240 330
    if (n < 1) return 0;
    else return sumbr(n - 1) + n * n - n;
  }

main(){
     int n;
     printf("Enter n:");
     scanf("%d", &n);
     printf("%d\n", suma(n));
     printf("%d\n", sumar(n));
     printf("%d\n", sumb(n));
     printf("%d\n", sumbr(n));
     system("pause");
}
/*
 1. (5 points) Consider following recursive function and rewrite it as a
    non-recursive function.

    int sumar(int n) {
      if (n < 2) return 1;
      else return sumar(n - 1) + sumar(n - 2) + n;
    }

 2. (4 points) Consider following non-recursive function and rewrite it as a
    recursive function.

    int sum(int n) {
      int i, sum = 0;
      for (i = 1; i <= n; i++) sum += i * i - i;
      return sum;
    }
 3. (1 points) Write the main function to use the above two functions.

A possible run may look:

Enter n: 10
sumar(10) = 398 // recursive
suma(10) = 398  // non-recursive
sumb(10) = 330  // non-recursive
sumbr(10) = 330 // recursive
*/ 
