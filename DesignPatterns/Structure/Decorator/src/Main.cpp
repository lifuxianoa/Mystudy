/*
 * =====================================================================================
 *
 *       Filename:  Main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月10日 13时46分08秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Decorator.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    Component *com = new ConcreteComponent();
    Decorator *dec = new ConcreteDecorator(com);

    dec->Operation();
    delete dec;
    delete com;

    return 0;
}

