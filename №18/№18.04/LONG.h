#pragma once
#include "pair.h"

class LONG : public Pair
{
    private:
        int countOfZeros;

        int getLength(int);
        int correctLengthByOneNum(int &, int &);
    public:
        LONG(int, int);
        LONG();
        LONG operator+(LONG);
        LONG operator-(LONG);
        LONG operator*(LONG);
        friend std::istream &operator>>(std::istream &in, LONG &a);
        friend std::ostream &operator<<(std::ostream &out, const LONG &a);
};