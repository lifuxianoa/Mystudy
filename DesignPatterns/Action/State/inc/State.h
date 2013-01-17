/*
 * =====================================================================================
 *
 *       Filename:  State.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月17日 09时54分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#ifndef __STATE_H__
#define __STATE_H__

class Context; //前置声明

class State
{
    public:
        State();
        virtual ~State();
        virtual void OperationInterface(Context *ctx) = 0;
        virtual void OperationChangeState(Context *ctx) = 0;

    protected:
        bool ChangeState(Context *ctx, State *st);

    private:

};

class ConcreteStateA:public State
{
    public:
        ConcreteStateA();
        virtual ~ConcreteStateA();
        virtual void OperationInterface(Context *ctx);
        virtual void OperationChangeState(Context *ctx);

    protected:

    private:

};

class ConcreteStateB:public State
{
    public:
        ConcreteStateB();
        virtual ~ConcreteStateB();
        virtual void OperationInterface(Context *ctx);
        virtual void OperationChangeState(Context *ctx);

    protected:

    private:

};

#endif  /*__STATE_H__*/
