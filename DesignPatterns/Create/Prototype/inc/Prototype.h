/*
 * =====================================================================================
 *
 *       Filename:  Prototype.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月09日 16时03分52秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#ifndef __PROTOTYPE_H__
#define __PROTOTYPE_H__

class Prototype
{
    public:
        virtual ~Prototype();
        virtual Prototype* Clone() const = 0;

    protected:
        Prototype();

    private:

};

class ConcretePrototype:public Prototype
{
    public:
        ConcretePrototype();
        ConcretePrototype(const ConcretePrototype &cp);
        ~ConcretePrototype();
        Prototype* Clone() const;

    protected:

    private:

};

#endif  /*__PROTOTYPE_H__*/
