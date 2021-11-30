//�ɦW:ex5.c
//�s�边:Dev-C++
//���:2012/3/19
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100 
typedef struct{  //�y�Ш禡 
  float x, y;	
}Points;

float distance(float a,float b){//���I�������Z����� 
  return sqrt(a * a + b * b);	
}

main(){
  FILE *pt;//�ɮ׫��� 
  char name[SIZE];
  float max = 0;
  Points p,p1;
  printf("Enter the file name:");
  scanf("%s",name);//��J�ɦW 

  pt = fopen(name, "r");  //�}��  Ū 
  if(pt!=NULL){
    while(!feof(pt)){  
	fscanf(pt,"%f%f",&p.x,&p.y);  //Ū����I�y�� 
	if(max < distance(p.x,p.y)){//�P�_�Z���j�p 
	  max = distance(p.x,p.y); 
      p1.x = p.x;
      p1.y = p.y;            
	}
    }
    printf("The point (%f, %f) is farest from the origin point.\n",//�L�X�I�y�� 
	p1.x, p1.y);
	printf("The distance is %f\n",max);//�L�X�Z�� 
  }
  
  else printf("File cannot be opened\n");//�}�ɿ��~ 
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
