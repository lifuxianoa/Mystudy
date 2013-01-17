/*
 * =====================================================================================
 *
 *       Filename:  Subject.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月17日 14时23分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Subject.h"
#include "Observer.h"
#include <iostream>
#include <list>

using namespace std;

typedef string State;

Subject::Subject()
{
    cout << "Subject constructor..." << endl;
    _obvs = new list<Observer*>;
}

Subject::~Subject()
{
    cout << "Subject distructor..." << endl;
    delete _obvs;
}

void Subject::Attach(Observer *obv)
{
    _obvs->push_front(obv);
}

void Subject::Detach(Observer *obv)
{
    if (NULL != obv)
    {
        _obvs->remove(obv);
    }
}

void Subject::Notify()
{
    list<Observer *>::iterator it;
    it = _obvs->begin();
    for(  ; it != _obvs->end(); it++ )
    {
        (*it)->Update(this);
    }
}

ConcreteSubject::ConcreteSubject()
{
    cout << "ConcreteSubject constructor..." << endl;
    _st = '\0';
}

ConcreteSubject::~ConcreteSubject()
{
    cout << "ConcreteSubject distructor..." << endl;
}

State ConcreteSubject::GetState()
{
    return _st;
}

void ConcreteSubject::SetState(const State &st)
{
    _st = st;
}

