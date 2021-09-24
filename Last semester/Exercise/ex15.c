//郎:ex15.c
//絪亩竟:Dev-c++
//ら戳:2011/12/22 
#include <stdio.h>
#include <stdlib.h>
void main(int argc, char *argv[]){
	int i;
	float sum=0,n=0;
	float max=atof(argv[2]),min=atof(argv[2]);//安砞程程材计(argv[2]) 
	  switch (argv[1][1]) {//耞 a M m
			case 'a'://キА 
				for(i=2; i<=argc; i++){
				n=atof(argv[i]);//盢﹃锣Θ疊翴计 
				sum += n;//羆㎝				
				}
				printf("-a=> %.2f\n",sum/(argc-2));
				break;
			case 'M'://程 
			    for(i=3;i<argc;i++){	
				  n=atof(argv[i]);//盢﹃锣Θ疊翴计 	
				  if(max<n)max=n;//耞 
				}
                printf("-M=> %.2f",max);
				break;
			case 'm'://程 
				for(i=3;i<argc;i++){	
				  n=atof(argv[i]);//盢﹃锣Θ疊翴计 	
				  if(min>n)min=n;//耞 
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
