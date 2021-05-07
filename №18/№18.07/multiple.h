#pragma once    
#include <iostream>

template <class T>
class Multiple
{
    protected:
        int size;
        T *data;
    public:
        Multiple(int);
        Multiple(const Multiple<T> &);
        ~Multiple();
        Multiple &operator=(const Multiple<T> &);
        T &operator[](int);
        Multiple &operator+(Multiple<T>);
        int operator()();
        template <typename U>
        friend std::ostream &operator<<(std::ostream &out, const Multiple<U> &);
        template <typename U>
        friend std::istream &operator>>(std::istream &in, Multiple<U> &);
};

#include "multiple.cpp"