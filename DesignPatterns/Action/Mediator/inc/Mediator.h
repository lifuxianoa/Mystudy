/*
 * =====================================================================================
 *
 *       Filename:  Mediator.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月21日 15时55分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#ifndef __MEDIATOR_H__
#define __MEDIATOR_H__

class Colleage;

class Mediator
{
    public:
        virtual ~Mediator();
        virtual void DoActionFromAtoB() = 0;
        virtual void DoActionFromBtoA() = 0;

    protected:
        Mediator();

    private:

};

class ConcreteMediator:public Mediator
{
    public:
        ConcreteMediator();
        ConcreteMediator(Colleage *clgA, Colleage *clgB);
        ~ConcreteMediator();
        void SetConcreteColleageA(Colleage *clgA);
        void SetConcreteColleageB(Colleage *clgB);
        Colleage* GetConcreteColleageA();
        Colleage* GetConcreteColleageB();
        void IntroColleage(Colleage *clgA, Colleage *clgB);
        void DoActionFromAtoB();
        void DoActionFromBtoA();

    protected:

    private:
        Colleage *_clgA;
        Colleage *_clgB;

};

#endif  /*__MEDIATOR_H__*/
