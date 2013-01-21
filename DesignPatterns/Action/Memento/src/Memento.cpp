/*
 * =====================================================================================
 *
 *       Filename:  Memento.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月21日 13时55分31秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Memento.h"
#include <iostream>
using namespace std;

typedef string State;

Originator::Originator()
{
    cout << "Originator default constructor..." << endl;
    _st = "";
    _mt = NULL;
}

Originator::Originator(const State &st)
{
    cout << "Originator constructor..." << endl;
    _st = st;
    _mt = NULL;
}

Originator::~Originator()
{
    cout << "Originator distructor..." << endl;
    if (NULL != _mt)
    {
        delete _mt;
        _mt = NULL;
    }
}

Memento* Originator::CreateMemento()
{
    return new Memento(_st);
}

void Originator::DistoryMemento(Memento *men)
{
    if (NULL != men)
    {
        delete men;
    }
}

State Originator::GetState()
{
    return _st;
}

void Originator::SetState(const State &st)
{
    _st = st;
}

void Originator::PrintState()
{
    cout << _st << "..." << endl;
}

void Originator::SetMemento(Memento *men)
{
    _mt = men;
}

void Originator::RestoreToMemento(Memento *mt)
{
    _st = mt->GetState();
}

Memento::Memento()
{
    cout << "Memento default constructor..." << endl;
}

Memento::Memento(const State &st)
{
    cout << "Memento constructor..." << endl;
    _st = st;
}

Memento::~Memento()
{
    cout << "Memento distructor..." << endl;
}

State Memento::GetState()
{
    return _st;
}

