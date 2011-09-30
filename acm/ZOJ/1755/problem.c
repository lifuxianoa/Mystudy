#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int dimensions[9][3];
    char names[9][9];
    int n, i;
    unsigned char average;
    char bully[9];
    char victim[9];

    while(scanf("%d", &n))
    {
        if(n == -1)
        {
            break;
        }

        for(i=0; i<n; i++)
        {
            memset(names[i], '\0', 9);
            scanf("%d %d %d %s\n", &dimensions[i][0], &dimensions[i][1], &dimensions[i][2], names[i]);
            printf("%d %d %d %s\n", &dimensions[i][0], &dimensions[i][1], &dimensions[i][2], names[i]);
        }

        average = 0;
        for(i=0; i<n; i++)
        {
            //printf("%c %c %c %s\n", &dimensions[i][0], &dimensions[i][1], &dimensions[i][2], names[i]);
            average += dimensions[i][0] * dimensions[i][1] * dimensions[i][2];
        }

        average /= n;
        printf("average = %d\n", average);

        for(i=0; i<n; i++)
        {
            if(dimensions[i][0] * dimensions[i][1] * dimensions[i][2] > average)
            {
                memset(bully, '\0', 9);
                memcpy(bully, names[i], 9);
            }
            else if(dimensions[i][0] * dimensions[i][1] * dimensions[i][2] < average)
            {
                memset(victim, '\0', 9);
                memcpy(victim, names[i], 9);
            }
        }

        printf("%s took clay from %s.\n", bully, victim);
    }
    return 0;
}

