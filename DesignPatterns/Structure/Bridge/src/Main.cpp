/*
 * =====================================================================================
 *
 *       Filename:  Main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月10日 10时06分28秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Abstraction.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    AbstractionImp *imp = new ConcreteAbstractionImpA();
    Abstraction *abs = new RefinedAbstraction(imp);
    abs->Operation();
    
    AbstractionImp *imp1 = new ConcreteAbstractionImpB();
    Abstraction *abs1 = new RefinedAbstraction(imp1);
    abs1->Operation();

    delete imp;
    delete abs;
    delete imp1;
    delete abs1;
}
