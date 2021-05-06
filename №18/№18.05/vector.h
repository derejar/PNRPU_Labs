#pragma once
#include "object.h"
#include <iostream>
#include <string>

class Vector
{
    private:
        Object **ptrOnFirst;
        int size;
        int currentPosition;
    public:
        Vector();
        Vector(int);
        ~Vector();
        void add(Object *);
        friend std::ostream &operator<<(std::ostream &out, const Vector &);
};