//�ɦW:hw1-2.c
//�s�边:Dev-C++
//���:2012/3/5
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {// n���l d���� 
  int n, d;
} Fraction;

int GCD(int x,int y)
{
int i;//�ŧi���R�ΨӦs��l�� 
//��A���HB���l�Ʈɫh����@����۰��k
    while ( (i = x % y) != 0 )
    {//�����@����A���ƳQ���Ƥ���
        x = y;
        y = i;
    }
return y;//�^�ǳ̤j���]��y
}

void fraction (Fraction f1, Fraction f2, char c){//�|�h�B�⪺�禡�M�C�L 
  int x, y;// ����²�� ���l ����
  if(c == '+'){//�[ 
  x = f1.n * f2.d + f1.d * f2.n;
  y = f1.d * f2.d;
  printf("%d/%d + %d/%d = %d/%d\n",
  f1.n,f1.d,f2.n,f2.d,x/GCD(x,y),y/GCD(x,y));  
  }
  if(c == '-'){//�� 
  x = f1.n * f2.d - f1.d * f2.n;
  y = f1.d * f2.d;
  printf("%d/%d - %d/%d = %d/%d\n",
  f1.n,f1.d,f2.n,f2.d,x/GCD(x,y),y/GCD(x,y));
  }
  if(c == '*'){//�� 
  x = f1.n * f2.n;
  y = f1.d * f2.d;
  printf("%d/%d * %d/%d = %d/%d\n",
  f1.n,f1.d,f2.n,f2.d,x/GCD(x,y),y/GCD(x,y));
  }
  if(c == '/'){//�� 
  x = f1.n * f2.d;
  y = f1.d * f2.n;
  printf("%d/%d / %d/%d = %d/%d\n",
  f1.n,f1.d,f2.n,f2.d,x/GCD(x,y),y/GCD(x,y));
  }		
}

main(){
  Fraction f1, f2;
  char c;
  printf("Enter fraction expression:");
  scanf("%d/%d %c %d/%d",
  &f1.n,&f1.d,&c,&f2.n,&f2.d);  
  if (f1.n!= 0 && f2.n!= 0)fraction(f1,f2,c);//�P�_���l�O�_���s
  else//���l���s
  printf("%d/%d %c %d/%d is undefined",f1.n,f1.d,c,f2.n,f2.d);   
  system("pause");
}

/*
Write a program for a fraction number operations using struct.
1.Define a fraction number using struct.
2.Write the following functions:
  1.A function that passes two fraction numbers and returns the addition of them.
  2.A function that passes two fraction numbers and returns the result of substracting the second number from the first number.
  3.A function that passes two fraction numbers and returns the multiplication of them.
  4.A function that passes two fraction numbers and returns the result of the first number divided by the second number.
3..Write the main function that reads two fraction numbers, invokes the above functions, and prints the result of the above arithematic operations in the reduced form of n/d where n is the numerator and d is the denominator.
A possible run may look like:

Enter the fraction expression: 5/6 + 3/4
5/6 + 3/4 = 19/12
Enter the fraction expression: 5/6 - 3/4
5/6 - 3/4 = 1/12
Enter the fraction expression: 5/6 * 3/4
5/6 * 3/4 = 5/8
Enter the fraction expression: 5/6 / 3/4
5/6 / 3/4 = 10/9
Enter the fraction expression: 5/6 / 0/4
5/6 / 0/4 is undefined.
*/ 
