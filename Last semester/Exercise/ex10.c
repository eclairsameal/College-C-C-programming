//檔名: ex10.c
//編譯器: Dev-C++
//日期:2011/11/17
#include<stdio.h>
#include<stdlib.h>

int main(){
    int score[3],count=0,i,j,k;
    float exam[3]={0},average[60],a=0,b=101;

    do{
        printf("Enter scores(-1 to end)");
        scanf("%d%d%d",&score[0],&score[1],&score[2]);
        average[count]=(score[0]+score[1]+score[2])/3.0;    //計算個人平均
        exam[0]+=score[0];   //第1次分數加總 
        exam[1]+=score[1];   //第2次分數加總 
        exam[2]+=score[2];   //第3次分數加總 
        count++;   //人數 
        
        }while(score[0]!= -1);


     for(i = 0;i <count-1;i++)
		{
        printf("Student %d: %f\n",i+1,average[i]);   //個人平均
        if(a<average[i])a=average[i];
	    if(b>average[i])b=average[i];
	    }

        printf("The highes average is %f and lowest average is %f\n",a,b);
        printf("The average of exam 1 is %f\n",(exam[0] + 1)/(count - 1));   //第1次考試平均
        printf("The average of exam 2 is %f\n",(exam[1] + 1)/(count - 1));   //第2次考試平均
        printf("The average of exam 3 is %f\n",(exam[2] + 1)/(count - 1));   //第3次考試平均

system("pause");
}

/*
 A class has three exams and at most 60 students. Calculate the
 average for each student and for each exam and find the lowest
 and highest average scores.

 A possible run may look like:

Enter scores (-1 to end): 60 70 80
Enter scores (-1 to end): 70 80 90
Enter scores (-1 to end): 80 70 90
Enter scores (-1 to end): 70 60 80
Enter scores (-1 to end): 50 60 70
Enter scores (-1 to end): 90 70 80
Enter scores (-1 to end): -1 -1 -1
Student 1: 70.00
Student 2: 80.00
Student 3: 80.00
Student 4: 70.00
Student 5: 60.00
Student 6: 80.00
The highest average is 80.00 and lowest average is 60.00.
The average of Exam 1 is 70.00.
The average of Exam 2 is 68.33.
The average of Exam 3 is 81.67.
*/ 
