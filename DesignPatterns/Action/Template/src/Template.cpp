/*
 * =====================================================================================
 *
 *       Filename:  Template.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月15日 09时53分47秒
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

AbstractClass::AbstractClass()
{
    cout << "AbstractClass constructor..." << endl;
}

AbstractClass::~AbstractClass()
{
    cout << "AbstractClass distructor..." << endl;
}

void AbstractClass::TemplateMethod()
{
    PrimitiveOperation1();
    PrimitiveOperation2();
}

ConcreteClass1::ConcreteClass1()
{
    cout << "ConcreteClass1 constructor..." << endl;
}

ConcreteClass1::~ConcreteClass1()
{
    cout << "ConcreteClass1 distructor..." << endl;
}

void ConcreteClass1::PrimitiveOperation1()
{
    cout << "ConcreteClass1 PrimitiveOperation1..." << endl;
}

void ConcreteClass1::PrimitiveOperation2()
{
    cout << "ConcreteClass1 PrimitiveOperation2..." << endl;
}

ConcreteClass2::ConcreteClass2()
{
    cout << "ConcreteClass2 constructor..." << endl;
}

ConcreteClass2::~ConcreteClass2()
{
    cout << "ConcreteClass2 distructor..." << endl;
}

void ConcreteClass2::PrimitiveOperation1()
{
    cout << "ConcreteClass2 PrimitiveOperation1..." << endl;
}

void ConcreteClass2::PrimitiveOperation2()
{
    cout << "ConcreteClass2 PrimitiveOperation2..." << endl;
}

