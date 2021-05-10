#include <iostream>
#include "multiple.h"

template<class T>
Multiple<T>::Multiple(){}

template<class T>
Multiple<T>::Multiple(int s)
{
    T temp;
    for(int i=0; i<s; i++)
    {
        std::cin >> temp;
        data.push_back(temp);
    }
}

template<class T>
Multiple<T>::~Multiple()
{
    data.clear();
}

template<class T>
void Multiple<T>::print()
{
    for(int i=0; i<data.size(); i++)
    {
        std::cout << data[i] << " | ";
    }
    std::cout << std::endl;
}

template<class T>
void Multiple<T>::findAndAddMax()
{
    T max = data[0];
    for(int i=0; i<data.size(); i++)
    {
        if(data[i] > max)
        {
            max = data[i];
        }
    }
    data.insert(data.cbegin(), max);
}

template<class T>
void Multiple<T>::delMinElementFromVector()
{
    T min = data[0];
    int pos = 0;
    for(int i=0; i<data.size(); i++)
    {
        if(data[i] < min)
        {
            min = data[i];
            pos = i;
        }
    }
    data.erase(data.cbegin()+pos);
}

template<class T>
void Multiple<T>::addArithmeticAverange()
{
    T averange;
    for(int i=0; i<data.size(); i++)
    {
        averange = averange + data[i];
    }
    int temp = data.size();
    averange = averange / temp;
    for(int i=0; i<data.size(); i++)
    {
        data[i] = data[i] + averange;
    }
}