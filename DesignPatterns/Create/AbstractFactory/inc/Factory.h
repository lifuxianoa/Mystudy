/*
 * =====================================================================================
 *
 *       Filename:  Factory.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/06/2013 10:54:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

//Factory.h

#ifndef __FACTORY_H__
#define __FACTORY_H__

#include "Product.h"

class AbstractFactory
{
    public:
        virtual ~AbstractFactory()=0;
        virtual AbstractProductA* CreateProductA()=0;
        virtual AbstractProductB* CreateProductB()=0;

    protected:
        AbstractFactory();

    private:

};

class ConcreteFactory1:public AbstractFactory
{
    public:
        ConcreteFactory1();
        ~ConcreteFactory1();
        AbstractProductA* CreateProductA();
        AbstractProductB* CreateProductB();

    protected:

    private:

};

class ConcreteFactory2:public AbstractFactory
{
    public:
        ConcreteFactory2();
        ~ConcreteFactory2();
        AbstractProductA* CreateProductA();
        AbstractProductB* CreateProductB();

    protected:

    private:

};

#endif //~__FACTORY_H__

