//郎:hw5-2.c
//絪亩竟:Dev-c++
//ら戳:2011/1/3 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 30
void generate_array( int n, int a[][SIZE] )//玻ネ睹计
{
  int i,j;
	  for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
          a[i][j] = rand() % ((n * n)/2) + 1;
}
void function(int n, int a[SIZE][SIZE],int b[SIZE][SIZE] )// 
{
  int i,j,k,q,t;//北跑计
  char line[]= "+--";
  for(t=0;t<n;t++){printf("  %c",t+'a');}
  printf("\n");
  for(i=0;i<n;i++)
    { //printf("%d",i+1); 
	  for(j=0;j<n;j++)
		{
		  printf("%s",line);		  
		}
	  printf("+\n"); 
	  for(k=0;k<n;k++)
	    {
		 b[i][k]==0 ? printf("| %s","*"): printf("| %d",a[i][k]);//北*┪ 
		}
	  printf("|\n");
	  
	}
  for(q=1;q<=n;q++)printf("+--");
  printf("+\n"); 
}

main() {
  int n,c;//n 產匡计  
  int i,j,k,your_points=0,Computer_points=0;//北跑计  產だ计  筿福だ计 
  int a[SIZE][SIZE],b[SIZE][SIZE]={0},s=0;
  char d;//產匡计 
  char ans,game;//计┪案计  Ω 
  srand(time(NULL));
do{ 
  printf("Enter n:");
  scanf("%d",&n);
  generate_array(n, a);//玻ネ睹计
  function(n,a,b);//陆礟***** 
  for(i=0;i<n*n;i++)
    {
      printf("Select a card:");
      scanf("%d%c",&c,&d);
      getchar();
      b[c-1][d-'a']=1;      
      //function(n,a,b);//陆礟
      s=a[c-1][d-'a'];
      printf("Odd or Even (O/E)?\n");
      scanf("%c",&ans);//计┪案计
       getchar();
       function(n,a,b);//陆礟
      if(ans == 'o' || ans == 'O')//瞦计
	    {
		  if(s%2 == 0)//案计
		    {
			  printf("You guess wrong\n");//瞦岿
			  Computer_points+=s;//瞦岿筿福眔だ
			  printf("your points%:%d\n",your_points);
			  printf("Computer points:%d\n",Computer_points);			  
		    }
		  if(s%2 == 1)//计
		    {
			  printf("You guess correct\n");//瞦癸
			  your_points+=s;//瞦癸產眔だ 
			  printf("your points%:%d\n",your_points);
			  printf("Computer points:%d\n",Computer_points);			  
		    }
	    }
	  if(ans == 'e' || ans == 'E')//瞦案计
	    {
		  if(s%2 == 1)//计
		    {
			  printf("You guess wrong\n");//瞦岿 
			  Computer_points+=s;//瞦岿筿福眔だ 
			  printf("your points%:%d\n",your_points);
			  printf("Computer points:%d\n",Computer_points);			  
		    }
		  if(s%2 == 0)//案计
		    {
			  printf("You guess correct\n");//瞦癸 
			  your_points+=s;//瞦癸產眔だ
			  printf("your points%:%d\n",your_points);
			  printf("Computer points:%d\n",Computer_points);			  
		    }
	    }
}
  if(your_points > Computer_points)printf("Congratulations! You won the game!\n");//產墓
  if(your_points < Computer_points)printf("You lose!\n");//筿福墓 
  if(your_points == Computer_points)printf("Draw!\n");//キも 
  printf("Start a new game (Y/N)?\n");//琌Ω 
  scanf("%c",&game);
  getchar();
  your_points=0;//耴箂  
  Computer_points=0;//耴箂
  for(j=0;j<n;j++){for(k=0;k<n;k++)b[j][k]=0;}//耴箂
  
}while(game == 'y' || game == 'Y');   
   printf("Thanks for playing!");
  system("pause");    
}
/* Write a small guessing game.
1.Write a function that passes n, generates a board of n by n, and randomly fills with the pairs of 1 to n2/2 if n is even or n2/2 + 1 if n is odd.
2.Write a function that prints the board shown as below. In the beginning the numbers are hidden. After the player selects numbers, the numbers are exposed successively.
3.Write the main function to use the above functions.
  1.The player selects a number. A number has been selected cannot be reselected.
  2.The player guess if the number is odd or even. If guessing right, the player wins the points, otherwise, the computer wins the points.
  3.The game is over until no number can be selected and the result is announced.
  4.The player can start a new game or leave the game.
A possible run may look like:
Enter n: 3
     a  b  c 
   +--+--+--+
 1 | *| *| *|
   +--+--+--+
 2 | *| *| *|
   +--+--+--+
 3 | *| *| *|
   +--+--+--+
Your choice => 2a
Odd or Even (O/E)? E
You guess wrong.
Your Points: 0
Computer's Points: 3
     a  b  c 
   +--+--+--+
 1 | *| *| *|
   +--+--+--+
 2 | 3| *| *|
   +--+--+--+
 3 | *| *| *|
   +--+--+--+
Your choice => 3c
Odd or Even (O/E)? E
You guess correct.
Your Points: 4
Computer's Points: 3
     a  b  c 
   +--+--+--+
 1 | *| *| *|
   +--+--+--+
 2 | 3| *| *|
   +--+--+--+
 3 | *| *| 4|
   +--+--+--+
...
     a  b  c 
   +--+--+--+
 1 | 1| 2| 5|
   +--+--+--+
 2 | 3| 4| 3|
   +--+--+--+
 3 | 2| 1| 4|
   +--+--+--+
...
Your Points: 15
Computer's Points: 10 
Congratulations! You won the game! 
Start a new game (Y/N)? Y
=============================================================
Enter n: 4
     a  b  c  d 
   +--+--+--+--+
 1 | *| *| *| *|
   +--+--+--+--+
 2 | *| *| *| *|
   +--+--+--+--+
 3 | *| *| *| *|
   +--+--+--+--+
 4 | *| *| *| *|
   +--+--+--+--+ */ 
