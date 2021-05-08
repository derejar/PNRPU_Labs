#pragma once
#include <string>
#include "object.h"

class Person : public Object
{
    protected:
        std::string name;
        int age;
    public:
        Person();
        Person(std::string, int);
        Person(const Person &);
        virtual ~Person();
        void show();
        void input();
        std::string getName();
        int getAge();
        void setName(std::string);
        void setAge(int);
        Person &operator=(const Person &);
};
#include "person.cpp"