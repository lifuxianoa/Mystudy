#include <iostream>
#include<vector>

using namespace std;

bool uniform(int step, int mod)
{
    int count = 1;
    int seed = step % mod;

    while(seed != 0)
    {
        count++;
        seed = (seed + step)%mod;
    }
    return count == mod;
}

int main()
{
    int step, mod;
    while(scanf("%d%d", &step, &mod) != EOF)
    {
        printf("%10d%10d    ", step, mod);
        if (uniform(step, mod)) {
            printf("Good Choice\n\n");
        }
        else
        {
            printf("Bad Choice\n\n");
        }
    }

    return 0;
}
