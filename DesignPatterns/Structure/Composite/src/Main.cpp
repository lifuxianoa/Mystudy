/*
 * =====================================================================================
 *
 *       Filename:  Main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月10日 15时27分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Leaf.h"
#include "Composite.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    Leaf l1, l2;
    l1.Operation();
    l2.Operation();

    Composite com;
    com.Add(&l1);
    com.Add(&l2);
    cout << "aaaaaaaaaaaaaaaaaa" << endl;
    com.Operation();
    cout << "bbbbbbbbbbbbbbbbbb" << endl;

    Component *ll = com.GetChild(0);
    ll->Operation();

    return 0;
}
