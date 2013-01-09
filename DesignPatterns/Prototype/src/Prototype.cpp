/*
 * =====================================================================================
 *
 *       Filename:  Prototype.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月09日 16时18分45秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Prototype.h"
#include <iostream>

using namespace std;

Prototype::Prototype()
{
    cout << "Prototype constructor..." << endl;
}

Prototype::~Prototype()
{
    cout << "Prototype distructor..." << endl;
}

Prototype* Prototype::Clone() const
{
    cout << "Prototype Clone..." << endl;
    return NULL;
}

ConcretePrototype::ConcretePrototype()
{
    cout << "ConcretePrototype constructor..." << endl;
}

ConcretePrototype::~ConcretePrototype()
{
    cout << "ConcretePrototype distructor..." << endl;
}

ConcretePrototype::ConcretePrototype(const ConcretePrototype &cp)
{
    cout << "ConcretePrototype copy constructor..." << endl;
}

Prototype* ConcretePrototype::Clone() const
{
    return new ConcretePrototype(*this);
}

