#include <stdio.h>
#include <math.h>

unsigned int color_map[16][3]={{0,0,0}};

int inline distance(int r1, int g1, int b1, int r2, int g2, int b2)
{
    return pow(r1-r2, 2) + pow(g1-g2, 2) + pow(b1-b2, 2);
}

int main()
{
    int i, j;
    unsigned int R, G, B;
    int fence;
    int d, D;

    for(i=0; i<16; i++)
    {
        for(j=0; j<3; j++)
        {
            scanf("%d", &color_map[i][j]);
        }
    }

    while(1)
    {
        scanf("%d%d%d", &R, &G, &B);
        if(R==-1 && G==-1 && B==-1)
        {
            break;
        }

        D = distance(R, G, B, color_map[0][0], color_map[0][1], color_map[0][2]);
        fence = -1;

        for(i=0; i<16; i++)
        {
            d = distance(R, G, B, color_map[i][0], color_map[i][1], color_map[i][2]);
            if(d < D)
            {
                D = d;
                fence = i;
            }
        }

        printf("(%d,%d,%d) maps to (%d,%d,%d)\n", R, G, B, color_map[fence][0], color_map[fence][1], color_map[fence][2]);
    }
    return 0;
}
