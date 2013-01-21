/*
 * =====================================================================================
 *
 *       Filename:  Memento.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月21日 13时47分42秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#ifndef __MEMENTO_H__
#define __MEMENTO_H__

#include <string>
using namespace std;

class Memento;
class Originator
{
    public:
        typedef string State;
        Originator();
        Originator(const State &st);
        ~Originator();
        Memento* CreateMemento();
        void DistoryMemento(Memento *men);
        void SetMemento(Memento* men);
        void RestoreToMemento(Memento *mt);
        State GetState();
        void SetState(const State &st);
        void PrintState();

    protected:

    private:
        State _st;
        Memento *_mt;

};

class Memento
{
    public:

    protected:

    private:
        friend class Originator; //这是最关键的地方，将Originator定义为friend类，可以访问
                                //内部信息，但是其他类不能访问。
        typedef string State;
        Memento();
        Memento(const State &st);
        ~Memento();
        void SetState(const State &st);
        State GetState();
        State _st;

};

#endif  /*__MEMENTO_H__*/
