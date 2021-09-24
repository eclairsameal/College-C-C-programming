//檔名:ex4.c
//編輯器:Dev-C++
//日期:2012/3/15
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct {    //結構 
  char name[30];//姓名 
  char course[20];//科目 
  unsigned short score;//分數 
} record;

main(){
  int student_number;//有多少學生 
  int i, len, j, temp ;
  record student[SIZE];
  printf("Enter the number of student:");
  scanf("%d",&student_number);//輸入有多少學生 
  getchar();
  for(i = 0; i < student_number; i++){//輸入學生資料 
    printf("Enter the name:");
    fgets(student[i].name,30,stdin);
    len = strlen(student[i].name) - 1;//輸入姓名 
    student[i].name[len] = '\0';//除去換行 
    printf("Enter the course:");
    fgets(student[i].course,20,stdin);//輸入科目 
    len = strlen(student[i].course) - 1;
    student[i].course[len] = '\0';
    printf("Enter the score:");
    scanf("%d",&student[i].score);//輸入分數 
    getchar();	    
  }
  printf("========== List of Grade Records ==================\n");
  for(j = 0; j < student_number; j++){//列印學生資料 
    printf("%-10s %-10s %-10d\n",
      student[j].name, student[j].course, student[j].score);
  }  
  printf("---------------------------------------------------\n");
  temp = student[0].score;
  for(i = 1; i < student_number; i++ ){//判斷分數最高 
    if(temp < student[i].score)temp = student[i].score;
  }
  printf("Tylor Swift has the heighest point %d\n",temp);//列印最高分數
  system("pause");
}
/*
 A student's grade record can be represented by the following structure:

 typedef struct {
   char name[30];
   char course[20];
   unsigned short score;
 } record;

 Write a program to read a list of student's grade, print them, and
 list the information of the highest score. A possible run may look
 like:

Enter the number of student: 3
Enter the name: Lady Gaga
Enter the course: Calclus
Enter the score: 86
Enter the name: Katy Perry
Enter the course: C++ Programming
Enter the score: 76
Enter the name: Tylor Swift
Enter the course: English
Enter the score: 96
========== List of Grade Records ==================
Lady Gaga     Calculus         86
Katy Perry    C++ Programming  76
Tylor Swift   English          96
---------------------------------------------------
Tylor Swift has the heighest point 96.
*/ 
