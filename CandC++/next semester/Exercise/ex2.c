//�ɦW:ex2.c
//�s�边:Dev-C++
//���:2012/3/1
#include <stdio.h>
#include <stdlib.h>

typedef struct { //�I�y�� 
  double x, y;
} Point;

typedef struct { //���I 
  Point a, b;
} Line;

int function(Line l){//�P�_�u���禡 
  int i;//return���� 
  if(l.a.x == l.b.x && l.a.y == l.b.y)i = 0;//not a line �@���I 
  if(l.a.x != l.b.x && l.a.y != l.b.y)i = 1;//oblique �׽u 
  if(l.a.x == l.b.x && l.a.y != l.b.y)i = 2;//vertical �����u 
  if(l.a.x != l.b.x && l.a.y == l.b.y)i = 3;//horizontal �����u 
  return i;
}
void printf_function(Line l){  //�C�L���G���禡 
  switch(function(l))//�a�J�P�_�u���禡
  {
    case 0:printf("It is not a line\n");break;//not a line �@���I
	case 1:printf("The line is oblique\n");break;//oblique �׽u 
    case 2:printf("The line is vertical\n");break;//vertical �����u 
    case 3:printf("The line is horizontal\n");break;//horizontal �����u   
  }	
}

int main() {
  Line l;
  printf("Enter two points of the line: ");
  scanf("%lf%lf%lf%lf", &l.a.x, &l.a.y, &l.b.x, &l.b.y);//��J�I 
  printf("Two points of the line are (%lf, %lf) and (%lf, %lf).\n", 
  l.a.x, l.a.y, l.b.x, l.b.y);
  printf_function(l);//�I�s�L���G���禡
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
