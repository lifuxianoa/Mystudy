/*
 * =====================================================================================
 *
 *       Filename:  FlyweightFactory.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月10日 16时31分58秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "FlyweightFactory.h"
#include <cassert>
#include <iostream>

using namespace std;

FlyweightFactory::FlyweightFactory()
{
    cout << "FlyweightFactory constructor..." << endl;
}

FlyweightFactory::~FlyweightFactory()
{
    for( unsigned int i = 0; i < _fly.size(); i++)
    {
        delete _fly[i];
    }
    _fly.clear();
    cout << "FlyweightFactory distructor..." << endl;
}

Flyweight* FlyweightFactory::GetFlyweight(const string &key)
{
    for( unsigned int i = 0; i < _fly.size(); i++)
    {
        if( _fly[i]->GetIntrinsicState() == key )
        {
            cout << "Already created by users..." << endl; 
            return _fly[i];
        }
    }
    
    Flyweight *fw = new ConcreteFlyweight(key);
    _fly.push_back(fw);

    return fw;
}


