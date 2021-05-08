#pragma once
#include <string>
class Object
{
    public:
        Object(){}
        virtual ~Object(){}
        virtual void show() = 0;
        virtual void input() = 0;
        virtual std::string getName() = 0;
};