/*
 * =====================================================================================
 *
 *       Filename:  Product.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月09日 14时23分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include <iostream>
#include "Product.h"

using namespace std;

Product::Product()
{
    cout << "Product constructor..." << endl;
}

Product::~Product()
{
    cout << "Product distructor..." << endl;
}

void Product::ProducePart()
{
    cout << "Product ProducePart..." << endl;
}

ProductPart::ProductPart()
{
    cout << "ProductPart constructor..." << endl;
}

ProductPart::~ProductPart()
{
    cout << "ProductPart distructor..." << endl;
}

void ProductPart::BuildPart()
{
    cout << "ProductPart BudilPart..." << endl;
}

