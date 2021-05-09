#pragma once
#include <iostream>

const int MAX_SIZE = 15;

class Multiple
{
    protected:
        int size;
        int *data;
    public:
        Multiple();
        Multiple(int, int);
        Multiple(const Multiple &);
        ~Multiple();
        Multiple &operator=(const Multiple &);
        Multiple &operator+(Multiple &);
        Multiple &operator++(int);
        int &operator[](int);
        int operator()();
        friend std::ostream &operator<<(std::ostream &out, const Multiple &);
        friend std::istream &operator>>(std::istream &in, Multiple &);
};
#include "multiple.cpp"