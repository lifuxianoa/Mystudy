#include <stdio.h>
#include "base64.h"

union u
{
    struct
    {
        unsigned long d:6;
        unsigned long c:6;
        unsigned long b:6;
        unsigned long a:6;
    } s;
    
    unsigned char c[3];
} u;

int main(int argc, char *argv[])
{
    if (2 != argc)
    {
        printf("%s <string to encode use base64>\n", argv[0]);
        return 1;
    }

    u.c[0] = 'n';
    u.c[1] = 'a';
    u.c[2] = 'M';

    printf("c: %p %p %p\n", &(u.c[0]), &(u.c[1]), &(u.c[2]));
    //printf("a:%p, b:%p, c:%p, d:%p\n", &(u.s.a), &(u.s.b), &(u.s.c), &(u.s.d));
    printf("c: %c %c %c\n", u.c[0], u.c[1], u.c[2]);
    printf("a:%d, b:%d, c:%d, d:%d\n", u.s.a, u.s.b, u.s.c, u.s.d);
    return 0;
}

