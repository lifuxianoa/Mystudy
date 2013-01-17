/*
 * =====================================================================================
 *
 *       Filename:  Main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月17日 10时29分22秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "State.h"
#include "Context.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    State *st = new ConcreteStateA();
    Context ctx = Context(st);
    ctx.OperationChangeState();
    ctx.OperationChangeState();
    ctx.OperationChangeState();

    return 0;
}
