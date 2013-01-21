/*
 * =====================================================================================
 *
 *       Filename:  Main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月21日 16时24分06秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Mediator.h"
#include "Colleage.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    ConcreteMediator m;
    ConcreteColleageA cA = ConcreteColleageA(&m);
    ConcreteColleageB cB = ConcreteColleageB(&m);
    m.IntroColleage(&cA, &cB);

    cA.SetState("oldA");
    cB.SetState("oldB");
    cA.Action();
    cB.Action();
    cout << endl;

    cA.SetState("newA");
    cA.Action();
    cB.Action();
    cout << endl;

    cB.SetState("oldB");
    cB.Action();
    cA.Action();

    return 0;
}
