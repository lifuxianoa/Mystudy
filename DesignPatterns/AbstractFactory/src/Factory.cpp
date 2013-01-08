/*
 * =====================================================================================
 *
 *       Filename:  Factory.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/06/2013 10:59:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

//Factory.cpp

#include "Factory.h"

#include <iostream>

using namespace std;

AbstractFactory::AbstractFactory()
{
    cout << "AbstractFactory constructor..." << endl;
}

AbstractFactory::~AbstractFactory()
{
    cout << "AbstractFactory distructor..." << endl;
}

ConcreteFactory1::ConcreteFactory1()
{
    cout << "ConcreteFactory1 constructor..." << endl;
}

ConcreteFactory1::~ConcreteFactory1()
{
    cout << "ConcreteFactory1 distructor..." << endl;
}

AbstractProductA* ConcreteFactory1::CreateProductA()
{
    return new ProductA1();
}

AbstractProductB* ConcreteFactory1::CreateProductB()
{
    return new ProductB1();
}

ConcreteFactory2::ConcreteFactory2()
{
    cout << "ConcreteFactory2 constructor..." << endl;
}

ConcreteFactory2::~ConcreteFactory2()
{
    cout << "ConcreteFactory2 distructor..." << endl;
}

AbstractProductA* ConcreteFactory2::CreateProductA()
{
    return new ProductA2();
}

AbstractProductB* ConcreteFactory2::CreateProductB()
{
    return new ProductB2();
}

