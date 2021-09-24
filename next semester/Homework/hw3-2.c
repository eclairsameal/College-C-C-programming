//檔名:hw3-2.c
//編輯器:Dev-C++
//日期:2012/4/30 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#define SIZE 100

int numberletters(char inputstr[SIZE], int n) {
  int i = 0, len, j, k = 0;
  char *pch, words[SIZE][SIZE], inputstring[SIZE];
  
  strcpy(inputstring, inputstr);
  len = strlen(inputstring)-1;//計算字串大小
  inputstring[len] = '\0'; //去掉換行 
  pch = strtok (inputstring," ,.");//字串的切割 
  while (pch != NULL){
	strcpy(words[i++], pch);
    pch = strtok(NULL," ,.");
    }

  for(j = 0; j < i; j++) {//判斷有幾個字符合輸入的n值 
    if(strlen(words[j]) == n)
	  k++;
  }    
  return k;
}

void converted(char inputstring[SIZE], char key[SIZE]) {//大小寫的轉換 
  int len, i, j, keylen;
  int row, r, k;
  char str1[strlen(inputstring)], str2[strlen(inputstring)];
  
  strcpy(str1, inputstring);
  len = strlen(str1);//計算字串長度 
  for(i = 0; i < len ; i++){
    if(islower(str1[i]))//判斷是否為小寫 
	  str1[i] = toupper(str1[i]);//小寫轉大寫 
	else if (isupper(str1[i]))//判斷是否為大寫 
	  str1[i] = tolower(str1[i]);//大寫轉小寫 
	} 
  keylen = strlen(key);//key字串長度
  if(strlen(str1) % keylen == 0) //輸入的字串能被key字串整除 
    row=strlen(str1)/keylen;//輸入的字串能被切成幾行 
  else //輸入的字串不能剛好湊成一行 
    row=strlen(str1)/keylen +1 ; 
              
  char rowstr[row][keylen+1];//宣告二維字元陣列// 
   
  strcpy(str2, str1);
  
  for(r = 0; r < row - 1; r++){
    strncpy(rowstr[r], str2, keylen);
    rowstr[r][keylen] = '\0';
    for(j = keylen * (r+1); str1[j]!= '\0'; j++ )
      str2[j-keylen*(r+1)] = str1[j];
    str2[j-keylen*(r+1)] = '\0';
  }	   
  strcpy(rowstr[r], str2); 
  i = strlen(rowstr[r]);//rowstr字串長度
  if(i < keylen){
    for(j = i; j < keylen; j++)    
      rowstr[r][j] = ' ';
    rowstr[r][j]='\0';   
  }   
  int array[keylen]; //宣告變數//排列 
  int banner[keylen]; //宣告變數//紀錄 

  for(i  =0; i < keylen; i++)banner[i] = 0;//設變數起始值為0    
 
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
        minc = key[k]; //定義 minc               
        arrayregister = k;  
        bannerregister = k;
      }
    }
    array[arrayregister] = i + 1; //經過排序後字母的位置
    banner[bannerregister] = 1;
  }  
  printf("The encrypted string: ");
   
  for(j = 1; j <= keylen; j++){
    int a;
    for(i = 0; i < keylen; i++)
      if(array[i] == j)
        a = i;
    for(r = 0; r < row; r++)printf("%c", rowstr[r][a]);//列印結果          
  }    
}

int main(){
  char inputstr[SIZE], key[SIZE];//輸入的字串   關鍵字
  int n;
  
  printf("Enter the string:");	 	
  fgets(inputstr, SIZE, stdin);//讀輸入的字串 
  printf("Enter the number of letters in the word:");
  scanf("%d",&n);
  printf("There are %d words of %d letters.\n",numberletters(inputstr, n), n);
  printf("Enter the key:");
  scanf("%s", key);//輸入key
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
