/*
 * =====================================================================================
 *
 *       Filename:  Observer.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月17日 14时59分04秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Observer.h"
#include "Subject.h"
#include <iostream>
#include <string>
using namespace std;

Observer::Observer()
{
    cout << "Observer constructor..." << endl;
    _st = '\0';
}

Observer::~Observer()
{
    cout << "Observer distructor..." << endl;
}

ConcreteObserverA::ConcreteObserverA(Subject *sub)
{
    _sub = sub;
    _sub->Attach(this);
}

ConcreteObserverA::~ConcreteObserverA()
{
    _sub->Detach(this);
    /*
    if( NULL != _sub )
    {
        delete _sub;
    }
    */
}

Subject* ConcreteObserverA::GetSubject()
{
    return _sub;
}

void ConcreteObserverA::PrintInfo()
{
    cout << "ConcreteObserverA Observer..." << _sub->GetState() << endl;
}

void ConcreteObserverA::Update(Subject *sub)
{
    _st = sub->GetState();
    PrintInfo();
}

ConcreteObserverB::ConcreteObserverB(Subject *sub)
{
    _sub = sub;
    _sub->Attach(this);
}

ConcreteObserverB::~ConcreteObserverB()
{
    _sub->Detach(this);
    /*
    if( NULL != _sub )
    {
        delete _sub;
    }
    */
}

Subject* ConcreteObserverB::GetSubject()
{
    return _sub;
}

void ConcreteObserverB::PrintInfo()
{
    cout << "ConcreteObserverB Observer..." << _sub->GetState() << endl;
}

void ConcreteObserverB::Update(Subject *sub)
{
    _st = sub->GetState();
    PrintInfo();
}

