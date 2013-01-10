/*
 * =====================================================================================
 *
 *       Filename:  Decorator.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月10日 13时13分51秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#ifndef __DECORATOR_H__
#define __DECORATOR_H__

class Component
{
    public:
        virtual ~Component();
        virtual void Operation();

    protected:
        Component();

    private:

};

class ConcreteComponent:public Component
{
    public:
        ConcreteComponent();
        ~ConcreteComponent();
        void Operation();

    protected:

    private:

};

class Decorator:public Component
{
    public:
        Decorator(Component *com);
        virtual ~Decorator();
        void Operation();

    protected:
        Component *_com;

    private:

};

class ConcreteDecorator:public Decorator
{
    public:
        ConcreteDecorator(Component *com);
        ~ConcreteDecorator();
        void Operation();
        void AddedBehavior();

    protected:

    private:

};

#endif  /*__DECORATOR_H__*/
