/*
 * =====================================================================================
 *
 *       Filename:  Leaf.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月10日 15时25分46秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Leaf.h"
#include <iostream>

using namespace std;

Leaf::Leaf()
{
    cout << "Leaf constructor..." << endl;
}

Leaf::~Leaf()
{
    cout << "Leaf distructor..." << endl;
}

void Leaf::Operation()
{
    cout << "Leaf Operation..." << endl;
}

