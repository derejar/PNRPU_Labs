#include "fraction.h"
#include <iostream>

void fraction::init(double a, double b)
{
    first = a;
    second = b; 
}

void fraction::read()
{
    std::cout << "y=Ax+B" << std::endl;
    std::cout << "A=";
    std::cin >> first;
    std::cout << "B=";
    std::cin >> second;
}

void fraction::show()
{
    std::cout << "y = " << first << "x + " << second << std::endl;
}

void fraction::root()
{
    if(first==0)
    {
        std::cout << "Коэффициент при х равен нулю, корень не существует" << std::endl << std::endl;
    }
    else
    {
        std::cout << "x = " << (-1*(second/first)) << std::endl << std::endl;
    }
}