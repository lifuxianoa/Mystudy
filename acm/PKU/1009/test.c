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
    unsigned int count;
};

struct SImage
{
    unsigned int width;
    struct SData data[MAX_PAIR];
};

unsigned char get_value(struct SImage *img, unsigned int i, unsigned int j, int width)
{
    unsigned int index = i * width + j, count = 0;
    int k;
    for( k = 0; k < MAX_PAIR; k++ )
    {
        count += img->data[k].count;
        if (count > index)
        {
            break;
        }
    }

    //printf("value[%u][%u]=%d\n", i, j, img->data[k].value);
    return img->data[k].value;
}

unsigned char get_max(struct SImage *img, unsigned int i, unsigned int j, int width)
{
    unsigned char ret_val = 0, value, value_comp, abs_val;
    unsigned int max_line = 0, k;
    for( k = 0; k < MAX_PAIR; k++ )
    {
        if( 0 == img->data[k].count)
        {
            break;
        }
        max_line += img->data[k].count;
    }
    max_line /= width;

    value = get_value(img, i, j, width);

    if (i >= 1)
    {
        if (j >= 1)
        {
            value_comp = get_value(img, i - 1, j - 1, width);
            abs_val = abs(value - value_comp);
            if( abs_val > ret_val )
            {
                ret_val = abs_val;
            }
        }

        value_comp = get_value(img, i - 1, j, width);
        abs_val = abs(value - value_comp);
        if( abs_val > ret_val )
        {
            ret_val = abs_val;
        }

        if (j + 1 < width)
        {
            value_comp = get_value(img, i - 1, j + 1, width);
            abs_val = abs(value - value_comp);
            if( abs_val > ret_val )
            {
                ret_val = abs_val;
            }
        }
    }

    if (j >= 1)
    {
        value_comp = get_value(img, i, j - 1, width);
        abs_val = abs(value - value_comp);
        if( abs_val > ret_val )
        {
            ret_val = abs_val;
        }
    }

    if (j + 1 < width)
    {
        value_comp = get_value(img, i, j + 1, width);
        abs_val = abs(value - value_comp);
        if( abs_val > ret_val )
        {
            ret_val = abs_val;
        }
    }

    if (i + 1 < max_line)
    {
        if (j >= 1)
        {
            value_comp = get_value(img, i + 1, j - 1, width);
            abs_val = abs(value - value_comp);
            if( abs_val > ret_val )
            {
                ret_val = abs_val;
            }
        }

        value_comp = get_value(img, i + 1, j, width);
        abs_val = abs(value - value_comp);
        if( abs_val > ret_val )
        {
            ret_val = abs_val;
        }

        if (j + 1 < width)
        {
            value_comp = get_value(img, i + 1, j + 1, width);
            abs_val = abs(value - value_comp);
            if( abs_val > ret_val )
            {
                ret_val = abs_val;
            }
        }
    }

    return ret_val;
}

int main(int argc, char *argv[])
{
    struct SImage input;
    unsigned int width = 0;
    unsigned int value = 0;
    unsigned int count = 0;

    while(scanf("%d", &width))
    {
        if(0 == width)
        {
            break;
        }

        memset(&input, 0, sizeof(input));
        input.width = width;
        
        unsigned int line = 0;
        unsigned int max_line = 0;
        while(scanf("%u%u", &value, &count))
        {
            if(0 == count)
            {
                break;
            }
            input.data[line].value = value;
            input.data[line].count = count;
            line++;
            max_line += count;
        }

        unsigned char val = 0, val_last = 0;
        unsigned int i, j, val_count = 1;
        max_line /= width;
        printf("%d\n", width);
        for( i= 0; i < max_line; i++ )
        {
            for( j = 0; j < width; j++ )
            {
                val = get_max(&input, i, j, width);
                //printf("i:%d, j:%d,val=%d,", i, j, val);
                if(0 == i && 0 == j)
                {
                    val_last = val;
                    continue;
                }
                if( val == val_last )
                {
                    val_count++;
                }
                else if( 0 != val_count )
                {
                    printf("%d %u\n", (int)val_last, val_count);
                    val_count = 1;
                }
                val_last = val;
                //printf("val_count=%d\n", val_count);
            }
        }
        printf("%d %u\n0 0", (int)val_last, val_count);
    }
    printf("0\n");

    return 0;
}

