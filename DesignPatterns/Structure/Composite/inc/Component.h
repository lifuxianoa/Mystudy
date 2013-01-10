/*
 * =====================================================================================
 *
 *       Filename:  Component.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月10日 14时13分20秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#ifndef __COMPONENT_H__
#define __COMPONENT_H__

class Component
{
    public:
        Component();
        virtual ~Component();
        virtual void Operation() = 0;
        virtual void Add(const Component &com);
        virtual void Remove(const Component &com);
        virtual Component* GetChild(int index);

    protected:

    private:

};

#endif  /*__COMPONENT_H__*/
