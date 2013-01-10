/*
 * =====================================================================================
 *
 *       Filename:  Abstraction.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月09日 17时05分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#ifndef __ABSTRACTION_H__
#define __ABSTRACTION_H__

#include "AbstractionImp.h"

class Abstraction
{
    public:
        virtual ~Abstraction();
        virtual void Operation() = 0;

    protected:
        Abstraction();

    private:

};

class RefinedAbstraction:public Abstraction
{
    public:
        RefinedAbstraction(AbstractionImp *imp);
        ~RefinedAbstraction();
        void Operation();

    protected:

    private:
        AbstractionImp *_imp;

};


#endif  /*__ABSTRACTION_H__*/
