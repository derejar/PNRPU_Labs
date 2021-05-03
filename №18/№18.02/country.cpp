#include <iostream>
#include <string>
#include "country.h"

country::country()
{
    capital = "";
    countOfResidents = 0;
    area = 0;
    std::cout << "Конструктор без параметров для объекта: " << this << std::endl;
}

country::country(std::string n, int k, double s)
{
    capital = n;
    countOfResidents = k;
    area = s;
    std::cout << "Конструктор с параметрами для объекта: " << this << std::endl;
}

country::country(const country &temp)
{
    capital = temp.capital;
    countOfResidents = temp.countOfResidents;
    area = temp.area;
    std::cout << "Конструктор копирования для объекта: " << this << std::endl; 
}

country::~country()
{
    std::cout << "Деструктор для объекта " << this << std::endl;
}

std::string country::getCapital()
{
    return capital;
}

int country::getCountOfResidents()
{
    return countOfResidents;
}

double country::getArea()
{
    return area;
}

void country::setCapital(std::string n)
{
    capital = n;
}

void country::setCountOfResidents(int k)
{
    countOfResidents = k;
}

void country::setArea(double s)
{
    area = s;
}

void country::show()
{
    std::cout << "Название столицы: " << capital << std::endl;
    std::cout << "Количество жителей: " << countOfResidents << " тысяч." << std::endl;
    std::cout << "Площадь страны: " << area << " тысяч." << std::endl;
}