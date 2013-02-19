/*
 * =====================================================================================
 *
 *       Filename:  func.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月30日 14时40分56秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "func.h"
#include <math.h>

double slow(double x)
{
    return pow(x,1.12345);
}

double slower(double x)
{
    return 1.0/x;
}

double slowest(double x)
{
    return sqrt(x);
}

