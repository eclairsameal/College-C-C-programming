//�ɦW:hw4-2.c
//�sĶ��:Dev-c++
//���:2011/12/10
#include <stdio.h>
#include <stdlib.h>
double distance(int a,int b,int c,int px,int py) //�p���I�쪽�u�Z�����禡 
{
	double x, y, sum; 
	x = fabs((a * px) + (b * py) + c);//�N�I�a�J��{��(�Z���ҥH�ε����) 
	y = sqrt((a * a) + (b * b));//�I�쪽�u�Z�������������� 
	sum = x/y;
	return sum;
	}
double area(int a,int b,int c,int px,int py)//�p�⤺���ꭱ�n���禡
{
   float x, y, m,r;
    x = c/a;//x�b���I�Z 
    y = c/b;//y�b���I�Z
    m = sqrt(((x * x) + (y * y)));//����� 
    r=(x+y-m)/2;//������b�|	
	return (3.14159265*r*r);//������b�| 
	}

int main()//�D�禡 
{
	int a,b,c,px,py;//a,b,c ��{�����t�� px,py �I�y�� 
	printf("Enter the a, b, c of ax + by = c and a point (px, px):");
	scanf("%d%d%d%d%d",&a,&b,&c,&px,&py);
	printf("The distance of the line to the point is %lf\n",distance(a,b,c,px,py));
	if(a==0 || b==0 )//��{���Mx�by�b����S�������� 
	printf("The area of the incircle of the triangle is 0\n");
	else printf("The area of the incircle of the triangle is %lf",area(a,b,c,px,py));

system("pause");
}


/*
(No: 5, 6, 7, 8, 9) (10 points) A line equations is represented by ax + by = c where a, b, and c are coefficients.
1.(3 points) Write a function that passes the coefficients of the line and x and y coordinates of a point and returns the distance of the point to the line.
2.(4 points) Write a function that passes the coefficients of the line and returns the area of the incircle of the triangle formed by the line, x-axis and y-axis.
3.(3 points) Write the main function to use above functions.

A sample session may look like as follows:
Enter the a, b, c of ax + by = c and a point (px, px): 1 1 4 0 0
The distance of the line to the point is 2.828427.
The area of the incircle of the triangle is 4.31209667562.
Enter the a, b, c of ax + by = c and a point (px, px): 1 0 4 0 0
The distance of the line to the point is 4.000000.
The area of the incircle of the triangle is 0.000000.*/
