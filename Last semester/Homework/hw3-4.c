//檔名:hw3-2
//編譯器:Dev-c++
//日期:2011/11/22
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double equation()   //y(x) = x^3 + 2x^2 - 3cos(x)
{
	int i,j;
	double F,FD,x[3]={-2,2,2};                  //y(x),y(x)',根 
		for(i=0;i<3;i++)
		{
		  for(j=0;j<500;j++)
          {
		  F=pow(x[i],3)+2*pow(x[i],2)-3*cos(x[i]);//y(x)
		  FD=3*pow(x[i],2)+4*x[i]+3*sin(x[i]);    //y(x)'
		  x[i]=x[i]-F/FD;
		  }
		  printf("The roots are:%lf\n",x[i]);      
		}

}
double equation1()    //y(x) = ax^3 + bx^2 + cx + d
{
	int i,j,a,b,c,d;         
	double f,fd,x[3]={100000,0,-100000};
	printf("Enter a b c d :");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(i=0;i<3;i++)
		{
		  for(j=1;j<=7800;j++)
		  {
		  f=a*pow(x[i],3)+b*pow(x[i],2)+c*x[i]+d;//y(x)
		  fd=3*a*pow(x[i],2)+2*b*x[i]+c;         //y(x)'
		  x[i]=x[i]-(f/fd);
		  }
		  printf("y(x)= %dx^3 + %dx^2 + %dx + %d",a,b,c,d);
		  printf("The roots are:%lf\n",x[i]);
		}


}




int menu(){      //選單函式
	printf("============== Equation Root Solver ==============\n");
	printf("1. y(x) = x^3 + 2x^2 - 3cos(x)\n");
	printf("2. y(x) = ax^2 + bx + c\n");
	printf("3. Exit\n");
	printf("==================================================\n");
	return 0;
	}

int main(){
	int option;     //選擇方程式
	
 
    do
	{
	  menu();
	  printf("=>");
	  scanf("%d",&option);
	  switch(option){
		case 1:equation();
               break;
			
		case 2:equation1();
				 break;

		case 3:printf("Bye!\n");break;
		default:printf("輸入錯誤\n");

		}

	}while(option==1||option==2);

system("pause");
return 0;
}
/*
The Newton-Raphson method can be used to find the roots of any equation y(x) = 0. In this method, the (i + 1)st approximation, xi + 1, to a root of y(x) = 0 is given in terms of the ith approximation, xi, by the formula xi + 1 = xi - y(xi)/y'(xi) For example, if y(x) = 3x2 + 2x - 2, then y'(x) = 6x + 2, and the roots are found by making a reasonable guess for a first approximation x1 and iterating using the equation xi + 1 = xi - (3xi2 + 2xi - 2)/ (6xi + 2)
1.(4 points) Create a selection menu for the user to solve the following two equations. Your solution should be at least 6-digital precision to the right of the decimal point.
2.(12 points) Using the Newton-Raphson method to find the roots of the equation y(x) = x3 + 2x2 - 3cos(x).
    Hint: http://rechneronline.de/function-graphs/
3.(14 points) y = ax3 + bx2 + cx + d where a, b, c, and d are coefficents.
4.(2 points) Write the main function to use above 3 functions.
A sample run may look like:
============== Equation Root Solver ==============
1. y(x) = x^3 + 2x^2 - 3cos(x)
2. y(x) = ax^2 + bx + c
3. Exit
==================================================
Option => 1
The roots are -1.1803035 and 0.8398034.
============== Equation Root Solver ==============
1. y(x) = x^3 + 2x^2 - 3cos(x)
2. y(x) = ax^3 + bx^2 + cx + d
3. Exit
==================================================
Option => 2
Enter a, b, c: 1 0 -7 6
y(x) = 1.0000x^3 - 7.0000x + 6.0000
The roots are 1.000000, 2.000000, and -3.000000.
============== Equation Root Solver ==============
1. y(x) = x^3 + 2x^2 - 3cos(x)
2. y(x) = ax^3 + bx^2 + cx + d
3. Exit
==================================================
Option => 2
Enter a, b, c: 1 1 -4 -4
The roots are -1.000000, -2.000000, and 2.000000.
*/ 
