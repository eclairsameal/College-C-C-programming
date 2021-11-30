//檔名:ex17.c
//編譯器:Dev-c++
//日期:2011/1/4
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
main(){
    char a[SIZE]={0},b[26],c[26];// 輸入的字串 小寫  大寫 
    int i,j,k,t=0;//變數控制  控制是否相同的變數 
    
    printf("Enter a sentence:");
    fgets(a, SIZE, stdin);
    printf("%s", a); 
    for(i = 0; i < 26; i++ )  //產生字母 
      {
        b[i] = i + 'a';  //小寫 
        c[i] = i + 'A';  //大寫 
      }
      for(j = 0; j < 26; j++ )  //字母
        {
          for(k = 0; k < SIZE; k++)  //輸入的字串
            {
              if(a[k]==b[j])t++;    //比小寫 
              if(a[k]==c[j])t++;    //比大寫
              }
              if(t!=0)printf("%c = %d\n",b[j],t);  //如果有相同就印出 
              t=0;  
        }
       
    system("pause");       
}
/*
 Write a program that reads a sentence and count the occurences of each letter
 ignoring the case. A possible run may look like:

 Enter a sentence: Knowledge is power.
 d: 1
 e: 3
 g: 1
 i: 1
 l: 1
 k: 1
 n: 1
 o: 2
 p: 1
 r: 1
 s: 1
 w: 2

*/ 
