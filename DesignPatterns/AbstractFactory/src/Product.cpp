/*
 * =====================================================================================
 *
 *       Filename:  Product.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/06/2013 10:51:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

//Product.cpp

#include "Product.h"

#include <iostream>

using namespace std;

AbstractProductA::AbstractProductA()
{
    cout << "AbstractProductA constructor..." << endl;
}

AbstractProductA::~AbstractProductA()
{
    cout << "AbstractProductA distructor..." << endl;
}

AbstractProductB::AbstractProductB()
{
    cout << "AbstractProductB constructor..." << endl;
}

AbstractProductB::~AbstractProductB()
{
    cout << "AbstractProductB distructor..." << endl;
}

ProductA1::ProductA1()
{
    cout << "ProductA1 constructor..." << endl;
}

ProductA1::~ProductA1()
{
    cout << "ProductA1 distructor..." << endl;
}

ProductA2::ProductA2()
{
    cout << "ProductA2 constructor..." << endl;
}

ProductA2::~ProductA2()
{
    cout << "ProductA2 distructor..." << endl;
}

ProductB1::ProductB1()
{
    cout << "ProductB1 constructor..." << endl;
}

ProductB1::~ProductB1()
{
    cout << "ProductB1 distructor..." << endl;
}

ProductB2::ProductB2()
{
    cout << "ProductB2 constructor..." << endl;
}

ProductB2::~ProductB2()
{
    cout << "ProductB2 distructor..." << endl;
}

