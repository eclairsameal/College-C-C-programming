//�ɦW:hw5-4.c
//�sĶ��:Dev-c++
//���:2011/12/28 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(){
  srand(time(NULL));
  char name[50];//���a�m�W 
  char select, more, ans;  //�q��\���a���   �O�_�h��   �O�_�A��  
  int ticket=0, ticketsum = 0;//�� �����`�M 
  int number[50][6]={0}, i, all = 0,k;//�︹ 
  int lottery_result[0][6]={0}, j,star=0;//�ֳz���X 
  int money=0;//Ĺ�h�� 
  do{
	printf("=================================================\n");
    printf("Welcome to the Happy Lottery Game!\n");
	printf("Your name:");
	scanf("%s",&name);
	printf("%s, welcome to the game!\n", name);
    
	do {//�P�_�O�_�h��
	  printf("=================================================\n");
      printf("Enter the number of tickets you want to buy: ");
      scanf("%d",&ticket);
	  ticketsum=ticketsum+ticket;//���������`�M 
      getchar();
	  
	  printf("Computer or Self select (C/P)?\n");		
	  scanf("%c",&select);//�q��\���a���
	  getchar();
        if(select== 'c' || more == 'C')//�q���︹ 
		{
          printf("Computer select\n");
          for(i = 0 ; i < ticket ; i++)//����q����X�� 
		    {			  	
		      for(k = 0 ; k < 6 ; k++)//����q���碌�Ӹ��X 
			    {				  
			      number[all][k] = rand()%49 + 1;//�q���üƿ碌�Ӹ��X		    
			      printf("%d  ",number[all][k]);//�C�L�q���諸���Ӹ��X		
		        }
		    all++;//�����O�ĴX�ո��X 
		    printf("\n");
		    }  
		}                  
        if(select== 'p' || more == 'P')
		  {//���a�︹ 
            printf("Self select\n");         
            for(i = 0 ; i < ticket ; i++)//����a��X�� 
		      {
				printf("Select  6 numbers: ");
			    for(k = 0 ; k < 6 ; k++)//����a�碌�Ӹ��X			
			      {									  
		            scanf("%d",&number[all][k]); 
		          }
		          getchar();
			    all++;//�����O�ĴX�ո��X 
		        printf("\n");	
		      }	
		  }		   
	  printf("=================================================\n");//��O�M�� 
	  printf("%s is Receipt:\n",name);
	  printf("Total pay:%d\n",ticketsum*50);
	
	  printf("Play more (Y/N)? ");
	  scanf("%c", &more);//�O�_�h��
	  getchar();
	
     } while (more == 'Y' || more == 'y');//�P�_�O�_�h��
    printf("\nThe lottery result is:\n");
    printf("%d\n",all);
    for( j = 0 ; j < 6 ; j++ )
	  {
        lottery_result[0][j]=(rand()%49)+1;//�üƲ��ͼֳz���X
        printf("%d  ",lottery_result[0][j]);//�C�L�ֳz���X
	  }
	  printf("\n");
	  //�P�_�O�_���� 
    for(i = 0 ; i < all ; i++)//����ĴX�ո��X
	   {
		  //star=0;//�����ŦX�X�Ӹ��X 
		  for(j = 0 ; j < 6 ; j++)//����ĴX�Ӹ��X
		    {
			  for(k = 0 ; k < 6 ; k++)//����ֳz���ĴX�Ӹ��X
			    {
			      if(number[i][j] == lottery_result[0][k])
			      star++;
			    }
			    
			}
		   if(star == 3)//�ŦX3�X�Ӹ��X
		     {
			    printf("Rita! Congratulations! You won 3 stars.\n");
			    star=0;
			    money+=200;
			 }
			if(star == 4)//�ŦX4�X�Ӹ��X
		      {
			    printf("Rita! Congratulations! You won 4 stars.\n");
			    star=0;
			    money+=5000;
			  }
			if(star == 5)//�ŦX5�X�Ӹ��X
		      {
			    printf("Rita! Congratulations! You won 5 stars.\n");
			    star=0;
			    money+=10000000;
			  }
			if(star == 6)//�ŦX6�X�Ӹ��X
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
  }while ( ans == 'n' || ans == 'N');//�P�_�O�_�A��
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
