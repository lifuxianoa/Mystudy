/*
 * =====================================================================================
 *
 *       Filename:  Facade.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月13日 10时35分05秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Facade.h"
#include <iostream>

using namespace std;

Subsystem1::Subsystem1()
{
    cout << "Subsystem1 constructor..." << endl;
}

Subsystem1::~Subsystem1()
{
    cout << "Subsystem1 distructor..." << endl;
}

void Subsystem1::Operation()
{
    cout << "Subsystem1 operation..." << endl;
}

Subsystem2::Subsystem2()
{
    cout << "Subsystem2 constructor..." << endl;
}

Subsystem2::~Subsystem2()
{
    cout << "Subsystem2 distructor..." << endl;
}

void Subsystem2::Operation()
{
    cout << "Subsystem2 operation..." << endl;
}

Facade::Facade()
{
    _subs1 = new Subsystem1();
    _subs2 = new Subsystem2();
}

Facade::~Facade()
{
    delete _subs1;
    delete _subs2;
}

void Facade::OperationWrapper()
{
    _subs1->Operation();
    _subs2->Operation();
}

