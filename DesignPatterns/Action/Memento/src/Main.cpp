/*
 * =====================================================================================
 *
 *       Filename:  Main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月21日 14时04分45秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Memento.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    Originator ori = Originator();
    ori.SetState("old"); //备忘前状态
    ori.PrintState();

    Memento *men = ori.CreateMemento(); //将状态备忘
    ori.SetState("new"); //修改状态
    ori.PrintState();
    ori.RestoreToMemento(men); //恢复修改前状态
    ori.PrintState();
    ori.DistoryMemento(men);

    return 0;
}

