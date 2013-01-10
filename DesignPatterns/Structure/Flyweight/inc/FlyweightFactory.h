/*
 * =====================================================================================
 *
 *       Filename:  FlyweightFactory.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月10日 16时29分38秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#ifndef __FLYWEIGHTFACTORY_H__
#define __FLYWEIGHTFACTORY_H__

#include "Flyweight.h"
#include <vector>
using namespace std;

class FlyweightFactory
{
    public:
        FlyweightFactory();
        ~FlyweightFactory();
        Flyweight* GetFlyweight(const string &key);

    protected:

    private:
        vector<Flyweight*> _fly;

};



#endif  /*__FLYWEIGHTFACTORY_H__*/
