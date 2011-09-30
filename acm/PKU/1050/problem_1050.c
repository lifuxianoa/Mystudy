#include <stdio.h>

char array[100][100];
int N;

inline int rect_sum(int x, int y, int x1, int y1)
{
    int i, j;
    int sum = 0;

    for(i=x; i<=x1; i++)
    {
        for(j=y; j<=y1; j++)
        {
            sum += array[i][j];
        }
    }
    return sum;
}

int main()
{
    int i, j, i1, j1;
    int sum, max_sum;

    scanf("%d", &N);
    //printf("N=%d\n", N);
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            scanf("%d", &array[i][j]);
            //printf("(%d,%d)=%d\n", i, j, array[i][j]);
        }
    }

    max_sum = array[0][0];
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            for(i1=i; i1<N; i1++)
            {
                for(j1=j; j1<N; j1++)
                {
                    sum = rect_sum(i, j, i1, j1);
                    if(sum > max_sum)
                    {
                        max_sum = sum;
                    }
                }
            }
        }
    }
    printf("%d\n", max_sum);
    return 0;
}
