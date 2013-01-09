/*
 * =====================================================================================
 *
 *       Filename:  Main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月09日 15时18分38秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include    "Director.h"

int main(int argc, char *argv[])
{
    ConcreteBuilder cb;
    Director d = Director(&cb);

    d.Construct();

    return 0;
}
