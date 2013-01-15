/*
 * =====================================================================================
 *
 *       Filename:  Context.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月15日 11时11分24秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#ifndef __CONTEXT_H__
#define __CONTEXT_H__

/* 这个类是Strategy模式的关键，也是Strategy模式和Template模式的根本区别所在。
 * Strategy通过“组合”（委托）方式实现算法（实现）的异构，而Template模式则采取的是继承
 * 的方式。这两个模式的区别也是继承和组合两种实现接口重用的方式的区别*/
#include "Strategy.h"

class Context
{
    public:
        Context(Strategy *stg);
        ~Context();
        void DoAction();

    protected:

    private:
        Strategy *_stg;

};


#endif  /*__CONTEXT_H__*/
