//檔名:hw2-2.c
//編譯器:Dev-C++
//日期:2010/10/3

#include <stdio.h>
#include <stdlib.h>

main()
{
int i, j, n,g, sum = 0;

    printf("Enter n: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)        //控制層行數
	{
         for (j = 1; j <= n - i; j++) printf(" ");  //印出空白
         for (j = 1; j <= 2 * i - 1; j++)
		 {
         printf("%d",j);
         }
         printf("\n");
    }
    for(j=n;j>=1;j--)
	    {
        for(g=1;g<n;g++){printf(" ");
	    }
    printf("%d\n",j);
    }
system("pause");
}
/*Enter n: 1
1
Enter n: 2
 1
123
 1
Enter n: 3
  1
 123
12345
  2
  1
Enter n: 4
   1
  123
 12345
1234567
   3
   2
   1
...*/
