/*
 * =====================================================================================
 *
 *       Filename:  Main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月15日 11时18分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Context.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    Strategy *psA = new ConcreteStrategyA();
    Strategy *psB = new ConcreteStrategyB();
    Context pcA = Context(psA);
    Context pcB = Context(psB);

    pcA.DoAction();
    pcB.DoAction();

    delete psA;
    delete psB;

    return 0;
}
