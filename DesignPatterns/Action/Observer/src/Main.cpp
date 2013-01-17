/*
 * =====================================================================================
 *
 *       Filename:  Main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月17日 15时29分12秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Subject.h"
#include "Observer.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    ConcreteSubject *sub = new ConcreteSubject();
    Observer *obs1 = new ConcreteObserverA(sub);
    Observer *obs2 = new ConcreteObserverB(sub);

    sub->SetState("old");
    sub->Notify();
    sub->SetState("new");
    sub->Notify();

    delete obs2;
    delete obs1;
    delete sub;

    return 0;
}
