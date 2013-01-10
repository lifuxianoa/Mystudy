/*
 * =====================================================================================
 *
 *       Filename:  Component.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月10日 14时20分43秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Component.h"
#include <iostream>
using namespace std;

Component::Component()
{
    cout << "Component constructor..." << endl;
}

Component::~Component()
{
    cout << "Component distructor..." << endl;
}

void Component::Add(const Component &com)
{
    cout << "Component Add..." << endl;
}

void Component::Remove(const Component &com)
{
    cout << "Component Remove..." << endl;
}

Component* Component::GetChild(int index)
{
    cout << "Component GetChild..." << endl;
    return NULL;
}

