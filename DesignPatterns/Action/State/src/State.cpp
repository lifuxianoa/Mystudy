/*
 * =====================================================================================
 *
 *       Filename:  State.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月17日 10时03分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "State.h"
#include "Context.h"
#include <iostream>

using namespace std;

State::State()
{
    cout << "State constructor..." << endl;
}

State::~State()
{
    cout << "State distructor..." << endl;
}

void State::OperationInterface(Context *ctx)
{
    cout << "State OperationInterface..." << endl;
}

bool State::ChangeState(Context *ctx, State *st)
{
    ctx->ChangeState(st);
    return true;
}

void State::OperationChangeState(Context *ctx)
{
    cout << "State OperationChangeState..." << endl;
}

ConcreteStateA::ConcreteStateA()
{
    cout << "ConcreteStateA constructor..." << endl;
}

ConcreteStateA::~ConcreteStateA()
{
    cout << "ConcreteStateA distructor..." << endl;
}

void ConcreteStateA::OperationInterface(Context *ctx)
{
    cout << "ConcreteStateA OperationInterface..." << endl;
}

void ConcreteStateA::OperationChangeState(Context *ctx)
{
    cout << "ConcreteStateA OperationChangeState..." << endl;
    OperationInterface(ctx);
    ChangeState(ctx, new ConcreteStateB());
}

ConcreteStateB::ConcreteStateB()
{
    cout << "ConcreteStateB constructor..." << endl;
}

ConcreteStateB::~ConcreteStateB()
{
    cout << "ConcreteStateB distructor..." << endl;
}

void ConcreteStateB::OperationInterface(Context *ctx)
{
    cout << "ConcreteStateB OperationInterface..." << endl;
}

void ConcreteStateB::OperationChangeState(Context *ctx)
{
    cout << "ConcreteStateB OperationChangeState..." << endl;
    OperationInterface(ctx);
    ChangeState(ctx, new ConcreteStateA());
}

