#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    double mon = 0.0, sum = 0.0;
    int i;

    for(i=0; i<12; i++)
    {
        scanf("%lf", &mon);
        sum += mon;
    }
    printf("$%.2lf\n", sum/12);
    return 0;
}

