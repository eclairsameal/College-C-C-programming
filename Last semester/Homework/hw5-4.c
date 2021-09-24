//檔名:hw5-4.c
//編譯器:Dev-c++
//日期:2011/12/28 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(){
  srand(time(NULL));
  char name[50];//玩家姓名 
  char select, more, ans;  //電腦\玩家選擇   是否多玩   是否再玩  
  int ticket=0, ticketsum = 0;//票 票的總和 
  int number[50][6]={0}, i, all = 0,k;//選號 
  int lottery_result[0][6]={0}, j,star=0;//樂透號碼 
  int money=0;//贏多少 
  do{
	printf("=================================================\n");
    printf("Welcome to the Happy Lottery Game!\n");
	printf("Your name:");
	scanf("%s",&name);
	printf("%s, welcome to the game!\n", name);
    
	do {//判斷是否多玩
	  printf("=================================================\n");
      printf("Enter the number of tickets you want to buy: ");
      scanf("%d",&ticket);
	  ticketsum=ticketsum+ticket;//紀錄票的總和 
      getchar();
	  
	  printf("Computer or Self select (C/P)?\n");		
	  scanf("%c",&select);//電腦\玩家選擇
	  getchar();
        if(select== 'c' || more == 'C')//電腦選號 
		{
          printf("Computer select\n");
          for(i = 0 ; i < ticket ; i++)//控制電腦選幾次 
		    {			  	
		      for(k = 0 ; k < 6 ; k++)//控制電腦選六個號碼 
			    {				  
			      number[all][k] = rand()%49 + 1;//電腦亂數選六個號碼		    
			      printf("%d  ",number[all][k]);//列印電腦選的六個號碼		
		        }
		    all++;//紀錄是第幾組號碼 
		    printf("\n");
		    }  
		}                  
        if(select== 'p' || more == 'P')
		  {//玩家選號 
            printf("Self select\n");         
            for(i = 0 ; i < ticket ; i++)//控制玩家選幾次 
		      {
				printf("Select  6 numbers: ");
			    for(k = 0 ; k < 6 ; k++)//控制玩家選六個號碼			
			      {									  
		            scanf("%d",&number[all][k]); 
		          }
		          getchar();
			    all++;//紀錄是第幾組號碼 
		        printf("\n");	
		      }	
		  }		   
	  printf("=================================================\n");//花費清單 
	  printf("%s is Receipt:\n",name);
	  printf("Total pay:%d\n",ticketsum*50);
	
	  printf("Play more (Y/N)? ");
	  scanf("%c", &more);//是否多玩
	  getchar();
	
     } while (more == 'Y' || more == 'y');//判斷是否多玩
    printf("\nThe lottery result is:\n");
    printf("%d\n",all);
    for( j = 0 ; j < 6 ; j++ )
	  {
        lottery_result[0][j]=(rand()%49)+1;//亂數產生樂透號碼
        printf("%d  ",lottery_result[0][j]);//列印樂透號碼
	  }
	  printf("\n");
	  //判斷是否中獎 
    for(i = 0 ; i < all ; i++)//控制第幾組號碼
	   {
		  //star=0;//紀錄符合幾個號碼 
		  for(j = 0 ; j < 6 ; j++)//控制第幾個號碼
		    {
			  for(k = 0 ; k < 6 ; k++)//控制樂透的第幾個號碼
			    {
			      if(number[i][j] == lottery_result[0][k])
			      star++;
			    }
			    
			}
		   if(star == 3)//符合3幾個號碼
		     {
			    printf("Rita! Congratulations! You won 3 stars.\n");
			    star=0;
			    money+=200;
			 }
			if(star == 4)//符合4幾個號碼
		      {
			    printf("Rita! Congratulations! You won 4 stars.\n");
			    star=0;
			    money+=5000;
			  }
			if(star == 5)//符合5幾個號碼
		      {
			    printf("Rita! Congratulations! You won 5 stars.\n");
			    star=0;
			    money+=10000000;
			  }
			if(star == 6)//符合6幾個號碼
		      {
			    printf("Rita! Congratulations! You won 6 stars.\n");
			    star=0;
			    money+=100000000;
			  } 	  
	   }
        printf("You spent NT $%d and won NT $%d\n",(ticketsum*50),money);
        ticketsum = 0;
        money = 0;
        all = 0;
		printf("=================================================\n");
        printf("Quit the game (Y/N)?\n");
        scanf("%c",&ans);
        getchar();
  }while ( ans == 'n' || ans == 'N');//判斷是否再玩
  system("pause");
}

/*Write a program to simulate a lottery game. The rule is as follows:
1.A lottery ticket cost NT $50.
2.The player can pick six numbers from 1 to 49. 
    6 stars: The selected 6 numbers are same as the 6 lottery numbers. - NT $100,000,000 
    5 stars: The selected 5 numbers are in the 6 lottery numbers. - NT $10,000,000 
    4 stars: The selected 4 numbers are in the 6 lottery numbers. - NT $5,000 
    3 stars: The selected 3 numbers are in the 6 lottery numbers. - NT $200
  1.Display a welcome message to the game. A player enters her or his name.
  2.A player can select the number of tickets the player wants to buy and decide if the computer selects the numbers or the player selects the numbers.
  3.A player enters the numbers or the computer selects the numbers based on the player's decision.
  4.Print the receipt.
  5.The player can choose to buy more tickets or not.
  6.Show the lottery result.
  7.Calculate how much the player spends and wins.
  8.The player can choose to continue a new game.
A possible run could look like as follows:
 
=================================================
Welcome to the Happy Lottery Game!
Your name: Rita
Rita, welcome to the game!
=================================================
Enter the number of tickets you want to buy: 2
Computer or Self select (C/P)? P
Select numbers: 17 2 6 22 32 42
Select numbers: 10 6 12 7 28 46
-------------------------------------------------
Rita's Receipt:
Total pay: 100
Thanks for your playing Happy Lottery.
=================================================
Play more (Y/N)? Y
=================================================
Enter the number of tickets you want to buy: 1
Computer or Self select (C/P)? P
Select numbers: 33 7 18 26 45 36
-------------------------------------------------
Rita's Receipt:
Total pay: 50
Thanks for your playing Happy Lottery..
=================================================
Play more (Y/N)? N
The lottery result is:
3 7 12 28 38 47
Rita! Congratulations! You won 3 stars.
You spent NT $150 and won NT $200.
=================================================
Quit the game (Y/N)? N
=================================================
Welcome to the lottery game!
Your name: Mary
Rita, welcome to the game!
=================================================
...
...
=================================================
Quit the game (Y/N)? Y
=================================================
Thanks for playing!
*/
