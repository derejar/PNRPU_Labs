#pragma once
#include <iostream>
#include <vector>

const int MAX_SIZE = 15;
template<class T>

class Multiple
{
    protected:
        std::vector<T> data;
    public:
        Multiple();
        Multiple(int);
        ~Multiple();
        void print();
        void findAndAddMax();
        void delMinElementFromVector();
        void addArithmeticAverange();
};
#include "multiple.cpp"