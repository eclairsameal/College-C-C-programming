//檔名: hw-1-1.c
//編譯器: Dev-C++
//日期:2011/10/12
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int a,b,c,e;  // 商品  投入的錢  缺額  多投入的錢
    printf("serial killers of Vending Machine:\n");//商品
    printf("1:Jason Voorhees - 100    2:Freddy Krueger - 90\n");
    printf("3:Mychael Myers - 70      4:Hannibal Lecter - 65\n");
    printf("5:Jigsaw - 50             6:Jack The Ripper - 5\n");
    printf("7:Jeffery Dahmer - 35     8:Ted Bundy - 40\n");
    printf("9:Richard Ramirez - 20    10:Peter Sutcliffe - 15\n");
    printf("Selection:\n");

    scanf("%d",&a);

if (a==1)// 1:Jason Voorhees - 100
{
    printf("請投入100元:\n");
    scanf("%d",&b);
    c=100-b;
    e=b-100;
        if (b<100)
    {printf("少投了%d元\n",c);}
        if (b==100)
    {printf("得到Jason Voorhees");}
        if (b>100)
    {printf("找您%d元",e);}
}
  if (a==2)// 2:Freddy Krueger - 90
{
    printf("請投入90元:\n");
    scanf("%d",&b);
    c=90-b;
    e=b-90;
        if (b<90)
    {printf("少投了%d元\n",c);}
        if (b==90)
    {printf("得到Freddy Krueger");}
        if (b>90)
    {printf("找您%d元",e);}
}
  if (a==3)// 3:Mychael Myers - 70
{
    printf("請投入70元:\n");
    scanf("%d",&b);
    c=70-b;
    e=b-70;
        if (b<70)
    {printf("少投了%d元\n",c);}
        if (b==70)
    {printf("得到Mychael Myers");}
        if (b>70)
    {printf("找您%d元",e);}
}
  if (a==4)//  4:Hannibal Lecter - 65
{
    printf("請投入65元:\n");
    scanf("%d",&b);
    c=65-b;
    e=b-65;
        if (b<65)
    {printf("少投了%d元\n",c);}
        if (b==65)
    {printf("得到Hannibal Lecter");}
        if (b>65)
    {printf("找您%d元",e);}
}
  if (a==5)// 5:Jigsaw - 50
{
    printf("請投入50元:\n");
    scanf("%d",&b);
    c=50-b;
    e=b-50;
        if (b<50)
    {printf("少投了%d元\n",c);}
        if (b==50)
    {printf("得到Jigsaw");}
        if (b>50)
    {printf("找您%d元",e);}
}
  if (a==6)//6:Jack The Ripper - 5
{
    printf("請投入5元:\n");
    scanf("%d",&b);
    c=5-b;
    e=b-5;
        if (b<5)
    {printf("少投了%d元\n",c);}
        if (b==5)
    {printf("得到Put coins");}
        if (b>5)
    {printf("找您%d元",e);}
}
  if (a==7)// 7:Jeffery Dahmer - 35
{
    printf("請投入35元:\n");
    scanf("%d",&b);
    c=35-b;
    e=b-35;
        if (b<35)
    {printf("少投了%d元\n",c);}
        if (b==35)
    {printf("得到Jeffery Dahmer");}
        if (b>35)
    {printf("找您%d元",e);}
}
  if (a==8)// 8:Ted Bundy - 40
{
    printf("請投入40元:\n");
    scanf("%d",&b);
    c=40-b;
    e=b-40;
        if (b<40)
    {printf("少投了%d元\n",c);}
        if (b==40)
    {printf("得到Ted Bundy");}
        if (b>40)
    {printf("找您%d元",e);}
}
  if (a==9)// 9:Richard Ramirez - 20
{
    printf("請投入20元:\n");
    scanf("%d",&b);
    c=20-b;
    e=b-20;
        if (b<20)
    {printf("少投了%d元\n",c);}
        if (b==20)
    {printf("得到Richard Ramirez");}
        if (b>20)
    {printf("找您%d元",e);}
}
  if (a==10)// 10:Peter Sutcliffe - 15
{
    printf("請投入15元:\n");
    scanf("%d",&b);
    c=15-b;
    e=b-15;
        if (b<15)
    {printf("少投了%d元\n",c);}
        if (b==15)
    {printf("得到Peter Sutcliffe");}
        if (b>15)
    {printf("找您%d元",e);}
}


    system("pause");
    return 0;
    }
    
/*
1.(14 points) Write a program to simulate a vending machine.
(3 points) List the items and price Your vending machine should have at least 10 items. Each student should choice different items to sell.
(3 points) The customer first selects an item.
(3 points) The customer put coins into the machine.
(5 points) The machine discharges the selected item and give you the change if the coins are enough, otherwise indicates there is not enough money.
A possible run may look like:
List of Items of Vending Machine:
1: Water - 15 2: Coke -  15 3: 7 UP - 15 4: Gatorade - 10 5: Woolong Tea - 10
6: Sprite -15 7: Funta - 15 8: Coke - 15 9: Lemonade - 15 10: Root Beer - 15
Selection => 2
Put coins: 20
You got a can of coke.
Return: 5

List of Items of Vending Machine:
1: Water - 15 2: Coke -  15 3: 7 UP - 15 4: Gatorade - 10 5: Woolong Tea - 10
6: Sprite -15 7: Funta - 15 8: Coke - 15 9: Lemonade - 15 10: Root Beer - 15
Selection => 6
Put coins: 10
Not enough. Put more coins.
Put coins: 5
You got a bottle of Sprite.	
*/ 
