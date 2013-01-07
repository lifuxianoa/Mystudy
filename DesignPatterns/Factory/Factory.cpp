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

Factory::Factory()
{
    cout << "Factory constructor..." << endl;
}

Factory::~Factory()
{
    cout << "Factory disconstructor..." << endl;
}

ConcreteFactory::ConcreteFactory()
{
    cout << "ConcreteFactory constructor..." << endl;
}

ConcreteFactory::~ConcreteFactory()
{
    cout << "ConcreteFactory distructor..." << endl;
}

Product* ConcreteFactory::CreateProduct()
{
    return new ConcreteProduct();
}

