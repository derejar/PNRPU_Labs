#pragma once
class Object
{
    public:
        Object(){}
        virtual ~Object(){}
        virtual void show() = 0;
        virtual void input() = 0;
};