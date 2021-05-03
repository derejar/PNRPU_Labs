#pragma once

#include <iostream>
#include <string>

class country
{
    std::string capital;
    int countOfResidents;
    double area;

    public:
        country();
        country(std::string, int, double);
        country(const country&);
        ~country();
        std::string getCapital();
        void setCapital(std::string);
        int getCountOfResidents();
        void setCountOfResidents(int);
        double getArea();
        void setArea(double);
        void show();
};