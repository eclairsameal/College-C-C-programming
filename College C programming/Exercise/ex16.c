//檔名:ex16.c
//編譯器:Dev-c++
//日期:2011/12/28
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100 

void function(int n ,char a[SIZE]){
  int i;
  for(i=0;i<n;i++){
    a[i]= rand()%58+65;
      if(a[i]>90 && a[i]<97)i--;
  } 
}

main() {
  int n,j,sum=0;
  char a[SIZE],c;
  srand(time(0));
  printf("enter n:");
  scanf("%d",&n);
  function(n,a);
  printf("The string is %s\n",a);
  printf("Enter the character:");
  getchar();
  scanf("%c",&c);
  for(j=0;j<n;j++){
    if(a[j]==c)sum++;
    }
  printf(" a appears %d times\n",sum);
  system("pause");
  return 0; 
}
/*
1. Write the following 2 functions:

  1) (5 points) a function that passes n and randomly generates a
     string with n alphabet characters from a to z or A to Z.
  2) (5 points) a function that passes a character and a string
     and count the number of appearances of the character in the string.
2. (2 points) Write the main program to use the above functions.

A possible run may look like:

Enter n: 6
The string is atHika.
Enter the character: a
a appears 2 times.
*/ 
