/*
 * =====================================================================================
 *
 *       Filename:  Decorator.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年01月10日 13时27分33秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lifuxian (Li Fuxian), lifuxianoa@163.com
 *        Company:  Feixun Corp.
 *
 * =====================================================================================
 */

#include "Decorator.h"
#include <iostream>
using namespace std;

Component::Component()
{
    cout << "Component constructor..." << endl;
}

Component::~Component()
{
    cout << "Component distructor..." << endl;
}

void Component::Operation()
{
    cout << "Component Operation" << endl;
}

ConcreteComponent::ConcreteComponent()
{
    cout << "ConcreteComponent constructor..." << endl;
}

ConcreteComponent::~ConcreteComponent()
{
    cout << "ConcreteComponent distructor..." << endl;
}

void ConcreteComponent::Operation()
{
    cout << "ConcreteComponent Operation..." << endl;
}

Decorator::Decorator(Component *com)
{
    cout << "Decorator constructor..." << endl;
    _com = com;
}

Decorator::~Decorator()
{
    cout << "Decorator distructor..." << endl;
}

void Decorator::Operation()
{
    cout << "Decorator Operation..." << endl;
}

ConcreteDecorator::ConcreteDecorator(Component *com)
    :Decorator(com)
{
    cout << "ConcreteDecorator constructor..." << endl;
}

ConcreteDecorator::~ConcreteDecorator()
{
    cout << "ConcreteDecorator distructor..." << endl;
}

void ConcreteDecorator::AddedBehavior()
{
    cout << "ConcreteDecorator::AddedBehavior..." << endl;
}

void ConcreteDecorator::Operation()
{
    _com->Operation();
    AddedBehavior();
}

