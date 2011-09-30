#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int score(int a, int b)
{
    int dis = a - b;
    int ret = 0;

    if(dis == 0)
    {
        ret = 0;
    }
    else if(dis == 1 )
    {
        if(a==2 && b == 1)
        {
            ret = -6;
        }
        else
        {
            ret = -(a + b);
        }
    }
    else if(dis == -1)
    {
        if(a==1 && b == 2)
        {
            ret = 6;
        }

        ret = a + b;
    }
    else if(dis > 0)
    {
        ret = a;
    }
    else if(dis < 0)
    {
        ret = -b;
    }

    return ret;
}

int main()
{
    int num, *cardA, *cardB, pointA, pointB;
    int i, j, points, blank_flag = 0;;

    while(scanf("%d", &num))
    {
        if(num == 0)
        {
            break;
        }

        pointA = 0;
        pointB = 0;
        cardA = (int *)malloc(sizeof(int) * num);
        cardB = (int *)malloc(sizeof(int) * num);
        memset(cardA, 0, sizeof(int)*num);
        memset(cardB, 0, sizeof(int)*num);

            for(j=0; j<num; j++)
                scanf("%d", cardA+j);
        
            for(j=0; j<num; j++)
                scanf("%d", cardB+j);

        for(i=0; i<num; i++)
        {
            points = score(cardA[i], cardB[i]);
            if(points > 0)
            {
                pointA += points;
            }
            else if(points < 0)
            {
                pointB += -points;
            }
        }

        if(blank_flag == 1)
        {
            printf("\n");
        }
        printf("A has %d points. B has %d points.\n", pointA, pointB);
        blank_flag = 1;
        free(cardA);
        free(cardB);
        cardA = NULL;
        cardB = NULL;
    }
    return 0;
}

