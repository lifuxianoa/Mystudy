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

class Factory
{
    public:
        virtual ~Factory()=0;
        virtual Product* CreateProduct()=0;

    protected:
        Factory();

    private:

};

class ConcreteFactory:public Factory
{
    public:
        ConcreteFactory();
        ~ConcreteFactory();
        Product* CreateProduct();

    protected:

    private:

};

#endif //~__FACTORY_H__

