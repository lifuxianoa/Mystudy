#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int N, i, j;
    double x, y;
    double square, distance_s, distance;

    scanf("%d", &N);

    for(i=0; i<N; i++)
    {
        scanf("%lf %lf", &x, &y);
        distance = sqrt(x*x + y*y);

        for(j=1;;j++)
        {
            square = j*50;
            distance_s = sqrt(square*2/3.1415926);
            if(distance_s >= distance)
            {
                printf("Property %d: This property will begin eroding in year %d.\n", i+1, j);
                break;
            }
        }
    }
    printf("END OF OUTPUT.\n");
    return 0;
}

