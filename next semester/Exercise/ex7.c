//檔名:ex7.c
//編輯器:Dev-C++
//日期:2012/4/2
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define SIZE 100

main(){
  FILE *fp;//檔案指標
  char file_name[SIZE], str[SIZE];
  char *pch;
  int a[SIZE], i = 0, temp = 0, j = 0, k = 0; 
  float average = 0;
  
  printf("Enter the file name:");
  scanf("%s",&file_name);//輸入檔名
  
  fp = fopen(file_name,"r");//開檔  讀 
  if(fp!=NULL)
    {
      while(fgets(str, SIZE, fp)!= NULL)
      {
        pch = strtok (str," :");//字串的切割 
        while (pch != NULL){
         // printf ("%s\n",pch);
          a[i++]=atoi(pch);//切割後存放在陣列a 用i紀錄有多少個 
          pch = strtok(NULL," :");
        }
      }
      for( k = 0; k < i; k++) //排序 
	  {
        for( j = k; j < i; j++) 
		{
          if( a[j] < a[k] ) 
		  {
            temp = a[j];
            a[j] = a[k];
            a[k] = temp;
          }
        }
      }
    printf("The numbers after sorting are:\n");
    for( k = 0; k < i; k++ ) 
	{
      printf("%d ", a[k]);//印出排序結果 
    }
    printf("\nThe maximum value is %d\n",a[i-1]);//印出最大值 
	printf("The minimum value is %d\n",a[0]);//印出最小值 
	for( k = 0; k < i; k++ ) 
	{
      average=+a[k];//將陣列加總 
    }
    printf("The average is %f",average/i); //印出平均      
    }	
  else printf("File cannot be opened\n");//開檔錯誤 
  fclose(fp);
  system("pause");
}

/*char str[] ="- This, a sample string.";
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ,.-");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ,.-");
  }*/
/*B02102A - C++ Programming In-Class Exercise 7 Name: ________________

 Assigned: Thursday, March 23
 Due: Monday, April 2

 o Put your student number and name and add necessary comments into the code 
   you created. These are a part of grading in the assignment.

 o Use ecampus (ecampus.chu.edu.tw) to submit all code including your
   document electronically. The submission ID is "Exercise 7.

 (10 points)

Open a file that contains numbers and find the maximum value, minimum value,
and average of them. The file format is as follows:

12:14:57:-32:88:23
99:72:-38
1:18:-66:2266:5438

 A possible run may look like:

 Enter the file name: data.txt
 The numbers are:
 12 14 57 -32 88 123 99 72 -38 1 18 -66 2266 5438
 
 The numbers after sorting are:
 -66 -38 -32 1 12 14 18 57 72 88 99 123 2266 5438
 The maximum value is 5438.
 The minimum value is -66.
 The average is 568.000.*/
