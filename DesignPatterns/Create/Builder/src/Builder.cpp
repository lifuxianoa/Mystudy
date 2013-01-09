/*
 * =====================================================================================
 *
 *       Filename:  Builder.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月09日 14时32分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Builder.h"

Builder::Builder()
{
    cout << "Builder constructor..." << endl;
}

Builder::~Builder()
{
    cout << "Builder distructor..." << endl;
}

ConcreteBuilder::ConcreteBuilder()
{
    cout << "ConcreteBuilder constructor..." << endl;
}

ConcreteBuilder::~ConcreteBuilder()
{
    cout << "ConcreteBuilder distructor..." << endl;
}

void ConcreteBuilder::BuildPartA(const string &buildPara)
{
    cout << "Step1:Build PartA..." << buildPara << endl;
}

void ConcreteBuilder::BuildPartB(const string &buildPara)
{
    cout << "Step1:Build PartB..." << buildPara << endl;
}

void ConcreteBuilder::BuildPartC(const string &buildPara)
{
    cout << "Step1:Build PartC..." << buildPara << endl;
}

Product* ConcreteBuilder::GetProduct()
{
    BuildPartA("aaa");
    BuildPartB("bbb");
    BuildPartC("ccc");

    return new Product();
}

