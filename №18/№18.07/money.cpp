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

Money &Money::operator=(const int a)
{
    rub = a;
    penny = 0;
    return *this;
}

bool Money::operator==(const int a)
{
    if(rub == a && penny == a)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::ostream &operator<<(std::ostream &out, const Money &temp)
{
    return (out << temp.rub << "," << temp.penny);
}

std::istream &operator>>(std::istream &in, Money &temp)
{
    std::cout << "Введите количество рублей: ";
    std::cin >> temp.rub;
    std::cout << "Введите количество копеек: ";
    std::cin >> temp.penny;
    temp.checkCorrect();
    return in;  
}
