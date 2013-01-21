/*
 * =====================================================================================
 *
 *       Filename:  Mediator.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月21日 16时17分54秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Mediator.h"
#include "Colleage.h"

Mediator::Mediator()
{

}

Mediator::~Mediator()
{

}

ConcreteMediator::ConcreteMediator()
{

}

ConcreteMediator::~ConcreteMediator()
{

}

ConcreteMediator::ConcreteMediator(Colleage *clgA, Colleage *clgB)
{
    _clgA = clgA;
    _clgB = clgB;
}



void ConcreteMediator::DoActionFromAtoB()
{
    _clgB->SetState(_clgA->GetState());
}

void ConcreteMediator::DoActionFromBtoA()
{
    _clgA->SetState(_clgB->GetState());
}

void ConcreteMediator::SetConcreteColleageA(Colleage *clgA)
{
    _clgA = clgA;
}

void ConcreteMediator::SetConcreteColleageB(Colleage *clgB)
{
    _clgB = clgB;
}

Colleage* ConcreteMediator::GetConcreteColleageA()
{
    return _clgA;
}

Colleage* ConcreteMediator::GetConcreteColleageB()
{
    return _clgB;
}

void ConcreteMediator::IntroColleage(Colleage *clgA, Colleage *clgB)
{
    _clgA = clgA;
    _clgB = clgB;
}

