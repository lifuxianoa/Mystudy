#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    double diameter, seconds;
    int revolutions, count = 0;
    double distance, mph, PI = 3.1415927;

    while(scanf("%lf %d %lf", &diameter, &revolutions, &seconds))
    {
        if(revolutions == 0)
        {
            break;
        }

        count++;

        distance = PI * diameter * revolutions / 12.0 / 5280.0;
        mph = distance / (seconds / 60.0 / 60.0);
        printf("Trip #%d: %.2f %.2f\n", count, distance, mph);
    }
    return 0;
}

