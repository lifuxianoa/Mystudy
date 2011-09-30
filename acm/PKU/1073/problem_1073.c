#include <stdio.h>
#include <string.h>

struct pipe_t
{
    int x;
    int y;
    int height;
    int link_l;
    int link_r;
};

struct link_t
{
    int x;
    int y;
    int length;
};

#define MAX_PIPES 20
#define MAX_LINKS 50

struct pipe_t pipes[MAX_PIPES];
struct link_t links[MAX_LINKS];
int target = 0, level = 0;

static inline int  calc_time(int id, int level);
static inline void calc_links();
static inline void print_pipes();

int main(int argc, char *argv[])
{
    int t;
    int p;
    int l;
    int i, j;
    int time = 0;

    scanf("%d", &t);
    for(i=0; i<t; i++)
    {
        memset(&pipes, 0, sizeof(struct pipe_t)*MAX_PIPES);
        memset(&links, 0, sizeof(struct link_t)*MAX_LINKS);

        scanf("%d", &p);
        for(j=0; j<p; j++)
        {
            scanf("%d", &pipes[j].x);
            scanf("%d", &pipes[j].y);
            scanf("%d", &pipes[j].height);
        }

        scanf("%d", &l);
        for(j=0; j<l; j++)
        {
            scanf("%d", &links[j].x);
            scanf("%d", &links[j].y);
            scanf("%d", &links[j].length);
        }

        scanf("%d", &target);
        scanf("%d", &level);

        calc_links();
        //print_pipes();
        time = calc_time(0, level);
        if(time == -1)
        {
            printf("No Solution\n");
        }
        else
        {
            printf("%d\n", time);
        }
    }
    return 0;
}

static inline int  calc_time(int id, int level)
{
    if(id<0 || id > MAX_PIPES || pipes[id].height==0)
    {
        return 0;
    }
    if(pipes[id].y > level)
    {
        return -1;
    }

    int iret = 0;
    int ret = 0;

    iret = pipes[id].height + pipes[id].y - level;
    
    if(pipes[id].link_r >= level)
    {
        ret = calc_time(id+1, level);
        if(ret == -1)
        {
            return -1;
        }
        iret += ret;
    }
    else if(id+1 < target)
    {
        return -1;
    }

    //printf("id=%d, level=%d, iret=%d\n", id, level, iret);
    return iret;
}

static inline void calc_links()
{
    int i, j;
    for(i=0; i<MAX_LINKS && links[i].length>0; i++)
    {
        for(j=0; j<MAX_PIPES; j++)
        {
            if(((pipes[j].x+1) == links[i].x)
                    && (pipes[j].link_r < links[i].y))
            {
                pipes[j].link_r = links[i].y;
            }

            if(((pipes[j].x) == links[i].x+links[i].length)
                    && (pipes[j].link_l < links[i].y))
            {
                pipes[j].link_l = links[i].y;
            }
        }
    }
}

static inline void print_pipes()
{
    int i;
    for(i=0; i<MAX_PIPES && pipes[i].height>0; i++)
    {
        printf("\npipes[%d].x=%d\n", i+1, pipes[i].x);
        printf("pipes[%d].y=%d\n", i+1, pipes[i].y);
        printf("pipes[%d].height=%d\n", i+1, pipes[i].height);
        printf("pipes[%d].link_l=%d\n", i+1, pipes[i].link_l);
        printf("pipes[%d].link_r=%d\n", i+1, pipes[i].link_r);
        printf("================================================\n");
    }
}

