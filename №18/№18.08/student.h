#pragma once
#include "person.h"

class Student : public Person
{
    protected:
        float rating;
    public:
        Student();
        Student(std::string, int, float);
        virtual ~Student();
        void show();
        void input();
        std::string getName();
        float getRating();
        void setRating(float);
        Student &operator=(const Student &);
};
#include "student.cpp"