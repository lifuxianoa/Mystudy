/*
 * =====================================================================================
 *
 *       Filename:  Composite.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月10日 14时47分20秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#ifndef __COMPOSITE_H__
#define __COMPOSITE_H__

#include "Component.h"
#include <vector>
using namespace std;

class Composite:public Component
{
    public:
        Composite();
        ~Composite();
        void Operation();
        void Add(Component *com);
        void Remove(Component *com);
        Component* GetChild(int index);

    protected:

    private:
        vector<Component*> comVec;

};

#endif  /*__COMPOSITE_H__*/
