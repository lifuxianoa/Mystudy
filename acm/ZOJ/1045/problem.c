#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    double len;

    while(scanf("%lf", &len) != EOF)
    {
        if(len == 0.00)
        {
            return 0;
        }

        double sum = 0.0;
        int i;

        for(i=2;;i++)
        {
            sum += 1.0/i;
            if(sum >= len)
            {
                printf("%d card(s)\n", i-1);
                break;
            }
        }
    }
    return 0;
}

