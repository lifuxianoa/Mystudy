/*
 * =====================================================================================
 *
 *       Filename:  Main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月13日 10时51分08秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Proxy.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    Subject *sub = new ConcreteSubject();
    Proxy p = Proxy(sub);
    p.Request();

    return 0;
}
