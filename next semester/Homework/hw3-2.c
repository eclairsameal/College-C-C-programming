//�ɦW:hw3-2.c
//�s�边:Dev-C++
//���:2012/4/30 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#define SIZE 100

int numberletters(char inputstr[SIZE], int n) {
  int i = 0, len, j, k = 0;
  char *pch, words[SIZE][SIZE], inputstring[SIZE];
  
  strcpy(inputstring, inputstr);
  len = strlen(inputstring)-1;//�p��r��j�p
  inputstring[len] = '\0'; //�h������ 
  pch = strtok (inputstring," ,.");//�r�ꪺ���� 
  while (pch != NULL){
	strcpy(words[i++], pch);
    pch = strtok(NULL," ,.");
    }

  for(j = 0; j < i; j++) {//�P�_���X�Ӧr�ŦX��J��n�� 
    if(strlen(words[j]) == n)
	  k++;
  }    
  return k;
}

void converted(char inputstring[SIZE], char key[SIZE]) {//�j�p�g���ഫ 
  int len, i, j, keylen;
  int row, r, k;
  char str1[strlen(inputstring)], str2[strlen(inputstring)];
  
  strcpy(str1, inputstring);
  len = strlen(str1);//�p��r����� 
  for(i = 0; i < len ; i++){
    if(islower(str1[i]))//�P�_�O�_���p�g 
	  str1[i] = toupper(str1[i]);//�p�g��j�g 
	else if (isupper(str1[i]))//�P�_�O�_���j�g 
	  str1[i] = tolower(str1[i]);//�j�g��p�g 
	} 
  keylen = strlen(key);//key�r�����
  if(strlen(str1) % keylen == 0) //��J���r���Qkey�r��㰣 
    row=strlen(str1)/keylen;//��J���r���Q�����X�� 
  else //��J���r�ꤣ���n�ꦨ�@�� 
    row=strlen(str1)/keylen +1 ; 
              
  char rowstr[row][keylen+1];//�ŧi�G���r���}�C// 
   
  strcpy(str2, str1);
  
  for(r = 0; r < row - 1; r++){
    strncpy(rowstr[r], str2, keylen);
    rowstr[r][keylen] = '\0';
    for(j = keylen * (r+1); str1[j]!= '\0'; j++ )
      str2[j-keylen*(r+1)] = str1[j];
    str2[j-keylen*(r+1)] = '\0';
  }	   
  strcpy(rowstr[r], str2); 
  i = strlen(rowstr[r]);//rowstr�r�����
  if(i < keylen){
    for(j = i; j < keylen; j++)    
      rowstr[r][j] = ' ';
    rowstr[r][j]='\0';   
  }   
  int array[keylen]; //�ŧi�ܼ�//�ƦC 
  int banner[keylen]; //�ŧi�ܼ�//���� 

  for(i  =0; i < keylen; i++)banner[i] = 0;//�]�ܼư_�l�Ȭ�0    
 
  for(i = 0; i < keylen; i++){
    int bannerregister;
    int arrayregister;
    char minc;
    for(j = 0; j < keylen; j++){
      if(banner[j] == 0){
        minc = key[j];
        arrayregister = j;
        bannerregister = j;
        break;
      }
    }
                
    for(k = 0; k < keylen; k++){      
      if(minc > key[k] && banner[k] == 0){
        minc = key[k]; //�w�q minc               
        arrayregister = k;  
        bannerregister = k;
      }
    }
    array[arrayregister] = i + 1; //�g�L�Ƨǫ�r������m
    banner[bannerregister] = 1;
  }  
  printf("The encrypted string: ");
   
  for(j = 1; j <= keylen; j++){
    int a;
    for(i = 0; i < keylen; i++)
      if(array[i] == j)
        a = i;
    for(r = 0; r < row; r++)printf("%c", rowstr[r][a]);//�C�L���G          
  }    
}

int main(){
  char inputstr[SIZE], key[SIZE];//��J���r��   ����r
  int n;
  
  printf("Enter the string:");	 	
  fgets(inputstr, SIZE, stdin);//Ū��J���r�� 
  printf("Enter the number of letters in the word:");
  scanf("%d",&n);
  printf("There are %d words of %d letters.\n",numberletters(inputstr, n), n);
  printf("Enter the key:");
  scanf("%s", key);//��Jkey
  converted(inputstr, key);
  system("pause");
  return 0;
}
/*
1. Write a function that passes a string and a number n and returns the count of the words with n letters.
2. Write a function that passes a string and a key and generates an encrypted string. The rule of encryption is as follows:
	1. A lowercase letter is converted to a uppercase and a uppercase one is converted to a lowercase one.
	2. Then use transposition cipher to encrypt the string.
	For example, the input string is "Knowledge is power." The key is "insanity".
	1. "kNOWLEDGE IS POWER."
	2. 24615378          (insanity)          ----------           kNOWLEDG           E IS POW           ER.
	3. "WS kEEEP N RL OI.DO GW "
3. Write a main function that reads the string and call above two functions.
A possible run may look like:
Enter the string: Knowledge is power. Time is money.  Enter the number of letters in the word: 2 There are 2 words of 2 letters. Enter the key: insanity The encrypted string: WS   kEE YEPIO N RI.L tM OI.S DOMN GWEE
*/ 
