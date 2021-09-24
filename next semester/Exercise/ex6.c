//�ɦW:ex6.c
//�s�边:Dev-C++
//���:2012/3/22
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
typedef struct{
int a, b;
char c;
}Math;

main(){
  FILE *pf;//�ɮ׫��� 
  char file_name[SIZE];
  Math m;

  printf("Enter the file name:");
  scanf("%s",file_name);//��J�ɦW

  pf = fopen(file_name, "r");//�}��  Ū 
  if(pf!=NULL)//�P�_�ɮ׬O�_���� 
  {
    do{
      fscanf(pf,"%d %c %d =",&m.a,&m.c,&m.b);
      switch(m.c)//�P�_�[��� 
      {
        case '+':printf("%d %c %d = %d\n",m.a,m.c,m.b,m.a+m.b); break;//�[ 
        case '-':printf("%d %c %d = %d\n",m.a,m.c,m.b,m.a-m.b); break;//�� 
        case '*':printf("%d %c %d = %d\n",m.a,m.c,m.b,m.a*m.b); break;//�� 
        case '/':printf("%d %c %d = %d\n",m.a,m.c,m.b,m.a/m.b); break;//�� 
        case '%':printf("%d %c %d = %d\n",m.a,m.c,m.b,m.a%m.b); break;//�l�� 
      }
    }while(!feof(pf));
  }
  else printf("File cannot be opened\n");//�}�ɿ��~ 
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
