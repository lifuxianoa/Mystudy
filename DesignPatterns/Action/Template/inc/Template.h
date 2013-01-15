/*
 * =====================================================================================
 *
 *       Filename:  Template.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月15日 09时46分08秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__

class AbstractClass
{
    public:
        virtual ~AbstractClass();
        void TemplateMethod();

    protected:
        virtual void PrimitiveOperation1() = 0;
        virtual void PrimitiveOperation2() = 0;
        AbstractClass();

    private:

};

class ConcreteClass1:public AbstractClass
{
    public:
        ConcreteClass1();
        ~ConcreteClass1();

    protected:
        void PrimitiveOperation1();
        void PrimitiveOperation2();

    private:

};

class ConcreteClass2:public AbstractClass
{
    public:
        ConcreteClass2();
        ~ConcreteClass2();

    protected:
        void PrimitiveOperation1();
        void PrimitiveOperation2();

    private:

};

#endif  /*__TEMPLATE_H__*/
