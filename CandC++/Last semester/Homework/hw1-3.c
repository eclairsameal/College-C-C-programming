//�ɦW: hw1-3.c
//�sĶ��: Dev-C++
//���:2011/10/12
#include <stdio.h>
#include <stdlib.h>
int main(){
    int a,b,c,sum,d,e,f,sum0,g,sum1;
	//�ɬq  �j�H�H�� �p�ĤH�� �_����B
	//�j�H�馩    �p�ħ馩    3�H�馩   ���B  10�H�馩  �`���B
    
    printf("1.Weekday:    Adult:568   Children:368\n");
    printf("2.Weekend:    Adult:688   Children:468\n");
    printf("3.Star Light: Adult:488   Children:328\n");
    printf("��ܮɬq:");
    scanf ("%d",&a);

if (a==1){
        printf("�j�H�H��:");
        scanf ("%d",&b);
        printf("�p�ĤH��:");
        scanf ("%d",&c);
        sum=b*568+c*368;
        printf("�_����B:%d\n",sum);
        
        
            if (b+c>=3){
            d=b/3;
            e=(a%3+c)/3;
            f=d*568+e*368;
            printf("�馩:%d\n",f);
            sum0=sum-f;
            printf("���B:%d\n",sum0);
        }
                if (b+c>=10){
                g=sum0 * 5 / 100;
                printf("�馩(10�H):%d\n",g);
                sum1=sum0-g;
                printf("�`���B:%d\n",sum1);
             }
        
}
else if (a==2){
         printf("�j�H�H��:");
         scanf ("%d",&b);
         printf("�p�ĤH��:");
         scanf ("%d",&c);
         sum=b*688+c*468;
         printf("�_����B:%d\n",sum);
         
             if (b+c>=3){
             d=b/3;
             e=(b%3+c)/3;
             f=d*688+e*468;
             printf("�馩(3�H):%d\n",f);
             sum0=sum-f;
             printf("���B:%d\n",sum0);
         }
                 if (b+c>=10){
                 g=sum0 * 5 / 100;
                 printf("�馩(10�H):%d\n",g);
                 sum1=sum0-g;
                 printf("�`���B:%d\n",sum1);
             }
         
         
}
else if (a==3){
         printf("�j�H�H��:");
         scanf ("%d",&b);
         printf("�p�ĤH��:");
         scanf ("%d",&c);
         sum=b*488+c*328;
         printf("�_����B:%d",sum);
         
             if (b+c>=3 ){
             d=b/3;
             e=(a%3+c)/3;
             f=d*488+e*328;
             printf("�馩:%d\n",f);
             sum0=sum-f;
             printf("���I���B:%d\n",sum0);
         }
                 if (b+c>=10){
                 g=sum0 * 5 / 100;
                 printf("�馩(10�H):%d\n",g);
                 sum1=sum0-g;
                 printf("�`���B:%d\n",sum1);
             }
    
}  
  
    
    
system("pause");
return 0;
}

/*
Write a program that calculates the fee for an amusement park.
1.The fee for each person is shown as follows:
 	        Adult	Children
Weekday	    568	    368
Weekend	    688	    468
Star Light	488	    328

2.If 3 persons go together, then one is free. If there is a child, the discount fee is child's fee.
3.If more than 10 persons eat together, there is 5% discount.
  1.(3 points) Read the meal time, the number of adults and children.
  2.(9 points) Calculate the fee.
  3.(6 points) Print the receipt including discounts.
A possible run may look like:

1. Weekday 2. Weekend 3. Star Light: 1
Number of adults: 3
Number of children: 1
3 adults, 1 child
Original fee: 2072
Discount for three person promotion: 568  
Total fee: 1504
===========================================
1. Weekday 2. Weekend 3. Star Light: 2
Number of adults: 6
Number of children: 5
6 adults, 5 children
Original fee: 6468
Discount for three person promotion: 1844 (Two adults and one child)
Total fee: 4624
Discount for 10 persons: 231
Total fee: 4393
*/ 
