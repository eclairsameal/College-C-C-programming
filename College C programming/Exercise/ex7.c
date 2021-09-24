//檔名:ex7.c 
//編譯器:Dev-c++
//日期:2010/10/27
#include<stdio.h>
#include<stdlib.h>

double factorial(int n){
       int i;
	   double s=1.0;
       for(i=1;i<=n;i++)s*=i;
       return s;
}
//n!的函數 

int main(){
    int n,x,j;
    double sum=0;
    printf("Enter n,x:");
    scanf("%d%d",&n,&x);

	for(j=1;j<=n;j++){
	sum=sum+pow(-1,j-1)*(pow(x,j)/factorial(j));
		}
    printf("%.20f",sum);

    system("pause");
}


// x/1! - x^2/2! + x^3/3! - ... x^n/n!
// pow(-1,j-1) 控制正負 
// pow(x,j) x + x^2 + x^3 +... x^n

/*
Write a function to pass n and generate the factorial of n. Write the main 
 program to read x and an integer n, call the factorial function and calculate 
 the sum of the following series:

 x/1! - x^2/2! + x^3/3! - ... x^n/n!

 Then write the main fuction to read x and n and call it.

 A possible run may look like:

Enter n, x: 10 1
sum = 0.63212053571428573000
Enter n, x: 20 2
sum = 0.86466471676334988000
Enter n, x: 100 3
sum = 0.95021293163213594000
*/ 
