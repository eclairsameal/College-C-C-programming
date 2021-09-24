//檔名:ex5.c
//編輯器:Dev-C++
//日期:2012/3/19
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100 
typedef struct{  //座標函式 
  float x, y;	
}Points;

float distance(float a,float b){//兩點之間的距離函示 
  return sqrt(a * a + b * b);	
}

main(){
  FILE *pt;//檔案指標 
  char name[SIZE];
  float max = 0;
  Points p,p1;
  printf("Enter the file name:");
  scanf("%s",name);//輸入檔名 

  pt = fopen(name, "r");  //開檔  讀 
  if(pt!=NULL){
    while(!feof(pt)){  
	fscanf(pt,"%f%f",&p.x,&p.y);  //讀兩個點座標 
	if(max < distance(p.x,p.y)){//判斷距離大小 
	  max = distance(p.x,p.y); 
      p1.x = p.x;
      p1.y = p.y;            
	}
    }
    printf("The point (%f, %f) is farest from the origin point.\n",//印出點座標 
	p1.x, p1.y);
	printf("The distance is %f\n",max);//印出距離 
  }
  
  else printf("File cannot be opened\n");//開檔錯誤 
  fclose(pt);
  system("pause");
}
/*
1. Create a struct for a point. 
2. Read a file with points' coordinates. Find the point that is
  farest from the origin point and prints the points and the
  distance. For example, a file points.txt has the following 
  content:

 1.0 1.0 -2.1 1.3 5.0 -12.0 -3.4 6.8
 2.3 4.3
 1.2 -11.1
 ...
 ...

 A possible run may look like:

 Enter the file name: points.txt
 The point (5.000, -12.000) is farest from the origin point.
 The distance is 13.000.
*/ 
