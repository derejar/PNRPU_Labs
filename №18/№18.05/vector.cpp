#include "vector.h"

Vector::Vector()
{
    ptrOnFirst = 0;
    size = 0;
    currentPosition = 0;
}

Vector::Vector(int n)
{
    ptrOnFirst = new Object*[n];
    size = n;
    currentPosition = 0;
}

Vector::~Vector()
{
    if(ptrOnFirst!=0)
    {
        delete[] ptrOnFirst;
    }
    ptrOnFirst = 0;
}

void Vector::add(Object *p)
{
    if(currentPosition < size)
    {
        ptrOnFirst[currentPosition] = p;
        currentPosition++;
    }
}

std::ostream &operator<<(std::ostream &out, const Vector &a)
{
    if(a.size == 0)
    {
        out << "Пусто" << std::endl;
    }
    Object **p = a.ptrOnFirst;
    for(int i=0; i<a.currentPosition; i++)
    {
        (*p)->show();
        p++;
    }
    return out;
}