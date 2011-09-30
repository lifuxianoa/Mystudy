#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline unsigned int func(int a)
{
    unsigned int ret;
    int i;

    ret = 1;
    for(i=1; i<=a; i++)
    {
        ret *= i;
    }
    return ret;
}

int main()
{
    double e;
    int n, i;

    printf("n e\n");
    printf("- -----------\n");

    for(n=0; n<10; n++)
    {
        e = 0.0;
        for(i=0; i<=n; i++)
        {
            e += 1.0 / func(i);
        }
        if(n == 8)
        {
            printf("%d %-.9f\n", n, e);
        }
        else
        {
            printf("%d %-.10g\n", n, e);
        }
    }
    return 0;
}

