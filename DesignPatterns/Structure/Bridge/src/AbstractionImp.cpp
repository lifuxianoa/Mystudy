/*
 * =====================================================================================
 *
 *       Filename:  AbstractionImp.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月10日 09时49分27秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "AbstractionImp.h"
#include <iostream>

using namespace std;

AbstractionImp::AbstractionImp()
{
    cout << "AbstractionImp constructor..." << endl;
}

AbstractionImp::~AbstractionImp()
{
    cout << "AbstractionImp distructor..." << endl;
}

void AbstractionImp::Operation()
{
    cout << "AbstractionImp Operation..." << endl;
}

ConcreteAbstractionImpA::ConcreteAbstractionImpA()
{
    cout << "ConcreteAbstractionImpA constructor..." << endl;
}

ConcreteAbstractionImpA::~ConcreteAbstractionImpA()
{
    cout << "ConcreteAbstractionImpA distructor..." << endl;
}

void ConcreteAbstractionImpA::Operation()
{
    cout << "ConcreteAbstractionImpA Operation..." << endl;
}

ConcreteAbstractionImpB::ConcreteAbstractionImpB()
{
    cout << "ConcreteAbstractionImpB constructor..." << endl;
}

ConcreteAbstractionImpB::~ConcreteAbstractionImpB()
{
    cout << "ConcreteAbstractionImpB distructor..." << endl;
}

void ConcreteAbstractionImpB::Operation()
{
    cout << "ConcreteAbstractionImpB Operation..." << endl;
}

