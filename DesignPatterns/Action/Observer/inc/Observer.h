/*
 * =====================================================================================
 *
 *       Filename:  Observer.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月17日 14时54分54秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include "Subject.h"
#include <string>

using namespace std;

typedef string State;

class Observer
{
    public:
        virtual ~Observer();
        virtual void Update(Subject *sub) = 0;
        virtual void PrintInfo() = 0;

    protected:
        Observer();
        State _st;

    private:

};

class ConcreteObserverA:public Observer
{
    public:
        virtual Subject* GetSubject();
        ConcreteObserverA(Subject *sub);
        virtual ~ConcreteObserverA();
        void Update(Subject *sub); //传入Subject作为参数，这样可以让一个View属于多个的Subject
        void PrintInfo();

    protected:

    private:
        Subject *_sub;

};

class ConcreteObserverB:public Observer
{
    public:
        virtual Subject* GetSubject();
        ConcreteObserverB(Subject *sub);
        virtual ~ConcreteObserverB();
        void Update(Subject *sub); //传入Subject作为参数，这样可以让一个View属于多个的Subject
        void PrintInfo();

    protected:

    private:
        Subject *_sub;

};


#endif  /*__OBSERVER_H__*/
