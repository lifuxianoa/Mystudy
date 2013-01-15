/*
 * =====================================================================================
 *
 *       Filename:  Strategy.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月15日 11时05分50秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Strategy.h"
#include <iostream>

using namespace std;

Strategy::Strategy()
{
    cout << "Strategy constructor..." << endl;
}

Strategy::~Strategy()
{
    cout << "Strategy distructor..." << endl;
}

void Strategy::AlgorithmInterface()
{
    cout << "Strategy AlgorithmInterface..." << endl;
}

ConcreteStrategyA::ConcreteStrategyA()
{
    cout << "ConcreteStrategyA constructor..." << endl;
}

ConcreteStrategyA::~ConcreteStrategyA()
{
    cout << "ConcreteStrategyA distructor..." << endl;
}

void ConcreteStrategyA::AlgorithmInterface()
{
    cout << "ConcreteStrategyA AlgorithmInterface..." << endl;
}

ConcreteStrategyB::ConcreteStrategyB()
{
    cout << "ConcreteStrategyB constructor..." << endl;
}

ConcreteStrategyB::~ConcreteStrategyB()
{
    cout << "ConcreteStrategyB distructor..." << endl;
}

void ConcreteStrategyB::AlgorithmInterface()
{
    cout << "ConcreteStrategyB AlgorithmInterface..." << endl;
}

