/*
 * =====================================================================================
 *
 *       Filename:  Leaf.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月10日 15时22分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#ifndef __LEAF_H__
#define __LEAF_H__

#include "Component.h"

class Leaf:public Component
{
    public:
        Leaf();
        ~Leaf();
        void Operation();

    protected:

    private:

};


#endif  /*__LEAF_H__*/
