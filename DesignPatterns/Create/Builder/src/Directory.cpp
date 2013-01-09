/*
 * =====================================================================================
 *
 *       Filename:  Directory.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月09日 15时15分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include    "Director.h"

Director::Director(Builder *bld)
{
    _bld = bld;
    cout << "Directory constructor..." << endl;
}

Director::~Director()
{
    cout << "Directory distructor..." << endl;
}

void Director::Construct()
{
    _bld->BuildPartA("AAA");
    _bld->BuildPartB("BBB");
    _bld->BuildPartC("CCC");
}

