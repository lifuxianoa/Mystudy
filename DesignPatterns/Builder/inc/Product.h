/*
 * =====================================================================================
 *
 *       Filename:  Product.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月09日 14时20分56秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#ifndef __PRODUCT_H__
#define __PRODUCT_H__

class Product
{
    public:
        Product();
        ~Product();
        void ProducePart();

    protected:

    private:

};

class ProductPart
{
    public:
        ProductPart();
        ~ProductPart();
        void BuildPart();

    protected:

    private:

};

#endif //~__PRODUCT_H__
