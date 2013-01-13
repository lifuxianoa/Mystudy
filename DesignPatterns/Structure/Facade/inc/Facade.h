/*
 * =====================================================================================
 *
 *       Filename:  Facade.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月13日 10时32分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#ifndef __FACADE_H__
#define __FACADE_H__

class Subsystem1
{
    public:
        Subsystem1();
        ~Subsystem1();
        void Operation();

    protected:

    private:

};

class Subsystem2
{
    public:
        Subsystem2();
        ~Subsystem2();
        void Operation();

    protected:

    private:

};

class Facade
{
    public:
        Facade();
        ~Facade();
        void OperationWrapper();

    protected:

    private:
        Subsystem1 *_subs1;
        Subsystem2 *_subs2;

};

#endif  /*__FACADE_H__*/
