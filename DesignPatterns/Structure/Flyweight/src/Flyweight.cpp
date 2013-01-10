/*
 * =====================================================================================
 *
 *       Filename:  Flyweight.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月10日 16时22分51秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Flyweight.h"
#include <iostream>

using namespace std;

Flyweight::Flyweight(string intrinsicState)
{
    _intrinsicState = intrinsicState;
    cout << "Flyweight constructor..." << endl;
}

Flyweight::~Flyweight()
{
    cout << "Flyweight distructor..." << endl;
}

void Flyweight::Operation(const string &extrinsicState)
{
    cout << "Flyweight Operation..." << endl;
}

string Flyweight::GetIntrinsicState()
{
    cout << "Flyweight GetIntrinsicState..." << endl;
    return _intrinsicState;
}

ConcreteFlyweight::ConcreteFlyweight(string intrinsicState)
    :Flyweight(intrinsicState)
{
    cout << "ConcreteFlyweight constructor..." << intrinsicState << endl;
}

ConcreteFlyweight::~ConcreteFlyweight()
{
    cout << "ConcreteFlyweight distructor..." << endl;
}

void ConcreteFlyweight::Operation(const string &extrinsicState)
{
    cout << "ConcreteFlyweight: Out[" << GetIntrinsicState()
        << "], in[" << extrinsicState << "]" << endl;
}

