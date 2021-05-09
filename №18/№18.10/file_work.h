#include <iostream>
#include <fstream>
#include <string>
#include "money.h"

int makeFile(const char *fileName)
{
    std::fstream file(fileName, std::ios::out|std::ios::trunc);
    if(!file)
    {
        return -1;
    }
    int n;
    std::cout << "Введите количество объектов для добавления: ";
    std::cin >> n;
    Money temp;
    for(int i=0; i<n; i++)
    {
        std::cin >> temp;
        file << temp << std::endl;
    }
    file.close();
    return n;
}

int printFile(const char *fileName)
{
    std::fstream file(fileName, std::ios::in);
    if(!file)
    {
        return -1;
    }
    Money temp;
    int i=0;
    while(file >> temp)
    {
        std::cout << temp << std::endl;
        i++;
    }
    file.close();
    return i;
}

int delElementsFromFile(const char *fileName, Money delValue)
{
    std::fstream temp("temp", std::ios::out);
    std::fstream file(fileName, std::ios::in);
    if(!file)
    {
        return -1;
    }
    Money t;
    int i=0;
    while(file >> t)
    {
        if(file.eof())
        {
            break;
        }
        if(t != delValue)
        {
            temp << t << std::endl;
        }
        i++;
    }
    file.close();
    temp.close();
    remove(fileName);
    rename("temp", fileName);
    return i;
}

int addElements(const char *fileName, int number, int k)
{
    std::fstream temp("temp", std::ios::out);
    std::fstream file(fileName, std::ios::in);
    if(!file)
    {
        return -1;
    }
    Money t;
    int i=0;
    while(file >> t)
    {
        if(file.eof())
        {
            break;
        }
        temp << t << std::endl;
        i++;
        if(i==number)
        {
            for(int j=0; j<k; j++)
            {
                std::cin >> t;
                temp << t << std::endl;
            }
        }
    }
    file.close();
    temp.close();
    remove(fileName);
    rename("temp", fileName);
    return i;
}

int addToEnd(const char *fileName, int k)
{
    std::fstream file(fileName, std::ios_base::app);
    if(!file)
    {
        return -1;
    }
    Money temp;
    for(int i=0; i<k; i++)
    {
        std::cin >> temp;
        file << temp << std::endl;
    }
    file.close();
    return 1;
}

int changeInfo(const char *fileName, Money value)
{
    std::fstream temp("temp", std::ios::out);
    std::fstream file(fileName, std::ios::in);
    Money t;
    Money plus(1, 50);
    while(file >> t)
    {
        if(file.eof())
        {
            break;
        }
        if(t == value)
        {
            t = t + plus;
        }
        temp << t << std::endl;
    }
    file.close();
    temp.close();
    remove(fileName);
    rename("temp", fileName);
    return 1;
}