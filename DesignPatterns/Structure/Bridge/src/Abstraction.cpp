/*
 * =====================================================================================
 *
 *       Filename:  Abstraction.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月10日 10时03分41秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Abstraction.h"
#include <iostream>

using namespace std;

Abstraction::Abstraction()
{
    cout << "Abstraction constructor..." << endl;
}

Abstraction::~Abstraction()
{
    cout << "Abstraction distructor..." << endl;
}

RefinedAbstraction::RefinedAbstraction(AbstractionImp *imp)
{
    _imp = imp;
    cout << "RefinedAbstraction constructor..." << endl;
}

RefinedAbstraction::~RefinedAbstraction()
{
    cout << "RefinedAbstraction distructor..." << endl;
}

void RefinedAbstraction::Operation()
{
    cout << "RefinedAbstraction Operation" << endl;
    _imp->Operation();
}
