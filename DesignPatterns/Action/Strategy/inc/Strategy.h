/*
 * =====================================================================================
 *
 *       Filename:  Strategy.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月15日 10时29分20秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#ifndef __STRATEGY_H__
#define __STRATEGY_H__

class Strategy
{
    public:
        Strategy();
        virtual ~Strategy();
        virtual void AlgorithmInterface() = 0;

    protected:

    private:

};

class ConcreteStrategyA:public Strategy
{
    public:
        ConcreteStrategyA();
        virtual ~ConcreteStrategyA();
        void AlgorithmInterface();

    protected:

    private:

};

class ConcreteStrategyB:public Strategy
{
    public:
        ConcreteStrategyB();
        virtual ~ConcreteStrategyB();
        void AlgorithmInterface();

    protected:

    private:

};

#endif  /*__STRATEGY_H__*/
