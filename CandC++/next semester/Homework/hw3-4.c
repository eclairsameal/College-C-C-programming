//檔名:hw3-4.c
//編輯器:Dev-C++
//日期:2012/4/13
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 200

typedef struct {//Students結構 
  char name[SIZE], data[SIZE];//姓名   
  float score[4], average;//分數  個人平均 
}Students;

int op(char filename[SIZE],Students s[SIZE]){
	//開檔 讀字串 跟字串的切割  
  FILE *pf;
  char line[SIZE], *st;
  int j = 0, i = 0;	
  
  pf = fopen(filename, "r");//開檔
  if(pf!=NULL){
    while(fgets(line, SIZE, pf)!= NULL)//開讀檔案 
	{	  
	  strcpy(s[i].data, line);//將字串存進Students結構  
	  st = strtok(line," ");//切割 
	  strcpy(s[i].name, st);
	  
	  while((st = strtok(NULL," ")) !=NULL)
      {
        if(!isdigit(st[0]))strcat(s[i].name, st);
        s[i].score[j] = atof(st);
        j++;
      } 
	  i++;//紀錄人數 
	  j = 0; 	
	}
	return i;  
  }
  else printf("File cannot be opened\n");//開檔錯誤 
  //fclose(pf);  
}

void wrap(Students s[SIZE], int n){//去掉換行 
  int i, len;
  for(i = 0; i < n; i++){
    len = strlen(s[i].data) - 1;
    s[i].data[len] = '\0'; 		
  }
}

double a(Students s[SIZE], int n, double score_average[3]){//計算平均分數 
  int i, j;
  for(i = 0; i < n; i++){//個人平均 
    for(j = 0; j < 4; j++){
	  s[i].average = s[i].average + s[i].score[j];
	}	
  }
  for(i = 0; i < 3; i++){//科目平均 
    for(j = 0; j < n; j++){
	  score_average[i] = score_average[i] + s[j].score[i+1];
	}	
  } 
 return score_average[3]; 
}

void same(Students s[SIZE], int n, int len){//輸入的人 
  int i, j, k = 0, p;
  char studentname[SIZE];
  printf("Enter the student's name:");
  fgets(studentname, SIZE, stdin);//輸入學生 
  len = strlen(studentname) - 1;
  studentname[len] = '\0';//去掉換行 
  for(i = 0; i < n; i++){
    for(j = 0; j < len; j++){
      if(s[i].data[j] == studentname[j])k++;//判斷字母是否相同		
    }
	if(k == len){
	  printf("The score report of %s is:\n",studentname);
	  printf("English  Calculus  C Programming\n");
	  printf("%5.0f%9.0f%13.0f\n",s[i].score[1], s[i].score[2], s[i].score[3]);
	}//如果相同印出輸入學生成績 
	k = 0;
  }	
}

void sort_score(Students s[SIZE], int n) { //排序score
  int i, j, k;
  int h;
  float temp = 0.0;
  for(i = 1; i < 4; i++)
  {  
	for( k = 0; k < n; k++) 
	{
      for( j = k; j < n; j++) 
	  {
        if( s[j].score[i] < s[k].score[i] ) 
		{
          temp = s[j].score[i];
          s[j].score[i] = s[k].score[i];
          s[k].score[i] = temp;
        }
      }
    }		  
  } 	
}

void sort_average(Students s[SIZE], int n){//排序scoreaverage
  int i, j; 
  float temp = 0.0;
	for( i = 0; i < n; i++) 
	{
      for( j = i; j < n; j++) 
	  {
        if( s[j].average < s[i].average ) 
		{
          temp = s[j].average;
          s[j].average = s[i].average;
          s[i].average = temp;
        }
      }
    }	
} 

main(){
  Students s[SIZE];
  char filename[SIZE];
  int i, n, len, j;
  double score_average[3];
  printf("Enternthe file name:");
  scanf("%s",filename);
  getchar();
  n = op(filename, s);
  a(s, n, score_average);//計算平均分數
  wrap(s, n);
   
  same(s, n, len);//輸入的人   
  printf("The number of students is %d\n",n);
  printf("-----------------------------------------------------------\n");
  printf("Student Name                 English  Calculus  C Programming  Average\n");
  for(i = 0; i < n; i++)printf("%s         %f\n",s[i].data, s[i].average/3);
  printf("-----------------------------------------------------------\n\Average     ");
  for(j = 0; j < 3 ; j++)printf("%lf     ",score_average[j]/n);
  sort_score(s, n);//排序score
  printf("\nMaximum     ");
  for(i = 1; i < 4; i++)printf("%lf     ",s[n-1].score[i]);
  printf("\nMinimum     ");
  for(i = 1; i < 4; i++)printf("%lf     ",s[0].score[i]);
  printf("\n");
  sort_average(s, n);//排序scoreaverage
  printf("Celine Dion has highest average score %lf",s[n-1].average/3);
  system("pause");
}
/*
Write a program to read a file of course scores and calculate the statistics of the course. Suppose there are maximum 100 students and three courses: English, Calculus, and C++ Programming. Each score has the value between 0 and 100.
1. Create a structure for a stduent's score report that includes that includes two members: a string to represent the name of a student and an arry to store the scores of each student.
2. Write a function that reads students' names and and the scores of each course and returns the number of students.
3. Write a function that passes a student's name, an array of student's record, and prints her or his score report.
4. Write a function that passes an array of student's record, and prints score report of all students.
5. Write a function that calculates the average, maximum, and minimum scores for each course, the average for each student, and the name and the score of the student who has the highest score.
6. Write the main function to use the above functions.
The file may has the following format where you can suppose the name contains maximum 30 characters::
Sarah McLachlan               75        68          80 Celine Dion                   94        88          96  Lisa Loeb                     88        78          90 Natalie Imbruglia             70        72          86  Alanis Morissette             64        70          88
A possible run may look like:
Enter the file name: grade.dat Enter the student's name: Celine Dion  The number of students is 5.  The score report of Celine Dion is: English  Calculus  C Programming   94        88          96  ----------------------------------------------------------- Student Name       English  Calculus  C Programming  Average Sarah McLachlan    75        68          80         74.33 Celine Dion        94        88          96         92.67 Lisa Loeb          88        78          90         85.33 Natalie Imbruglia  70        72          86         76.00 Alanis Morissette  64        70          88         74.00 ----------------------------------------------------------- Average     78.20     75.20       88.00 Maximum       94        88          96 Minimum       64        68          80 ----------------------------------------------------------- Celine Dion has highest average score 92.67.
*/ 
