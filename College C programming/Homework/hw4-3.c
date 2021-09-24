//�ɦW:hw4-3.c
//�sĶ��:Dev-c++
//���:2011/12/16 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu() {  //���إؿ� 
printf("=================================================\n\
Welcome to the Game of Happy Fortune!\n\
The fortune is as follows:\n\
-------------------------------------------------\n\
1: �Q�z�������u�j�j�ЦY�K��!\n\
2: �Q�a���֤k�F�]�R�y���a��!\n\
3: ���[�J���W�ͮ{�|,��o�U�Ǫ�1000��!\n\
4: �J�����~�},�Q�r�F�@�f,���k�s!\n\
5: �M�C��ñ�q����,�����]�k�֤k!(�A���@��)\n\
6: �Ѷ}���������������D,��F�����m,��o5000��!\n\
7: �h�ݤ���`�`LIVE CASTLE 2011 KING'S NIGHT,QUEEN'S NIGHT,�������F!\n\
8: �M�ˤ��[.���J�l.�p�M�M���±N�j��,��F3000��!\n\
9: �~�J���a�q,�ܦ��Һ��C�n�f������!\n\
10: �b�߻A�����u,��o2000��!\n\
11: �o��s�����ФJ�����U!(�A���@��)\n\
12: ��۪��ꨵ�j�t�X,�Ҷ��쯫������µ�O1000��\n\
=================================================\n\n");
}
int roll(int sum){//���Ͷüƪ��禡 
	int option;
	option=rand()%12+1;
	printf("�Y�X�F�ﶵ:%d\n",option);
	roll_option(option,sum);//��üƭȶǤJ���ت��禡 
}
int roll_option(int option,int sum){//���ت��禡
    static int sum1=0;
	switch(option){
    case 1:printf("�Q�z�������u�j�j�ЦY�K��!\n");break;
    case 2:printf("�Q�a���֤k�F�]�R�y���a��!\n");break;
    case 3:printf("���[�J���W�ͮ{�|,��o�U�Ǫ�1000��!\n");
           sum+=1000;
	       break;
    case 4:printf("�J�����~�},�Q�r�F�@�f���k�s!\n");
           sum-=sum;
	       break;
    case 5:printf("�M�C��ñ�q����,�����]�k�֤k!(�A���@��)!\n");
           roll(sum);
	       break;
    case 6:printf("�Ѷ}���������������D,��F�����m,��o5000��!\n");
           sum+=5000;
	       break;
    case 7:printf("�h�ݤ���`�`LIVE CASTLE 2011 KING'S NIGHT,QUEEN'S NIGHT,�������F!\n");
	       sum-=sum;
		   break;
    case 8:printf("�M�ˤ��[.���J�l.�p�M�M���±N�j��,��F3000��!\n");
	       sum-=3000;
		   break;     
    case 9:printf("�~�J���a�q,�ܦ��Һ��C�n�f������!\n");
	       break;
    case 10:printf("�b�߻A�����u,��o2000��!\n");
            sum+=2000; 
	        break;
    case 11:printf("�o��s�����ФJ�����U!(�A���@��)\n");
	       roll(sum);
	       break;
    case 12:printf("��۪��ꨵ�j�t�X,�Ҷ��쯫������µ�O1000��!\n");
	        sum+=1000; 
			break;			   		
    }
	sum1=sum1+sum;

	return sum1;//�`���B 
	
}

int main() {
  
  srand(time(NULL));
  int pay=0,sum=0,x=0,i=0; //��O ���� 
  static int games;//�C������
  char a,a1,a2,a3;           
  //�O�_�{�b�� �O�_�i��U�@�� �W�[�C������ �O�_�i��U�@�� 
  do{ 
  menu(); 
  do{
  printf("�n���X���C�� (���@��100��):");
  scanf("%d",&games);
  //printf("��������:%d\n",games);
  getchar();
  pay+=100*games;//�`��O 
  printf("��O:%d\n",pay);
  printf("�P�§A���C��,���A���o�r��\n");
  printf("�O�_�{�b��(Y/N)?\n");
  scanf("%c",&a);
  getchar();  
  if(a=='y' || a=='Y') {//�O�_�{�b��
      x=1;
	  do{
		i++;//�ĴX��
		printf("�C��:%d\n",i);
		if(games==1)printf("\n�A��F%d and won NT $%d\n\n",pay,roll(sum));
		
	    if(games >= x){
		  ++x;//����üƨ禡�]�X��
		  roll(sum);//�üƨ禡					
		  printf("�O�_�{�b��(Y/N)?\n");
          scanf("%c",&a1);
          getchar();
		}
		 
      }while((a1=='y'||a1=='Y') &&  games >= x);//�O�_�i��U�@��
} 

  printf("\n");  
  printf("Play more (Y/N)?");
  scanf("%c",&a2);
  getchar();
  printf("\n");
			
}while(a2=='Y'||a2=='y');//�W�[�C������
  printf("\n�A��F%d and won NT $%d\n\n",pay,roll(sum));
  i=0;
  printf("�O�_���}�C��(Y/N)?");
  scanf("%c",&a3);
  getchar();
}while(a3=='N'||a3=='n');
printf("�P�§A���C��!\n\n");

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
