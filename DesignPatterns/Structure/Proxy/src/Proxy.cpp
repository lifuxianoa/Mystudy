/*
 * =====================================================================================
 *
 *       Filename:  Proxy.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月13日 10时46分50秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Proxy.h"
#include <iostream>

using namespace std;

Subject::Subject()
{
    cout << "Subject constructor..." << endl;
}

Subject::~Subject()
{
    cout << "Subject distructor..." << endl;
}

ConcreteSubject::ConcreteSubject()
{
    cout << "ConcreteSubject constructor..." << endl;
}

ConcreteSubject::~ConcreteSubject()
{
    cout << "ConcreteSubject distructor..." << endl;
}

void ConcreteSubject::Request()
{
    cout << "ConcreteSubject ...... Request ......" << endl;
}

Proxy::Proxy()
{
    cout << "Proxy default constructor..." << endl;
}

Proxy::Proxy(Subject *sub)
{
    _sub = sub;
    cout << "Proxy constructor..." << endl;
}

Proxy::~Proxy()
{
    delete _sub;
}

void Proxy::Request()
{
    cout << "Proxy Request ... " << endl;
    _sub->Request();
}

