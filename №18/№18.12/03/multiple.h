#pragma once
#include <iostream>
#include <map>

template<class T>

class Multiple
{
    protected:
        std::multimap<int, T> data;
    public:
        Multiple();
        Multiple(int);
        ~Multiple();
        void print();
        void findAndAddMaxElement();
        void delMinElement();
        void addArithmeticAverange();
};
#include "multiple.cpp"