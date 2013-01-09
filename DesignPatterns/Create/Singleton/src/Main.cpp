/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/07/2013 09:17:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Singleton.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    cout << "aaaaaaaaaa" << endl;
    Singleton *sgt = Singleton::Instance();
    cout << "bbbbbbbbbbb" << endl;

    sgt = sgt;
    return 0;
}
