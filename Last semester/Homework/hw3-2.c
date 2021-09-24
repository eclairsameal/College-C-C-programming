//檔名:hw3-2
//編譯器:Dev-c++
//日期:2011/11/22
#include <stdio.h>
#include <stdlib.h>
//選單函式
int menu() {
    printf("====== Menu ======\n");
    printf("1. Cross\n 2. Diamond\n 3. Exit\n");
    printf("------------------\n");
    return 0;
}

void Cross (int n){     //十字函式
    int i,j,k;
    //上半部
    for(i=1;i<=n;i++)              //有幾行
    {
      for(k=1;k<=n;k++)printf(" ");
      for(j=1;j<=1;j++)printf("*");
      printf("\n");
    }
    //中
    for(i=1;i<=2*n+1;i++)printf("*"); 
    printf("\n");
    //下半部
    for(i=1;i<=n;i++)
	{             //有幾行     
      for(k=1;k<=n;k++)printf(" ");
      for(j=1;j<=1;j++)printf("*");
      printf("\n");
    }

    }

void Diamond (int n){
	int i ,k ;  //上半部
     for(i =0;i<n;i++)  //有幾行
     {
       for(k=1;k<=2*n+1;k++)//一行有幾格
       {
       if(k == n+1-i || k == n+1+i)printf("*");
       else printf(" ");
       }
       printf("\n");
     }//下半部
       
     
      for(i=n;i>=0;i--)//有幾行
     {
       for(k=1;k<=2*n+1;k++)//一行有幾格
       {
       if(k == n+1-i || k == n+1+i)printf("*");
       else printf(" ");
       }
       printf("\n");
     }

}

int main(){        //主函式
    int a,n;       //選項   個數
do{
    menu();
    printf("=>");
    scanf("%d",&a);
    printf("enter n:");
    scanf("%d",&n);

    switch(a){
      case 1: Cross (n);break;    
      case 2: Diamond (n);break;
      default:printf("Bye!\n");
}
 }while (a==1|| a==2);

system("pause");
}

/*
1
1.Write a function that generates a menu with three options: 1. Cross, 2. Diamond, and 3. Exit and returns user's selection.
2.Write a function that passes n and generates a cross as below.
3.Write a function that passes n and generates a hollow diamond shown as below.
4.Write the main function that reads n and uses the above 3 functions.

A possible run may look like:
====== Menu ======
1. Cross
2. Diamond
3. Exit
------------------
=> 1
Enter n: 1
 *
***
 *
====== Menu ======
1. Cross
2. Diamond
3. Exit
------------------
=> 2
Enter n: 2
  *
 * *
*   *
 * *
  *
====== Menu ======
1. Cross
2. Diamond
3. Exit
------------------
=> 1
Enter n: 2
  *
  *
*****
  *
  *
====== Menu ======
1. Cross
2. Diamond
3. Exit
------------------
=> 2
Enter n: 3
   *
  * *
 *   *
*     *
 *   *
  * *
   *
*/ 

