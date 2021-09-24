//檔名: ex5.c
//編譯器: Dev-C++
//日期:2011/10/12
#include<stdio.h>
#include<stdlib.h>

int main(){
    int a, r, n, i = 1, k = 1,sum = 0, q;
    printf("Enter a, r, n: ");
    scanf("%d%d%d", &a, &r, &n);
    sum=a;
    q=r;
    while (i <= n) {

          sum = sum + a*q*k;
          q*= r;
          k = k*(-1);                          //正負
          i++;
          
          }
    printf("The sum is %d",sum);
          
          
    system("pause");
    return 0;    
}
//  a + ar - ar^2 + ar^3 - ar^4 + ar^5 - ....  ar^n.

/*
 Read the initial term, a, ratio, r, and the final vaule of power, n, and 
 calculate the sum of the geometric series: a + ar - ar^2 + ar^3 - ar^4 + ar^5 - ....  ar^n.
 A possible run may look like:

 Enter a, r, n: 1 3 5
 The sum is 184.

 Enter a, r, n: 2 3 6
 The sum is -1090.
*/ 
