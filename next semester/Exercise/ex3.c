//檔名:ex3.c
//編輯器:Dev-C++
//日期:2012/3/8

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void main(int argc, char *argv[]){
  char line[MAX], a[26]={0}, b[26], c[26];
  int i, j, k, t=0, n;

  FILE *ftp;//檔案指標 
  ftp = fopen(argv[1], "r");//開檔
  if(ftp!=NULL){
	
    while(fgets(line, MAX , ftp) != NULL) {
	
  	  printf("%s", line);
  	  n = strlen(line);
	  for(j = 0; j < 26; j++ )  //字母
        {
	      b[j] = j + 'a';  //小寫 
          c[j] = j + 'A';  //大寫 
            for(i = 0; i < n; i++)  //輸入的字串
              {
                if(line[i]==b[j])t++;    //比小寫 
                if(line[i]==c[j])t++;    //比大寫            
			  } 
			a[j] += t;
            t=0;
        }    
	}
	fclose(ftp);
    printf("\n");
    for(k = 0; k < 26; k++)if(a[k]!=0)printf("%c = %d\n",k+ 'a',a[k]);
//印出 
  }
  else//開檔失敗 
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
