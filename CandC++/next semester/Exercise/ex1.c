/*
檔名:Dev-C++
編譯器:ex1
*/ 
#include <stdio.h>
#include <stdlib.h>

typedef struct {//點座標 
  double x ,y;
} Point;

typedef struct {//三邊長 
  double a ,b, c;
} Line;

double distance(Point p1, Point p2) {//點到點之間的距離函式 
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));//回傳距離 
}

double triangle_area(Line e) {//三角形面積函式 
  double s;
  s = (e.a + e.b + e.c)/2;
  return sqrt(s * (s - e.a) * (s - e.b) * (s - e.c));//海龍公式  
}

  main(){
  Point p1 ,p2, p3; //三個座標 
  Line s;
  printf("Enter three points:");
  scanf("%lf%lf%lf%lf%lf%lf",
  &p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y);//輸入三個點座標
  
  s.a = distance(p1, p2);//點1到點2的邊長
  s.b = distance(p2, p3);//點2到點3的邊長
  s.c = distance(p1, p3);//點1到點3的邊長
  
  if(s.a + s.b > s.c && s.b + s.c > s.a &&  s.c + s.a > s.b)//判斷是否為三角形 
  {    
    printf("The area formed by (%.2f, %.2f), (%.2f, %.2f), and (%.2f, %.2f) is %.2f\n",
	p1.x, p1.y ,p2.x, p2.y,p3.x, p3.y,triangle_area(s));//呼叫三角形面積函式
  }
  else printf("(%.2f, %.2f), (%.2f, %.2f), and (%.2f, %.2f)cannot form a triangle\n",
  p1.x, p1.y ,p2.x, p2.y,p3.x, p3.y);//不是三角形 
  system("pause");
}

/*
A point can be represented by the following structure:

 typedef struct { 
   double x, y;
 } Point;

 1. Write a function that passes two points and returns the distance
    of two points. 
 2. Write the function to pass 3 points, use the above function to
    calculate the triangle area formed by these 3 points.
 3. Write the main function to use the above functions.

A possible run may look like:

Enter three points; 1 1 1 4 5 1
The area formed by (1.00, 1.00), (1.00, 4.00), and (5.00, 1.00) is 6.00.
Enter three pints: 0 0 1 1 2 2
(0, 0), (1, 1), and (2, 2) cannot form a triangle.
Enter three points: -1 -1 -1 4 11 -1
The area formed by (-1.00, -1.00), (-1.00, 4.00), and (11.00, -1.00) is 30.00

 Hint: 

 1. The distance between two points (x1, y1) and (x2, y2) is
    sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)).
 2. Suppose a triangle with 3 sides: a, b, c. s = (a + b + c)/2.
    The area of the triangle is sqrt(s * (s - a) * (s - b) * (s - c)).
 3. Refer to the following code.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
 double x, y;
} Point;

double distance(Point p1, Point p2) {
}

main() {
  Point p;
  
  printf("Enter the point: ");
  scanf("%lf%lf", &p.x, &p.y);
  printf("The point is (%f, %f).\n", p.x, p.y);
  system("pause");
}
*/ 
