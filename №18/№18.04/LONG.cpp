#include "LONG.h"

LONG::LONG(int a, int b):Pair(a,b){};
LONG::LONG():Pair(){};

LONG LONG::operator-(LONG a)
{
    LONG temp;
    temp.first = first - a.first;
    temp.second = second - a.second;
    return temp;
}

LONG LONG::operator+(LONG a)
{
    LONG temp;
    temp.first = first + a.first;
    temp.second = second + a.second;
    return temp;
}

LONG LONG::operator*(LONG a)
{
    LONG temp;
    temp.first = first * a.first;
    temp.second = second * a.second;
    return temp;
}

std::ostream &operator<<(std::ostream &out, const LONG &a)
{
    return (std::cout << a.first << "_" << a.second);
}

std::istream &operator>>(std::istream &in, LONG &a)
{
    std::cout << "Введите первую часть числа: ";
    std::cin >> a.first;
    std::cout << "Введите вторую часть числа: ";
    std::cin >> a.second;
    return in;
}