#pragma once
#include "pair.h"

class LONG : public Pair
{
    public:
        LONG(int, int);
        LONG();
        void show();
        LONG operator+(LONG);
        LONG operator-(LONG);
        LONG operator*(LONG);
        friend std::istream &operator>>(std::istream &in, LONG &a);
        friend std::ostream &operator<<(std::ostream &out, const LONG &a);
};