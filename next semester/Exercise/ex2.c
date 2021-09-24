//檔名:ex2.c
//編輯器:Dev-C++
//日期:2012/3/1
#include <stdio.h>
#include <stdlib.h>

typedef struct { //點座標 
  double x, y;
} Point;

typedef struct { //兩點 
  Point a, b;
} Line;

int function(Line l){//判斷線的函式 
  int i;//return的值 
  if(l.a.x == l.b.x && l.a.y == l.b.y)i = 0;//not a line 一個點 
  if(l.a.x != l.b.x && l.a.y != l.b.y)i = 1;//oblique 斜線 
  if(l.a.x == l.b.x && l.a.y != l.b.y)i = 2;//vertical 垂直線 
  if(l.a.x != l.b.x && l.a.y == l.b.y)i = 3;//horizontal 水平線 
  return i;
}
void printf_function(Line l){  //列印結果的函式 
  switch(function(l))//帶入判斷線的函式
  {
    case 0:printf("It is not a line\n");break;//not a line 一個點
	case 1:printf("The line is oblique\n");break;//oblique 斜線 
    case 2:printf("The line is vertical\n");break;//vertical 垂直線 
    case 3:printf("The line is horizontal\n");break;//horizontal 水平線   
  }	
}

int main() {
  Line l;
  printf("Enter two points of the line: ");
  scanf("%lf%lf%lf%lf", &l.a.x, &l.a.y, &l.b.x, &l.b.y);//輸入點 
  printf("Two points of the line are (%lf, %lf) and (%lf, %lf).\n", 
  l.a.x, l.a.y, l.b.x, l.b.y);
  printf_function(l);//呼叫印結果的函式
  system("pause"); 
}

/*
where a and b are the beginning and ending points of the line.

1. Write a function that accepts a structure of type Line and returns an integer
(0, 1, 2, 3), where 0 means it is not a line, 1 means vertical, 2 means horizontal, 
and 3 means oblique. Write a main function that reads a line and invokes the function
to decide if a line is vertical, horizontal, or oblique. 
2. Write the main function to use the above function.


A possible run may look like:

Enter two points of the line: 1 1 1 1
It is not a line.
Enter two points of the line: 1 1 1 3
The line is vertical.
Enter two points of the line: 1 1 3 1
The line is horizontal.
Enter two points of the line: 1 1 3 3
The line is oblique.
*/
