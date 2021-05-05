#include "pair.h"

Pair::Pair()
{
    first = 0;
    second = 0;
}

Pair::Pair(int a, int b)
{
    first = a;
    second = b;
}

Pair::~Pair(){}

void Pair::setFirst(int a)
{
    first = a;
}

void Pair::setSecond(int a)
{
    second = a;
}

int Pair::getFirst()
{
    return first;
}

int Pair::getSecond()
{
    return second;
}

Pair &Pair::operator=(const Pair &a)
{
    if(this==&a)
    {
        return *this;
    }
    first = a.first;
    second = a.second;
    return *this;
}

Pair Pair::operator+(Pair a)
{
    Pair temp;
    temp.first = first + a.first;
    temp.second = second + a.second;
    return temp;
}

std::istream &operator>>(std::istream &in, Pair &a)
{
    std::cout << "Введите первое число пары: ";
    std::cin >> a.first;
    std::cout << "Введите второе число пары: ";
    std::cin >> a.second;
    return in;
}

std::ostream &operator<<(std::ostream &out, const Pair &a)
{
    return (std::cout << a.first << ":" << a.second);
}