#pragma once
#include <iostream>

class Money
{
    private:
        void checkCorrect()
        {
            if(penny >= 100)
            {
                int temp = penny/100;
                rub += temp;
                penny %= 100;
            }
        }
    protected:
        long rub;
        int penny;
    public:
        Money()
        {
            rub = 0.0;
            penny = 0;
        }

        Money(long a, int b)
        {
            rub = a;
            penny = b;
            checkCorrect();
        }
        ~Money(){};
        void setRub(long a)
        {
            rub = a;
        }
        void setPenny(int a)
        {
            penny = a;
            checkCorrect();
        }
        long getRub()
        {
            return rub;
        }
        int getPenny()
        {
            return penny;
        }
        void generateRandomValue()
        {
            rub = rand()%10000;
            penny = rand()%100;
            checkCorrect();
        }
        Money operator+(Money);
        Money operator-(Money);
        Money operator/(int);
        Money &operator=(const Money &);
        bool operator==(const Money &);
        bool operator!=(const Money &);
        bool operator>(const Money &);
        bool operator<(const Money &);
        friend std::istream &operator>>(std::istream &, Money &);
        friend std::ostream &operator<<(std::ostream &, const Money &);
};
#include "money.cpp"