#include <iostream>
#include "student.h"

Student::Student() : Person()
{
    rating = 0;
}

Student::Student(std::string n, int a, float r) : Person(n, a)
{
    rating = r;
}

std::string Student::getName()
{
    return name;
}

Student::~Student(){}

void Student::show()
{
    std::cout << "Имя: " << name << std::endl << "Возраст: " << age << std::endl << "Рейтинг: " << rating << std::endl;
}

void Student::input()
{
    std::cout << "Введите имя: ";
    std::cin >> name;
    std::cout << "Введите возраст: ";
    std::cin >> age;
    std::cout << "Введите рейтинг: ";
    std::cin >> rating;
}

float Student::getRating()
{
    return rating;
}

void Student::setRating(float r)
{
    rating = r;
}

Student &Student::operator=(const Student &temp)
{
    name = temp.name;
    age = temp.age;
    rating = temp.rating;
    return *this;
}