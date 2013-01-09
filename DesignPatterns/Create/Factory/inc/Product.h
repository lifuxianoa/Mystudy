/*
 * =====================================================================================
 *
 *       Filename:  Product.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/06/2013 10:33:27 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#ifndef __PROCUCT_H__
#define __PROCUCT_H__

class Product
{
    public:
        virtual ~Product()=0;

    protected:
        Product();

    private:

};

class ConcreteProduct:public Product
{
    public:
        ConcreteProduct();
        ~ConcreteProduct();

    protected:

    private:

};

#endif //~__PROCUCT_H__

