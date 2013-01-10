/*
 * =====================================================================================
 *
 *       Filename:  Adapter.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月10日 10时58分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Adapter.h"
#include <iostream>

using namespace std;

Target::Target()
{
    cout << "Target constructor..." << endl;
}

Target::~Target()
{
    cout << "Target distructor..." << endl;
}

void Target::Request()
{
    cout << "Target Request..." << endl;
}

Adaptee::Adaptee()
{
    cout << "Adaptee constructor..." << endl;
}

Adaptee::~Adaptee()
{
    cout << "Adaptee distructor..." << endl;
}

void Adaptee::SpecificRequest()
{
    cout << "Adaptee SpecificRequest..." << endl;
}

Adapter::Adapter(Adaptee *ade)
{
    cout << "Adapter constructor..." << endl;
    _ade = ade;
}

Adapter::~Adapter()
{
    cout << "Adapter distructor..." << endl;
}

void Adapter::Request()
{
    _ade->SpecificRequest();
}
