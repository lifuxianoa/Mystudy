#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *buff)
{
    char *head, *tail, *tmp;

    head = buff;
    tail = buff;
    while(*head != '\0')
    {
        while(*tail != ' ' && *tail != '\0')
        {
            tail++;
        }

        tmp = tail-1;
        while(tmp >= head)
        {
            printf("%c", *tmp);
            tmp--;
        }
    
        if(*tail == ' ')
        {
            printf(" ");
        }

        tail++;
        head = tail;
    }
    printf("\n");
}

int main()
{
    int N, n, i, j;
    char buff[1000];

    scanf("%d\n", &N);
    for(i=0; i<N; i++)
    {
        if(i>0)
        {
            printf("\n");
        }
        scanf("%d\n", &n);

        for(j=0; j<n; j++)
        {
            memset(buff, '\0', 1000);
            gets(buff);
            reverse(buff);
        }
    }
    return 0;
}

