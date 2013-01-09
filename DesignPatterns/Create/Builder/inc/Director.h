/*
 * =====================================================================================
 *
 *       Filename:  Director.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月09日 15时12分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#ifndef __DIRECTORY_H__
#define __DIRECTORY_H__

#include    "Builder.h"

class Director
{
    public:
        Director(Builder *bld);
        ~Director();
        void Construct();

    protected:

    private:
        Builder *_bld;

};

#endif //~__DIRECTORY_H__
