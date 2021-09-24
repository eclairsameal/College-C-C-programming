//檔名:ex12.c
//編譯器:Dev-c++
//日期:2011/12/01
#include <stdio.h>
#include <stdlib.h>

int function(int n,int a[50][50])//產生陣列的函式(讀入n和陣列)
    {
    int i,j,sum=0;//行,列,值

    for(i=0;i<n;i++)//行
    {
        for(j=0;j<n;j++)//列
		{
        sum=sum+n;
        a[i][j]=sum;
        printf("%4d",a[i][j]);
        }
    printf("\n");
    }

    }
int main(){
    int n,c,d,a[50][50];  //c , d = row , col
    printf("enter n:");
    scanf("%d",&n);
    function(n,a);//產生陣列的函式
    printf("Enter row #, col #: ");
    scanf("%d%d",&c,&d);

    
    if(c < n || d < n){

	printf("%d",a[c][d]);
	}
	else{printf(" ? ");}

    
    system("pause");
}

/*
Write a program to read n and generate a two dimensional array of n by n and
fill the numbers and query the array in the following way:

Enter n: 2
2  4
6  8
Enter row #, col #: 2 1
?

Enter n: 3
 3  6  9
12 15 18
21 24 27
Enter row #, col #: 1 2
18

Enter n: 4
 4   8  12  16
20  24  28  32
36  40  44  48
52  56  60  64
Enter row #, col #: 3 2
60
*/
