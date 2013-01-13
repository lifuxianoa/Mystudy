/*
 * =====================================================================================
 *
 *       Filename:  Proxy.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月13日 10时44分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#ifndef __PROXY_H__
#define __PROXY_H__

class Subject
{
    public:
        virtual ~Subject();
        virtual void Request() = 0;

    protected:
        Subject();

    private:

};

class ConcreteSubject:public Subject
{
    public:
        ConcreteSubject();
        ~ConcreteSubject();
        void Request();

    protected:

    private:

};

class Proxy
{
    public:
        Proxy();
        Proxy(Subject *sub);
        ~Proxy();
        void Request();

    protected:
        
    private:
        Subject *_sub;

};

#endif  /*__PROXY_H__*/
