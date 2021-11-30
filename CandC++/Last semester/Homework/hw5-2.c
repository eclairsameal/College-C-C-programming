//�ɦW:hw5-2.c
//�sĶ��:Dev-c++
//���:2011/1/3 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 30
void generate_array( int n, int a[][SIZE] )//���Ͷüƭ�
{
  int i,j;
	  for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
          a[i][j] = rand() % ((n * n)/2) + 1;
}
void function(int n, int a[SIZE][SIZE],int b[SIZE][SIZE] )//��l 
{
  int i,j,k,q,t;//�����ܼ�
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
		 b[i][k]==0 ? printf("| %s","*"): printf("| %d",a[i][k]);//����L*�έ� 
		}
	  printf("|\n");
	  
	}
  for(q=1;q<=n;q++)printf("+--");
  printf("+\n"); 
}

main() {
  int n,c;//n�� ���a�諸�Ƥ@  
  int i,j,k,your_points=0,Computer_points=0;//�����ܼ�  ���a����  �q������ 
  int a[SIZE][SIZE],b[SIZE][SIZE]={0},s=0;
  char d;//���a�諸�ƤG 
  char ans,game;//�_�Ʃΰ���  �A���@�� 
  srand(time(NULL));
do{ 
  printf("Enter n:");
  scanf("%d",&n);
  generate_array(n, a);//���Ͷüƭ�
  function(n,a,b);//½�P***** 
  for(i=0;i<n*n;i++)
    {
      printf("Select a card:");
      scanf("%d%c",&c,&d);
      getchar();
      b[c-1][d-'a']=1;      
      //function(n,a,b);//½�P
      s=a[c-1][d-'a'];
      printf("Odd or Even (O/E)?\n");
      scanf("%c",&ans);//�_�Ʃΰ���
       getchar();
       function(n,a,b);//½�P
      if(ans == 'o' || ans == 'O')//�q�_��
	    {
		  if(s%2 == 0)//�Ȭ�����
		    {
			  printf("You guess wrong\n");//�q��
			  Computer_points+=s;//�q���q���o��
			  printf("your points%:%d\n",your_points);
			  printf("Computer points:%d\n",Computer_points);			  
		    }
		  if(s%2 == 1)//�Ȭ��_��
		    {
			  printf("You guess correct\n");//�q��
			  your_points+=s;//�q�缾�a�o�� 
			  printf("your points%:%d\n",your_points);
			  printf("Computer points:%d\n",Computer_points);			  
		    }
	    }
	  if(ans == 'e' || ans == 'E')//�q����
	    {
		  if(s%2 == 1)//�Ȭ��_��
		    {
			  printf("You guess wrong\n");//�q�� 
			  Computer_points+=s;//�q���q���o�� 
			  printf("your points%:%d\n",your_points);
			  printf("Computer points:%d\n",Computer_points);			  
		    }
		  if(s%2 == 0)//�Ȭ�����
		    {
			  printf("You guess correct\n");//�q�� 
			  your_points+=s;//�q�缾�a�o��
			  printf("your points%:%d\n",your_points);
			  printf("Computer points:%d\n",Computer_points);			  
		    }
	    }
}
  if(your_points > Computer_points)printf("Congratulations! You won the game!\n");//���aĹ
  if(your_points < Computer_points)printf("You lose!\n");//�q��Ĺ 
  if(your_points == Computer_points)printf("Draw!\n");//���� 
  printf("Start a new game (Y/N)?\n");//�O�_�A���@�� 
  scanf("%c",&game);
  getchar();
  your_points=0;//�k�s  
  Computer_points=0;//�k�s
  for(j=0;j<n;j++){for(k=0;k<n;k++)b[j][k]=0;}//�k�s
  
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
