//�ɦW:hw2-5.c
//�sĶ��:Dev-C++
//���:2010/10/3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int pm=100,cm=100;         //player'swager,computer's wager
    int n,i,pn=0,pnsum=0;     //dice number,�üƭ�,�üƭ�sum(player)
	int j,cn=0,cnsum=0;       //dice number,�üƭ�,�üƭ�sum(computer)
	int pw=0,cw=0;           //Ĺ������
	char option = 'Y';
    srand(time(0));
do{                           //����b���@���C��
    
	printf("Welcome to the dice game!\n\n");
    printf("player'swager:%d\n",pm);
    printf("computer's wager:%d\n\n",cm);


do{                          //�����~��C��
while(pw!=2 && cw!=2){
printf("Enter the number of dices to roll:");

do{    
    scanf("%d",&n);
    if(n<=0)printf("Try again:");
    //�����l�Ƥ�<=0
}while(n<=0);
    printf("Roll the dice\n");
    printf("Player:");
	for(i=1;i<=n;i++)        //Player��l���ü�
	{
	pn=rand()%6+1;
	printf("%d  ",pn);
	pnsum+=pn;               //Player��l���üƪ��`�M
	    }
	//printf("%d",pnsum);
	printf("\ncomputer:");
	for(j=1;j<=n;j++)       //computer��l���ü�
	{
	cn=rand()%6+1;
	printf("%d  ",cn);
	cnsum+=cn;             ////computer��l���üƪ��`�M
	    }
	//printf("%d",cnsum);
	    if(pnsum>cnsum)
	    {   
            pnsum=0;
            cnsum=0;
			pw++;
			if(pw==2)printf("\nPlayer wins the set\n");
		    else printf("\nPlayer wins \n");
		    
		    }
		if(pnsum<cnsum)
	    {
		    pnsum=0;
            cnsum=0;
            cw++;
		    if(cw==2)printf("\ncomputer wins the set\n");
		    else printf("\ncomputer wins \n");
		    }
		if(pnsum==cnsum && pnsum!=0 && cnsum!=0)     //�����
		{
            pnsum=0;
            cnsum=0;
			printf("\nNo winner. Try again!\n");
			}
}
	if(pw==2)                   //Player�p�GĹ�⦸
	{
        pm=pm+20;              //��Ĺ��������
        cm=cm-20;
        pw=0;                  //�Ͽ�Ĺ�������k�s
        cw=0;
        
	}
	if(cw==2)                  //computer�p�GĹ�⦸
	{
        pm=pm-20;             //��Ĺ��������
        cm=cm+20;
        pw=0;                //�Ͽ�Ĺ�������k�s
        cw=0;
    }
	
    
    printf("player'swager:%d\n",pm);
    printf("computer's wager:%d\n\n",cm);
    printf("=================================================\n");
    printf("Continue (Y/N)? ");
    getchar();
    scanf("%c", &option);
} while (option == 'Y' || option == 'y');
    printf("==================== Game Over! ==================\n");
    printf("Start a new game (Y/N)? ");
    getchar();
    scanf("%c", &option);
    pm=100;                    //�ϱo�b���@��������^�k��@��
    cm=100;
} while (option == 'Y' || option == 'y');
       
    
 printf("Over the game thank you\n");
    system("pause");
}

/*
Write a program of a dice game.

1.The computer and the player are given 100 dollars wager.
2.The player decides the number of dices to roll (It should be larger than 0).
3.The computer and the player roll the dices.
4.Whoever has the larger total is the winer.
5.Whoever wins twice wins a set of game. The winner gains the wager of 20 dollars and the loser looses the wager of 20 dollars.
6.A player can keep playing the game or quit the game.
7.The game is over when the player or the computer looses all the wager.
8.Once the game is over, the player can start a new game or quit the game.
A possible run may look like:

**************************************************
Welcome to the dice game!
**************************************************
Player's wager: 100
Computer's wager: 100
Enter the number of dices to roll (>= 1): 0
Try again! Enter the number of dices to roll: 2
Roll the dice (Push any key to roll)?
Player: 3 3
Computer: 2 6
=> Computer wins once.
Roll the dice (Push any key to roll)?
Player: 2 5
Computer: 3 4
=> No winner. Try again!
Roll the dice (Push any key to roll)?
Player: 2 6
Computer: 1 3
=> Player wins once.
Roll the dice (Push any key to roll)?
Player: 4 6
Computer: 3 5
=> Player wins the set.
Player's wager: 120
Computer's wager: 80
==================================================
Continue (Y/N)? Y
Enter the number of dices to roll: 3
Roll the dice (Push any key to roll)?
Player: 3 3 6
Computer: 2 6 5
=> Computer wins once.
.....
.....
Player's wager: 200
Computer's wager: 0
==================== Game Over! ==================
Start a new game (Y/N)? Y
....
*/ 
