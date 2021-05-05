#pragma once
#include <iostream>

class Pair
{
    protected:
        int first;
        int second;
    public:
        Pair();
        Pair(int, int);
        ~Pair();
        void setFirst(int);
        void setSecond(int);
        int getFirst();
        int getSecond();
        Pair &operator=(const Pair &);
        virtual Pair operator+(Pair);
        friend std::istream &operator>>(std::istream &in, Pair &a);
        friend std::ostream &operator<<(std::ostream &out, const Pair &a);
};