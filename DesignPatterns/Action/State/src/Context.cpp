/*
 * =====================================================================================
 *
 *       Filename:  Context.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月17日 10时24分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Context.h"
#include "State.h"
#include <iostream>

using namespace std;

Context::Context()
{
    cout << "Context constructor..." << endl;
}

Context::Context(State *st)
{
    cout << "Context constructor 1..." << endl;
    _state = st;
}

Context::~Context()
{
    cout << "Context distructor..." << endl;
    if (NULL != _state)
    {
        delete _state;
    }
}

void Context::OperationInterface()
{
    _state->OperationInterface(this);
}

void Context::OperationChangeState()
{
    _state->OperationChangeState(this);
}

bool Context::ChangeState(State *st)
{
    if (NULL != _state)
    {
        delete _state;
    }

    _state = st;

    return true;
}

