//�ɦW:ex15.c
//�sĶ��:Dev-c++
//���:2011/12/22 
#include <stdio.h>
#include <stdlib.h>
void main(int argc, char *argv[]){
	int i;
	float sum=0,n=0;
	float max=atof(argv[2]),min=atof(argv[2]);//�����]�̤j�̤p�Ȭ��Ĥ@�Ӽ�(argv[2]) 
	  switch (argv[1][1]) {//�P�_ a M m
			case 'a'://���� 
				for(i=2; i<=argc; i++){
				n=atof(argv[i]);//�N�r���ন�B�I�� 
				sum += n;//�`�M				
				}
				printf("-a=> %.2f\n",sum/(argc-2));
				break;
			case 'M'://�̤j�� 
			    for(i=3;i<argc;i++){	
				  n=atof(argv[i]);//�N�r���ন�B�I�� 	
				  if(max<n)max=n;//�P�_�j�p 
				}
                printf("-M=> %.2f",max);
				break;
			case 'm'://�̤p�� 
				for(i=3;i<argc;i++){	
				  n=atof(argv[i]);//�N�r���ন�B�I�� 	
				  if(min>n)min=n;//�P�_�j�p 
				}
                printf("-m=> %.2f",min);
				break;				
		}	
system("pause");
return 0;
}
/*
 Write a program that reads a option and then a list of numbers and based
 on the option to 

 -a: average all numbers
 -M: list the maximum number
 -m: list the minimum number 

A possible run may look like:

> cal -a 10.0 30.0 20.0
20.0
> cal -M 30.2 60.3 50.4 20.1 10.8 
60.3
> cal -m 30.2 60.3 50.4 -9.5 6.88 4.32
-9.5


Hint: Use the function atof().

*/ 
