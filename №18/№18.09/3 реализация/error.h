#pragma once
#include <iostream>

class Error
{
    public:
        virtual void what(){};
};

class SizeError : public Error
{
    protected:
        std::string msg;
    public:
        SizeError() { msg = "Ошибка в размере множества!"; }
        virtual void what(){ std::cout << msg << std::endl; }
};

class MaxSizeError : public Error
{
    protected:
        std::string msg;
    public:
        MaxSizeError() { msg = "Ошибка! Превышен максимальный размер множества!"; }
        virtual void what(){ std::cout << msg << std::endl; }
};

class IndexErrorNegative : public Error
{
    protected:
        std::string msg;
    public:
        IndexErrorNegative() { msg = "Ошибка! Индекс меньше нуля!"; }
        virtual void what(){ std::cout << msg << std::endl; }
};

class IndexErrorTooMuch : public Error
{
    protected:
        std::string msg;
    public:
        IndexErrorTooMuch() { msg = "Ошибка! Индекс больше размера множества!"; }
        virtual void what(){ std::cout << msg << std::endl; }
};