/*
 * =====================================================================================
 *
 *       Filename:  Context.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月15日 11时15分46秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Context.h"
#include <iostream>

using namespace std;

Context::Context(Strategy *stg)
{
    _stg = stg;
    cout << "Context constructor..." << endl;
}

Context::~Context()
{
    cout << "Context distructor..." << endl;
}

void Context::DoAction()
{
    _stg->AlgorithmInterface();
}
