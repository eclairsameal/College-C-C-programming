//檔名:ex6.c
//編輯器:Dev-C++
//日期:2012/3/22
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
typedef struct{
int a, b;
char c;
}Math;

main(){
  FILE *pf;//檔案指標 
  char file_name[SIZE];
  Math m;

  printf("Enter the file name:");
  scanf("%s",file_name);//輸入檔名

  pf = fopen(file_name, "r");//開檔  讀 
  if(pf!=NULL)//判斷檔案是否結束 
  {
    do{
      fscanf(pf,"%d %c %d =",&m.a,&m.c,&m.b);
      switch(m.c)//判斷加減乘除 
      {
        case '+':printf("%d %c %d = %d\n",m.a,m.c,m.b,m.a+m.b); break;//加 
        case '-':printf("%d %c %d = %d\n",m.a,m.c,m.b,m.a-m.b); break;//減 
        case '*':printf("%d %c %d = %d\n",m.a,m.c,m.b,m.a*m.b); break;//乘 
        case '/':printf("%d %c %d = %d\n",m.a,m.c,m.b,m.a/m.b); break;//除 
        case '%':printf("%d %c %d = %d\n",m.a,m.c,m.b,m.a%m.b); break;//餘數 
      }
    }while(!feof(pf));
  }
  else printf("File cannot be opened\n");//開檔錯誤 
  fclose(pf);
  system("pause");
}
/*
 Read a file and calculate the value of an integer mathematical expression.
 You can ingore the precedence of operators. For example, a file 
 math-exp.txt has the following format:

 1 + 2  =
 3 - 8 =
 2 * 4  =
 6 / 5 =
 12 % 5 = 
 ...
 ...

 A possible run may look like:

 Enter the file name: math.txt
 1 + 2  = 3
 3 - 8 = -5
 2 * 4  = 8
 6 / 5 = 1.2
 12 % 5 = 2
 ...
*/ 
