/*
 * =====================================================================================
 *
 *       Filename:  Context.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月17日 09时55分04秒
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

class State;

class Context
{
    public:
        Context();
        Context(State *st);
        ~Context();
        void OperationInterface();
        void OperationChangeState();

    protected:

    private:
        friend class State; //在State类中可以访问Context类的private字段
        bool ChangeState(State *st);

    private:
        State *_state;

};

#endif  /*__CONTEXT_H__*/
