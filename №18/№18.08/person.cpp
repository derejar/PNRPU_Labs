#include <iostream>
#include "person.h"

Person::Person()
{
    name = "";
    age = 0;
}

Person::Person(std::string n, int a)
{
    name = n;
    age = a;
}

Person::~Person(){}

void Person::show()
{
    std::cout << "Имя: " << name << std::endl << "Возраст: " << age << std::endl;
}

void Person::input()
{
    std::cout << "Введите имя: ";
    std::cin >> name;
    std::cout << "Введите возраст: ";
    std::cin >> age;
}

std::string Person::getName()
{
    return name;
}

int Person::getAge()
{
    return age;
}

void Person::setName(std::string n)
{
    name = n;
}

void Person::setAge(int a)
{
    age = a;
}

Person &Person::operator=(const Person &temp)
{
    name = temp.name;
    age = temp.age;
    return *this;
}