//�ɦW:hw2-3.c
//�sĶ��:Dev-C++
//���:2010/10/3
#include<stdio.h>
#include<stdlib.h>

int main(){
	int a,b,d;
	char ans = 'Y';
	
do {
    printf("�C���}�l\n");
    printf("1.���ʤ���   2.�����A��   3.���a�q   4.���]���m\n");
	printf("��ܧA�n�h���a��:");
	scanf("%d",&a);
	
	if(a==1){
	printf("�J��`���B��S\n�`���G�uStarlight Breaker�v\n��S�G�uSprite Zanber�v\n�Q�ߤ��M�����������F����I\n");
    scanf("%c", &ans);}
    

	if(a==2){
	printf("��F������\n");
	printf("1.�����A�j����   2.��T�j�v   3.�j�⯫��\n");
	printf("��ܧA�n�h���a��:");
	scanf("%d",&b);
            if(b==1){
            printf("�ݨ줣�Ӭݪ����K�A�Q�i�R��§�`�M�o�˷R����M�A�j����ǤF�I\n");
            scanf("%c", &ans);
			}
            if(b==2){
            printf("�Q�g�𪺸֭��A�z�y�I\n");
            scanf("%c", &ans);
            }
            if(b==3){
            printf("��F�j�⯫��\n");
			    printf("1.�ѥ[���y��   2.��J�D���\n");
			    printf("�аݧA�n:");
                scanf("%d",&d);
                if(d==1){
                printf("�ѥ[�@�~�@�ת��y�����A�o��s�����ФJ�����֡I����~����~�I\n");
                scanf("%c", &ans);
                }
                if(d==2){
                printf("�~�񯫪����T�a�AĲ��s�����A�����A�fL5�f�o���`�I\n");
                scanf("%c", &ans);
                }
				}
}
	            
    if(a==3){
	printf("��F���a�q\n");
	printf("1.�k�N�c�a�j��   2.���ê��ѩ�\n");
	printf("��ܧA�n�h���a��:");
	scanf("%d",&b);
			if(b==1){
			printf("�Ѷ}�]�k�����D�A��F�����m�A�o���]�k�������������ٸ��M���_�I\n");
            scanf("%c", &ans);
            }

			if(b==2){
			printf("�M������m���H�ڡI���Y�����B��ݱ����B�渡�����B�樬�����A�]�k�_Ĭ�A�L�H���١I\n");
            scanf("%c", &ans);
            }
}

	if(a==4){
	printf("��C��q�U�����A�����]�k�֤k�I\n");
    scanf("%c", &ans);
    }

    printf("�O�_�A���@�� (Y/N)? ");
    scanf("%c", &ans);
    getchar();

}while (ans == 'y' || ans == 'Y');
system("pause");
}
/*
Write a program that simulates a treasure hunt game for One Piece. Your game should have at least 8 possibility. Each student should has her or his own map and upload the map. A map may look like as follows:

  1.(3 points) Draw your map.
  2.(9 points) Your game allows the player to choice the direction and the game stops until reach some destination.
  3.(3 points) Once the game is over, the player can decide to play again or not.
A possible run may look like:

Welcome to the map game!
Your Choice? (Left/Middle/Right) L
You get ice cream!
Play again? (Y/N) Y
Your Choice? (Left/Middle/Right) M
Your Choice? (Left/Middle/Right) L
Your Choice? (Left/Middle/Right) L
Your Choice? (Left/Middle/Right) R
Your Choice? (Left/Middle/Right) L
You find gold!
Play again? (Y/N) N

*/ 
