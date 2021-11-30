//�ɦW:hw1-4.c
//�s�边:Dev-C++
//���:2012/3/5

#include <stdio.h>
#include <stdlib.h>

typedef struct {//�I�y�� 
double x, y;
} Point;

typedef struct {//�T���ΤT�I 
Point a, b, c;
} Triangle;

double distance(Point p1, Point p2) {//�I���I�������Z���禡
return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));//�^�ǶZ��
}
double perimeter(Triangle t) {//�T���ΩP���禡
return distance(t.a,t.b) + distance(t.a,t.c) + distance(t.b,t.c);//�^�ǩP��
}

double triangle_area(Triangle t) {//�T���έ��n�禡
double s;
s = perimeter(t)/2;
return sqrt(s * distance(t.a,t.b) * (s - distance(t.a,t.c)) * (s - distance(t.b,t.c)));//���s����
}

void inside(Triangle t, Point p){//�T���Τ��߮y�Ш禡
  Point i;
  i.x = ((t.a.x*distance(t.b,t.c))+(t.b.x*distance(t.a,t.c))+(t.c.x*distance(t.a,t.b)))/perimeter(t);//�T���Τ���X�y��
  i.y = ((t.a.y*distance(t.b,t.c))+(t.b.y*distance(t.a,t.c))+(t.c.y*distance(t.a,t.b)))/perimeter(t);//�T���Τ���Y�y��
  if(p.x == i.x && p.y == i.y)printf("(%lf, %lf) is inside the triangle\n",i.x, i.y);//�P�_��J���y�ЬO�_���T���Τ���
  else printf("The triangle cannot be formed\n");
}

main(){
  Triangle t;
  Point p;

  printf("Enter the three points of the triangle:");
  scanf("%lf%lf%lf%lf%lf%lf",
    &t.a.x,&t.a.y,&t.b.x,&t.b.y,&t.c.x,&t.c.y);
  printf("%lf %lf %lf %lf %lf %lf\n",
    t.a.x,t.a.y,t.b.x,t.b.y,t.c.x,t.c.y);
  printf("Enter the point:");
  scanf("%lf%lf",&p.x,&p.y);
  printf("The perimeter of the triangle is %lf\n",perimeter(t));//�T���ΩP��
  printf("%lf\n",triangle_area(t));
  inside(t, p);
  system("pause");
}

/*
Consider the following structure for a point.
typedef struct {
   double x, y;
} Point;

1.Define a struct to represent a triangle which has three points.
2.Write a function that passes a triangle and returns its perimeter.
3.Write a function that passes a triangle and returns its area.
4.Write a function that passes a traingle and a point and returns true if the point is inside the triangle.
5.Write the main function to read three points of the triangle and the point and use the above functions.
A possible run may look like:

Enter the three points of the triangle: 0 0 3 0 0 4
Enter the point: 1 1
The perimeter of the triangle is 12.00.
The area of the triangle is 6.00.
(1.00, 1.00) is inside the triangle.
Enter the three points of the triangle: 0 0 3 0 4 0
Enter the point: 1 1
The triangle cannot be formed.
*/
