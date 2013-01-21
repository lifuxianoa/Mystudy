/*
 * =====================================================================================
 *
 *       Filename:  Colleage.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月21日 15时20分20秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#ifndef __COLLEAGE_H__
#define __COLLEAGE_H__

#include <string>
using namespace std;

class Mediator;

class Colleage
{
    public:
        virtual ~Colleage();
        virtual void Action() = 0;
        virtual void SetState(const string &st) = 0;
        virtual string GetState() = 0;

    protected:
        Colleage();
        Colleage(Mediator *mdt);
        Mediator *_mdt;

    private:

};

class ConcreteColleageA:public Colleage
{
    public:
        ConcreteColleageA();
        ConcreteColleageA(Mediator *mdt);
        ~ConcreteColleageA();
        void Action();
        void SetState(const string &st);
        string GetState();

    protected:

    private:
        string _st;
};

class ConcreteColleageB:public Colleage
{
    public:
        ConcreteColleageB();
        ConcreteColleageB(Mediator *mdt);
        ~ConcreteColleageB();
        void Action();
        void SetState(const string &st);
        string GetState();

    protected:

    private:
        string _st;
};

#endif  /*__COLLEAGE_H__*/
