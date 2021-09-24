//檔名:hw4-3.c
//編譯器:Dev-c++
//日期:2011/12/16 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu() {  //項目目錄 
printf("=================================================\n\
Welcome to the Game of Happy Fortune!\n\
The fortune is as follows:\n\
-------------------------------------------------\n\
1: 被爆走的黃泉姐姐請吃便當!\n\
2: 被地獄少女閻魔愛流放到地獄!\n\
3: 獲准加入極上生徒會,獲得助學金1000元!\n\
4: 遇見神獸咪,被咬了一口,錢歸零!\n\
5: 和丘比簽訂契約,成為魔法少女!(再玩一次)\n\
6: 解開貝阿朵莉切的謎題,到達黃金鄉,獲得5000元!\n\
7: 去看水樹奈奈LIVE CASTLE 2011 KING'S NIGHT,QUEEN'S NIGHT,把錢花光了!\n\
8: 和竹井久.美穗子.小和和打麻將大輸,輸了3000元!\n\
9: 誤入六軒島,變成煉獄七姊妹的玩具!\n\
10: 在喜翠莊打工,獲得2000元!\n\
11: 得到御社神羽入的幫助!(再玩一次)\n\
12: 跟著阿國巡迴演出,募集到神社的修繕費1000元\n\
=================================================\n\n");
}
int roll(int sum){//產生亂數的函式 
	int option;
	option=rand()%12+1;
	printf("擲出了選項:%d\n",option);
	roll_option(option,sum);//把亂數值傳入項目的函式 
}
int roll_option(int option,int sum){//項目的函式
    static int sum1=0;
	switch(option){
    case 1:printf("被爆走的黃泉姐姐請吃便當!\n");break;
    case 2:printf("被地獄少女閻魔愛流放到地獄!\n");break;
    case 3:printf("獲准加入極上生徒會,獲得助學金1000元!\n");
           sum+=1000;
	       break;
    case 4:printf("遇見神獸咪,被咬了一口錢歸零!\n");
           sum-=sum;
	       break;
    case 5:printf("和丘比簽訂契約,成為魔法少女!(再玩一次)!\n");
           roll(sum);
	       break;
    case 6:printf("解開貝阿朵莉切的謎題,到達黃金鄉,獲得5000元!\n");
           sum+=5000;
	       break;
    case 7:printf("去看水樹奈奈LIVE CASTLE 2011 KING'S NIGHT,QUEEN'S NIGHT,把錢花光了!\n");
	       sum-=sum;
		   break;
    case 8:printf("和竹井久.美穗子.小和和打麻將大輸,輸了3000元!\n");
	       sum-=3000;
		   break;     
    case 9:printf("誤入六軒島,變成煉獄七姊妹的玩具!\n");
	       break;
    case 10:printf("在喜翠莊打工,獲得2000元!\n");
            sum+=2000; 
	        break;
    case 11:printf("得到御社神羽入的幫助!(再玩一次)\n");
	       roll(sum);
	       break;
    case 12:printf("跟著阿國巡迴演出,募集到神社的修繕費1000元!\n");
	        sum+=1000; 
			break;			   		
    }
	sum1=sum1+sum;

	return sum1;//總金額 
	
}

int main() {
  
  srand(time(NULL));
  int pay=0,sum=0,x=0,i=0; //花費 控制 
  static int games;//遊戲次數
  char a,a1,a2,a3;           
  //是否現在玩 是否進行下一次 增加遊玩次數 是否進行下一場 
  do{ 
  menu(); 
  do{
  printf("要玩幾次遊戲 (玩一次100元):");
  scanf("%d",&games);
  //printf("玩的次數:%d\n",games);
  getchar();
  pay+=100*games;//總花費 
  printf("花費:%d\n",pay);
  printf("感謝你的遊玩,祝你玩得愉快\n");
  printf("是否現在玩(Y/N)?\n");
  scanf("%c",&a);
  getchar();  
  if(a=='y' || a=='Y') {//是否現在玩
      x=1;
	  do{
		i++;//第幾場
		printf("遊戲:%d\n",i);
		if(games==1)printf("\n你花了%d and won NT $%d\n\n",pay,roll(sum));
		
	    if(games >= x){
		  ++x;//控制亂數函式跑幾次
		  roll(sum);//亂數函式					
		  printf("是否現在玩(Y/N)?\n");
          scanf("%c",&a1);
          getchar();
		}
		 
      }while((a1=='y'||a1=='Y') &&  games >= x);//是否進行下一次
} 

  printf("\n");  
  printf("Play more (Y/N)?");
  scanf("%c",&a2);
  getchar();
  printf("\n");
			
}while(a2=='Y'||a2=='y');//增加遊玩次數
  printf("\n你花了%d and won NT $%d\n\n",pay,roll(sum));
  i=0;
  printf("是否離開遊戲(Y/N)?");
  scanf("%c",&a3);
  getchar();
}while(a3=='N'||a3=='n');
printf("感謝你的遊玩!\n\n");

system("pause");
}
/*
Write a program to create a game of wheel of the fortune. There are at least 12 different prize. Your game of the fortune should be different from others. The game is going in the following way:
1.(4 points) Write a function that displays a welcome message and show the wheel of the fortune and returns the selection of the player.
2.The main function is working as follows:
    1.(3 points) The player pays the fee for each game.
    2.(6 points) The player rolls the wheel of fortune and the number on the wheel prints the fortune of the player.
    3.(2 points) The player can decide to continue to play or not.
    4.(5 points) If the player decides not to continue to play, print the results and display a welcome message for a another player.
A sample session may look like as follows:
=================================================
Welcome to the Game of Happy Fortune!
The fortune is as follows:
-------------------------------------------------
 1: NT $300
 2: Play again!
 3: Thanks for your play!
 4: NT $100
 5: Thanks for your play!
 6: Thanks for your play!
 7: Play again!
 8: Thanks for your play!
 9: Thanks for your play!
10: NT $200
11: Thanks for your play! 
12: NT $500 
=================================================
Add games ($50 for each play) : 2 
Number of plays: 2                         
Total pay: $100                                
Thanks for your playing Game of Happy Fortune.
Play now (Y/N)? Y                         
=================================================
Game 1:
Your roll is 2. 
Play again!
-------------------------------------------------
Play now (Y/N)? Y
Your roll is 4.
You won NT$100.
Play now (Y/N)? Y
=================================================
Game 2:
Your roll is 6. 
Thanks for your play!
Play more (Y/N)? Y
=================================================
Add game ( $50 for each play) : 1
Number of plays: 1                         
Total pay: 150                                
Thanks for your playing Game of Happy Fortune.
Play now (Y/N)? Y                        
=================================================
Game 3:
Your roll is 3.
Thanks for your play!
Play now (Y/N)? N
=================================================
Rita! 
You spent NT $150 and won NT $100.
=================================================
Quit the game (Y/N)? N
=================================================
Welcome to the Game of Happy Fortune!
The fortune is as follows:
-------------------------------------------------
...
...
=================================================
Quit the game (Y/N)? Y
=================================================
Thanks for playing!

*/  
