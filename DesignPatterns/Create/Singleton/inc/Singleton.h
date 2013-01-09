/*
 * =====================================================================================
 *
 *       Filename:  Singleton.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/07/2013 09:05:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

//Singleton

#ifndef __SINGLETON_H__
#define __SINGLETON_H__

class Singleton
{
    public:
        ~Singleton();
        static Singleton* Instance();

    protected:
        Singleton();
        static Singleton _instance;

    private:
};

#endif //~__SINGLETON_H__
