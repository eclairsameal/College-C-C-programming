//�ɦW:ex17.c
//�sĶ��:Dev-c++
//���:2011/1/4
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
main(){
    char a[SIZE]={0},b[26],c[26];// ��J���r�� �p�g  �j�g 
    int i,j,k,t=0;//�ܼƱ���  ����O�_�ۦP���ܼ� 
    
    printf("Enter a sentence:");
    fgets(a, SIZE, stdin);
    printf("%s", a); 
    for(i = 0; i < 26; i++ )  //���ͦr�� 
      {
        b[i] = i + 'a';  //�p�g 
        c[i] = i + 'A';  //�j�g 
      }
      for(j = 0; j < 26; j++ )  //�r��
        {
          for(k = 0; k < SIZE; k++)  //��J���r��
            {
              if(a[k]==b[j])t++;    //��p�g 
              if(a[k]==c[j])t++;    //��j�g
              }
              if(t!=0)printf("%c = %d\n",b[j],t);  //�p�G���ۦP�N�L�X 
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
