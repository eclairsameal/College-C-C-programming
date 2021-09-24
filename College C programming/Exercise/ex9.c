//檔名:ex9.c 
//編譯器:Dev-C++ 
//日期:100/11/9 
#include<stdio.h>
#include<stdlib.h>
int sum (int n) {
int i, sum = 1;
for (i = 1; i <= n; i++) sum *= i + 1;
return sum;
}


int sumr (int n) {             /*把for (i = 1; i <= n; i++) sum *= i + 1;改成遞回*/ 
  if(n<1) return 1;
  else return (n+1)*sumr(n-1) ;    
}



int sumar(int n) {
  if (n < 1) return 1;
  else return n * sumar(n - 1) - n * n; 
}



int suma (int n) {               /*把遞回改成for*/ 
    int i,s=1;
    for(i=1;i<=n;i++)
    s=s*i-i*i;
    return s;
}

int main(){
int n;
printf("enter n:");
scanf("%d",&n);
printf("sum(%d) = %d\n", n, sum(n));
printf("sumr(%d) = %d\n", n, sumr(n));
printf("suma(%d) = %d\n", n, suma(n));
printf("sumar(%d) = %d\n", n, sumar(n));

system("pause");
}
/*
 1. (4 points) Consider the following function sum. Rewrite it as a recursive 
    function.
    
int sum (int n) {
  int i, sum = 1;
  for (i = 1; i <= n; i++) sum *= i + 1;
  return sum;
}

 2. (4 points) Consider the following recursive function. Rewrite it using 
    iterative (nonrecursive) approach.

int sumar(int n) {
  if (n < 1) return 1;
  else return n * sumar(n - 1) - n * n; 
}

3. (2 points) Write the main function to use the above 2 and the two functions you
   created.


*/ 
