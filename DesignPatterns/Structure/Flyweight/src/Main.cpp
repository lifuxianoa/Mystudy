/*
 * =====================================================================================
 *
 *       Filename:  Main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月10日 16时37分14秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "FlyweightFactory.h"

int main(int argc, char *argv[])
{
    FlyweightFactory fc;

    Flyweight *fw1 = fc.GetFlyweight("hello");
    Flyweight *fw2 = fc.GetFlyweight("world");
    Flyweight *fw3 = fc.GetFlyweight("hello");

    return 0;
}
