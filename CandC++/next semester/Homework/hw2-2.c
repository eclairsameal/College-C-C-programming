//�ɦW:hw2-2.c
//�s�边:Dev-C++
//���:2012/3/25
#include <stdio.h>
#include <stdlib.h>

typedef struct{//�ɶ����c
int hour, min, sec;//�p�� ���� ��
}Clock;

int range(Clock c){//�P�_��J���ɶ��O�_�ŦX�d�� 
  if(c.hour > 24 || c.min > 60 || c.sec > 60)return 0;
  else return 1;
}

Clock sum(Clock c1, Clock c2){//�N�⦸�ɶ��ۥ[ 
  Clock c;
  c.hour = c1.hour + c2.hour;
  c.min = c1.min + c2.min;
  c.sec = c1.sec + c2.sec;
  if(c.sec >= 60)//���i�� 
    {
	  c.sec = c.sec - 60;
	  c.min++;
	}
  if(c.min >= 60)//�����i�� 
    {
	  c.min = c.min - 60;
	  c.hour++;
	}
  if(c.hour >= 24)
    {
	  c.hour = c.hour - 24;
	}
  return c;
}

int main(){
  Clock c, c1, c2;
  do{
    printf("Enter the first time:");
    scanf("%d:%d:%d",&c1.hour,&c1.min,&c1.sec);//��J�ɶ��@ 
  }while(range(c1)==0);//�P�_��J���ɶ��O�_�ŦX�d�� 
  do{
    printf("Enter the second time:");
    scanf("%d:%d:%d",&c2.hour,&c2.min,&c2.sec);//��J�ɶ��G 
  }while(range(c2)==0);//�P�_��J���ɶ��O�_�ŦX�d�� 
  c = sum(c1, c2);//�N�⦸�ɶ��ۥ[
  printf("%d:%d:%d + %d:%d:%d = %d:%d:%d\n",
    c1.hour,c1.min,c1.sec,c2.hour,c2.min,c2.sec,c.hour,c.min,c.sec);  
  system("pause");
}
/*Create a program for time using the structure.
1. Create a structure for time with hour, minute, and second.
2. Write a function that passes hour, minute, and second and returns a time structure and make sure to verify if time is within the range.
3. Write a function that passes a time structure and prints the time in the form HH:MM:SS. For example, 11:12:00.
4. Write a function that passes two time structures and returns 1 if two times are the same, otherwise, returns 0.
5. Write a function that passes two time structure and returns a time structure of the sum of two times. For example, the sum of 05:30:20 and 12:40:30 is 18:10:50.
6. Write the main function to read two times and use the above functions.

A possible run may look like:
Enter the first time: 18:32:90
Enter the second time: 12:52:10
18:32:00 + 12:52:10 = 07:24:10
18:32:00 != 12:52:10*/
