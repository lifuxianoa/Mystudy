/*
 * =====================================================================================
 *
 *       Filename:  Composite.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月10日 14时50分59秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Composite.h"
#include <iostream>
using namespace std;

Composite::Composite()
{
    cout << "Composite constructor..." << endl;
}

Composite::~Composite()
{
    cout << "Composite distructor..." << endl;
}

void Composite::Operation()
{
    for( unsigned int i = 0; i < comVec.size(); i++ )
    {
        comVec[i]->Operation();
    }
}

void Composite::Add(Component *com)
{
    comVec.push_back(com);
}

void Composite::Remove(Component *com)
{
    for( unsigned int i = 0; i < comVec.size(); i++ )
    {
        if (comVec[i] == com)
        {
            comVec.erase(comVec.begin() + i);
        }
    }

}

Component* Composite::GetChild(int index)
{
    return comVec[index];
}

