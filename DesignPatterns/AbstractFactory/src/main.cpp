/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/06/2013 11:03:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

//main.cpp

#include "Factory.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    AbstractFactory *cf1 = new ConcreteFactory1();
    AbstractProductA *proA1 = cf1->CreateProductA();
    AbstractProductB *proB1 = cf1->CreateProductB();

    AbstractFactory *cf2 = new ConcreteFactory2();
    AbstractProductA *proA2 = cf2->CreateProductA();
    AbstractProductB *proB2 = cf2->CreateProductB();

    delete proB2;
    delete proA2;
    delete cf2;

    delete proB1;
    delete proA1;
    delete cf1;

    return 0;
}

