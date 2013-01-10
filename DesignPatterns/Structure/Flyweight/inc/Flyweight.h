/*
 * =====================================================================================
 *
 *       Filename:  Flyweight.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月10日 16时19分08秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#ifndef __FLYWEIGHT_H__
#define __FLYWEIGHT_H__

#include <string>
using namespace std;

class Flyweight
{
    public:
        virtual ~Flyweight();
        virtual void Operation(const string &extrinsicState);
        string GetIntrinsicState();

    protected:
        Flyweight(string intrinsicState);

    private:
        string _intrinsicState;

};

class ConcreteFlyweight:public Flyweight
{
    public:
        ConcreteFlyweight(string intrinsicState);
        ~ConcreteFlyweight();
        void Operation(const string &extrinsicState);

    protected:

    private:

};

#endif  /*__FLYWEIGHT_H__*/
