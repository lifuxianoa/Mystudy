/*
 * =====================================================================================
 *
 *       Filename:  Adapter.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月10日 10时24分25秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#ifndef __ADAPTER_H__
#define __ADAPTER_H__

class Target
{
    public:
        Target();
        virtual ~Target();
        virtual void Request();

    protected:

    private:

};

class Adaptee
{
    public:
        Adaptee();
        ~Adaptee();
        void SpecificRequest();

    protected:

    private:

};

class Adapter:public Target
{
    public:
        Adapter(Adaptee *ade);
        ~Adapter();
        void Request();

    protected:

    private:
        Adaptee *_ade;

};

#endif  /*__ADAPTER_H__*/
