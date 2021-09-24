//檔名:hw2-3.c
//編譯器:Dev-C++
//日期:2010/10/3
#include<stdio.h>
#include<stdlib.h>

int main(){
	int a,b,d;
	char ans = 'Y';
	
do {
    printf("遊戲開始\n");
    printf("1.機動六課   2.雛見澤村   3.六軒島   4.見瀧原町\n");
	printf("選擇你要去的地方:");
	scanf("%d",&a);
	
	if(a==1){
	printf("遇到奈葉、菲特\n奈葉：「Starlight Breaker」\n菲特：「Sprite Zanber」\n被冥王和死神的光束轟成渣！\n");
    scanf("%c", &ans);}
    

	if(a==2){
	printf("到達雛見村\n");
	printf("1.雛見澤大壩遺跡   2.園崎大宅   3.古手神社\n");
	printf("選擇你要去的地方:");
	scanf("%d",&b);
            if(b==1){
            printf("看到不該看的秘密，被可愛的禮奈和她親愛的柴刀，強制轉學了！\n");
            scanf("%c", &ans);
			}
            if(b==2){
            printf("被狂氣的詩音，腸流！\n");
            scanf("%c", &ans);
            }
            if(b==3){
            printf("到達古手神社\n");
			    printf("1.參加綿流祭   2.潛入刑具室\n");
			    printf("請問你要:");
                scanf("%d",&d);
                if(d==1){
                printf("參加一年一度的流綿祭，得到御社神羽入的祝福！哈嗚~哈嗚~！\n");
                scanf("%c", &ans);
                }
                if(d==2){
                printf("誤踏神社的禁地，觸怒御社神，雛見澤病L5病發身亡！\n");
                scanf("%c", &ans);
                }
				}
}
	            
    if(a==3){
	printf("到達六軒島\n");
	printf("1.右代宮家大殿   2.金藏的書房\n");
	printf("選擇你要去的地方:");
	scanf("%d",&b);
			if(b==1){
			printf("解開魔女的謎題，到達黃金鄉，得到魔女貝阿朵莉切的稱號和祕寶！\n");
            scanf("%c", &ans);
            }

			if(b==2){
			printf("尋找黃金鄉之人啊！剜頭殺之、剜胸殺之、剜腹殺之、剜足殺之，魔女復蘇，無人生還！\n");
            scanf("%c", &ans);
            }
}

	if(a==4){
	printf("跟丘比訂下契約，成為魔法少女！\n");
    scanf("%c", &ans);
    }

    printf("是否再玩一次 (Y/N)? ");
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
