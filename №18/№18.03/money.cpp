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
    return temp;
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
