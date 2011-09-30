#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int map[] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
#define M 10000000
int number[M];

int main()
{
    int i, j;
    int n;
    char buff[200];
    int sum = 0;

    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        memset(buff, 0, 200);
        scanf("%s", buff);
        j = 0;
        sum = 0;
        while(buff[j] != '\0')
        {
            if(buff[j] >= 'A' && buff[j] <= 'Z')
            {
                sum = sum * 10 + map[buff[j]-'A'];
            }
            else if(buff[j] >= '0' && buff[j] <= '9')
            {
                sum = sum * 10 + buff[j] - '0';
            }
            j++;
        }

        number[sum]++;
    }

    sum = 0;
    for(i = 0; i < M; i++)
    {
        if(number[i] > 1)
        {
            sum++;
            printf("%03d-%04d %d\n", i / 10000, i % 10000, number[i]);
        }
    }
    if(sum == 0)
    {
        printf("No duplicates.\n");
    }

    return 0;
}

