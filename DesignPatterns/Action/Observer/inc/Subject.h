/*
 * =====================================================================================
 *
 *       Filename:  Subject.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月17日 13时48分18秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include <list>
#include <string>

using namespace std;
typedef string State;
class Observer;

class Subject
{
    public:
        virtual ~Subject();
        virtual void Attach(Observer *obs);
        virtual void Detach(Observer *obs);
        virtual void Notify();
        virtual void SetState(const State &st) = 0;
        virtual State GetState() = 0;

    protected:
        Subject();

    private:
        list<Observer *> *_obvs;
};

class ConcreteSubject:public Subject
{
    public:
        ConcreteSubject();
        ~ConcreteSubject();
        State GetState();
        void SetState(const State &st);

    protected:

    private:
        State _st;

};

#endif  /*__SUBJECT_H__*/
