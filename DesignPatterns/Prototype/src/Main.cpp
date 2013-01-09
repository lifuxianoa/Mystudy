/*
 * =====================================================================================
 *
 *       Filename:  Main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月09日 16时26分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Prototype.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    Prototype *pro = new ConcretePrototype();
    Prototype *p1 = pro->Clone();

    delete p1;
    delete pro;

    return 0;
}

