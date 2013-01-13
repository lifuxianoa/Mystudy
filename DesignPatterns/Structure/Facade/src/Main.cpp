/*
 * =====================================================================================
 *
 *       Filename:  Main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月13日 10时40分48秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Facade.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    Facade f;
    f.OperationWrapper();
    return 0;
}
