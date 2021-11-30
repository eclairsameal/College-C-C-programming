//檔名:ex6.c
//編輯器:Dev-C++
//日期:2011/10/19

#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int main(){
srand(time(NULL));
int a,b,c; //a=骰子數 b=猜總數 c=亂數
printf("Number of dices:");
scanf("%d",&a);
c = rand() %(6*a-1) + a;
//printf("%d\n",c); 

printf("Guess the sum of %d dice:",a);
while(c!=b){

scanf("%d",&b);

if (b>c)printf("Too high. Try again:");

if (b<c)printf("Too low. Try again:");


}
if (b==c){printf("Excellent! You guessed the correct number!");
}

system("pause");
return 0;
}
/*
Write a program that plays the game of "guess the sum of dices" as follows.
Choose the number of dices and guess the sum until it is correct. A
possible run may look like:

Number of dices: 1
Guess the sum of 1 dice: 4
Too high. Try again: 2
Too low. Try again: 3
Excellent! You guessed the correct number!
Number of dices: 3
Guess the sum of 3 dices: 9
Too low. Try again: 16
Too high. Try again: 13
Too low. Try again: 14
Excellent! You guessed the correct number!
*/ 
