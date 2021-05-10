#pragma once
#include "money.h"

Money &Money::operator=(const Money &a)
{
    if(&a == this)
    {
        return *this;
    }
    rub = a.rub;
    penny = a.penny;
    return *this;
}

Money Money::operator+(Money a)
{
    Money temp;
    temp.rub = rub + a.rub;
    temp.penny = penny + a.penny;
    temp.checkCorrect();
    return temp;
}

Money Money::operator-(Money a)
{
    Money temp;
    temp.rub = rub - a.rub;
    temp.penny = penny - a.penny;
    if(temp.penny < 0)
    {
        temp.rub--;
        temp.penny += 100;
    }
    temp.checkCorrect();
    return temp;
}

Money Money::operator/(int temp)
{
    Money t;
    t.rub = rub/temp;
    t.penny = penny/temp;
    return t;
}

bool Money::operator==(const Money &temp)
{
    if(rub == temp.rub && penny == temp.penny)
    {
        return true;
    }
    return false;
}

bool Money::operator!=(const Money &temp)
{
    if(rub == temp.rub && penny == temp.penny)
    {
        return false;
    }
    return true;
}

bool Money::operator>(const Money &temp)
{
    if(rub > temp.rub)
    {
        return true;
    }
    else if(rub == temp.rub && penny > temp.penny)
    {
        return true;
    }
    return false;
}

bool Money::operator<(const Money &temp)
{
    if(rub < temp.rub)
    {
        return true;
    }
    else if(rub == temp.rub && penny < temp.penny)
    {
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &out, const Money &temp)
{
    out << temp.rub << ",";
    if(temp.penny < 10)
    {
        out << 0 << temp.penny;
    }
    else
    {
        out << temp.penny;
    }
    return out;
}

std::istream &operator>>(std::istream &in, Money &temp)
{
    std::cout << "Введите количество рублей: ";
    std::cin >> temp.rub;
    std::cout << "Введите количество копеек: ";
    std::cin >> temp.penny;
    std::cout << std::endl;
    temp.checkCorrect();
    return in;  
}