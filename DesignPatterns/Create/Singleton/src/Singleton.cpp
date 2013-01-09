/*
 * =====================================================================================
 *
 *       Filename:  Singleton.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/07/2013 09:09:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Singleton.h"
#include <iostream>

using namespace std;

//Singleton* Singleton::_instance = NULL;
Singleton Singleton::_instance = Singleton();

Singleton::Singleton()
{
    cout << "Singleton constructor..." << endl;
}

Singleton::~Singleton()
{
    cout << "Singleton distructor..." << endl;
}

Singleton* Singleton::Instance()
{
    /*
    if (NULL == _instance)
    {
        _instance = new Singleton();
    }
    */

    return &_instance;
}

