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
    Factory *fac = new ConcreteFactory();

    cout << "Factory new..." << endl;

    Product *pro = fac->CreateProduct();

    cout << "CreateProduct ..." << endl;

    if (NULL != pro)
    {
        delete pro;
    }
    delete fac;
    return 0;
}

