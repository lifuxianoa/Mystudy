/*
 * =====================================================================================
 *
 *       Filename:  Colleage.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月21日 15时49分46秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Colleage.h"
#include "Mediator.h"
#include <iostream>

using namespace std;

Colleage::Colleage()
{

}

Colleage::Colleage(Mediator *mdt)
{
    _mdt = mdt;
}

Colleage::~Colleage()
{

}

ConcreteColleageA::ConcreteColleageA()
{

}

ConcreteColleageA::ConcreteColleageA(Mediator *mdt)
    :Colleage(mdt)
{

}

ConcreteColleageA::~ConcreteColleageA()
{

}

string ConcreteColleageA::GetState()
{
    return _st;
}

void ConcreteColleageA::SetState(const string &st)
{
    _st = st;
}

void ConcreteColleageA::Action()
{
    _mdt->DoActionFromAtoB();
    cout << "State of ConcreteColleageB:" << GetState() << endl;
}

ConcreteColleageB::ConcreteColleageB()
{

}

ConcreteColleageB::ConcreteColleageB(Mediator *mdt)
    :Colleage(mdt)
{

}

ConcreteColleageB::~ConcreteColleageB()
{

}

void ConcreteColleageB::Action()
{
    _mdt->DoActionFromBtoA();
    cout << "State of ConcreteColleageB:" << GetState() << endl;
}

string ConcreteColleageB::GetState()
{
    return _st;
}

void ConcreteColleageB::SetState(const string &st)
{
    _st = st;
}

