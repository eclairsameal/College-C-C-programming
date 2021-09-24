//�ɦW:ex4.c
//�s�边:Dev-C++
//���:2012/3/15
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct {    //���c 
  char name[30];//�m�W 
  char course[20];//��� 
  unsigned short score;//���� 
} record;

main(){
  int student_number;//���h�־ǥ� 
  int i, len, j, temp ;
  record student[SIZE];
  printf("Enter the number of student:");
  scanf("%d",&student_number);//��J���h�־ǥ� 
  getchar();
  for(i = 0; i < student_number; i++){//��J�ǥ͸�� 
    printf("Enter the name:");
    fgets(student[i].name,30,stdin);
    len = strlen(student[i].name) - 1;//��J�m�W 
    student[i].name[len] = '\0';//���h���� 
    printf("Enter the course:");
    fgets(student[i].course,20,stdin);//��J��� 
    len = strlen(student[i].course) - 1;
    student[i].course[len] = '\0';
    printf("Enter the score:");
    scanf("%d",&student[i].score);//��J���� 
    getchar();	    
  }
  printf("========== List of Grade Records ==================\n");
  for(j = 0; j < student_number; j++){//�C�L�ǥ͸�� 
    printf("%-10s %-10s %-10d\n",
      student[j].name, student[j].course, student[j].score);
  }  
  printf("---------------------------------------------------\n");
  temp = student[0].score;
  for(i = 1; i < student_number; i++ ){//�P�_���Ƴ̰� 
    if(temp < student[i].score)temp = student[i].score;
  }
  printf("Tylor Swift has the heighest point %d\n",temp);//�C�L�̰�����
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
