#pragma once
#include <iostream>
#include <vector>
#include <stack>

const int MAX_SIZE = 15;
template<class T>

class Multiple
{
    protected:
        std::stack<T> data;
    public:
        Multiple();
        Multiple(int);
        ~Multiple();
        std::stack<T> toStack(std::vector<T>);
        std::vector<T> toVec(std::stack<T>);
        void print();
        void findAndAddMax();
        void delMinElementFromVector();
        void addArithmeticAverange();
};
#include "multiple.cpp"