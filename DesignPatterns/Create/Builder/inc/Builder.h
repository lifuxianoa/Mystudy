/*
 * =====================================================================================
 *
 *       Filename:  Builder.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月09日 14时27分19秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#ifndef __BUILDER_H__
#define __BUILDER_H__

#include <iostream>
#include "Product.h"

using namespace std;

class Builder
{
    public:
        virtual ~Builder();
        virtual void BuildPartA(const string &buildPara) = 0;
        virtual void BuildPartB(const string &buildPara) = 0;
        virtual void BuildPartC(const string &buildPara) = 0;
        virtual Product* GetProduct() = 0;

    protected:
        Builder();

    private:

};

class ConcreteBuilder:public Builder
{
    public:
        ConcreteBuilder();
        ~ConcreteBuilder();
        void BuildPartA(const string &buildPara);
        void BuildPartB(const string &buildPara);
        void BuildPartC(const string &buildPara);
        Product* GetProduct();

    protected:

    private:

};

#endif //~__BUILDER_H__
