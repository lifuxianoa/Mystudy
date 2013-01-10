/*
 * =====================================================================================
 *
 *       Filename:  Main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月10日 11时05分37秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Adapter.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    Adaptee ade;
    Adapter adt(&ade);
    adt.Request();

    return 0;
}
