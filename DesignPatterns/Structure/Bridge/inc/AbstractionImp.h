/*
 * =====================================================================================
 *
 *       Filename:  AbstractionImp.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月09日 17时06分01秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#ifndef __ABSTRACTIONIMP_H__
#define __ABSTRACTIONIMP_H__

class AbstractionImp
{
    public:
        virtual ~AbstractionImp();
        virtual void Operation() = 0;

    protected:
        AbstractionImp();

    private:

};

class ConcreteAbstractionImpA:public AbstractionImp
{
    public:
        ConcreteAbstractionImpA();
        ~ConcreteAbstractionImpA();
        virtual void Operation();

    protected:

    private:

};

class ConcreteAbstractionImpB:public AbstractionImp
{
    public:
        ConcreteAbstractionImpB();
        ~ConcreteAbstractionImpB();
        virtual void Operation();

    protected:

    private:

};

#endif  /*__ABSTRACTIONIMP_H__*/
