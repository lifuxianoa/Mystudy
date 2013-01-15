/*
 * =====================================================================================
 *
 *       Filename:  Main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月15日 09时59分27秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Template.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    AbstractClass *p1 = new ConcreteClass1();
    AbstractClass *p2 = new ConcreteClass2();

    p1->TemplateMethod();
    p2->TemplateMethod();

    delete p1;
    delete p2;

    return 0;
}

