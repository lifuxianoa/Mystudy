/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年02月27日 14时26分33秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_PAIR 1000

struct SData
{
    unsigned char value;
    unsigned int len;
};

struct SImage
{
    unsigned int width;
    struct SData data[MAX_PAIR];
};

struct SImage input;
unsigned int line = 0;
unsigned int sum = 0;

unsigned char get_value(unsigned int pos)
{
    int i, curpos = 0;

    for( i = 0; i < line; i++)
    {
        if( pos >= curpos && pos < curpos + input.data[i].len)
        {
            return input.data[i].value;
        }
        curpos += input.data[i].len;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    unsigned int value = 0;
    unsigned int len = 0;
    unsigned int width;

    while(scanf("%d", &width))
    {
        if(0 == width)
        {
            break;
        }

        memset(&input, 0, sizeof(input));
        input.width = width;
        
        while(scanf("%u%u", &value, &len))
        {
            if(0 == len)
            {
                break;
            }
            input.data[line].value = value;
            input.data[line].len = len;
            line++;
            sum += len;
        }

    }

    return 0;
}

