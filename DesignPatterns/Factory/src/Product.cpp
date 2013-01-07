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

Product::Product()
{
    cout << "Product constructor..." << endl;
}

Product::~Product()
{
    cout << "Product distructor..." << endl;
}

ConcreteProduct::ConcreteProduct()
{
    cout << "ConcreteProduct constructor..." << endl;
}

ConcreteProduct::~ConcreteProduct()
{
    cout << "ConcreteProduct distructor..." << endl;
}
