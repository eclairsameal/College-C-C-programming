//�ɦW:ex3.c
//�s�边:Dev-C++
//���:2012/3/8

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void main(int argc, char *argv[]){
  char line[MAX], a[26]={0}, b[26], c[26];
  int i, j, k, t=0, n;

  FILE *ftp;//�ɮ׫��� 
  ftp = fopen(argv[1], "r");//�}��
  if(ftp!=NULL){
	
    while(fgets(line, MAX , ftp) != NULL) {
	
  	  printf("%s", line);
  	  n = strlen(line);
	  for(j = 0; j < 26; j++ )  //�r��
        {
	      b[j] = j + 'a';  //�p�g 
          c[j] = j + 'A';  //�j�g 
            for(i = 0; i < n; i++)  //��J���r��
              {
                if(line[i]==b[j])t++;    //��p�g 
                if(line[i]==c[j])t++;    //��j�g            
			  } 
			a[j] += t;
            t=0;
        }    
	}
	fclose(ftp);
    printf("\n");
    for(k = 0; k < 26; k++)if(a[k]!=0)printf("%c = %d\n",k+ 'a',a[k]);
//�L�X 
  }
  else//�}�ɥ��� 
  printf("File cannot be opened\n");
  
  system("pause"); 

}
//while ((ch=getc(ftp))!=EOF
//count(line);

/*
 Write a program that reads a file name from the command line and count the 
 occurences of each letter ignoring the case in the file. For example, a
 file motto.txt contains:

 Knowledge is power.
 Time is money.

A possible run may look like:

 > letter-count motto.txt
 d: 1
 e: 5
 g: 1
 i: 3
 l: 1
 k: 1
 m: 2
 n: 2
 o: 3
 p: 1
 r: 1
 s: 2
 t: 1
 w: 2
 y: 1

where letter-count is the compiled running code.
*/ 
