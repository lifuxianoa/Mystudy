#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, m, c, count=0;

    while(scanf("%d %d %d", &n, &m, &c))
    {
        if(n == 0 && m == 0 && c == 0)
        {
            break;
        }

        int *dev = (int*)malloc(sizeof(int) * n);
        char *dev_stat = (char *)malloc(sizeof(char)*n);
        int i, op, sum=0, max=0;

        memset(dev, 0, sizeof(int)*n);
        memset(dev_stat, 0, sizeof(char)*n);
        count++;

        for(i=0; i<n; i++)
        {
            scanf("%d", dev+i);
        }

        for(i=0; i<m; i++)
        {
            scanf("%d", &op); 
            op--;

            if(dev_stat[op] == 0)
            {
                sum += dev[op];
                dev_stat[op] = 1;
            }
            else if(dev_stat[op] == 1)
            {
                sum -= dev[op];
                dev_stat[op] = 0;
            }

            if(sum > max)
            {
                max = sum;
            }
        }

        printf("Sequence %d\n", count);
        if(max > c)
        {
            printf("Fuse was blown.\n");
        }
        else
        {
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n", max);
        }
        printf("\n");

        free(dev);
        free(dev_stat);
    }
    return 0;
}

