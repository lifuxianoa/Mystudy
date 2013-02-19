/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月30日 14时16分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.h"

int main (int argc, char *argv[])
{
    int i;
    double x;

    for ( i = 0; i < 30000000; i++)
    {
        x = 100.0;
        x = slow(x);
        x = slower(x);
        x = slowest(x);
    }

    return 0;
}

