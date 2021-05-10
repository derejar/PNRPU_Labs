#include <iostream>
#include <map>
#include "multiple.h"

template<class T>
Multiple<T>::Multiple(){}

template<class T>
Multiple<T>::Multiple(int s)
{
    T value;
    std::cout << "Введите значения для " << s << " элементов: " << std::endl; 
    for(int i=0; i<s; i++)
    {
        std::cin >> value;
        data.insert(std::make_pair(i, value));
    }
}

template<class T>
Multiple<T>::~Multiple(){}

template<class T>
void Multiple<T>::print()
{
    typename std::multimap<int, T>::iterator it = data.begin();
    for(int i=0; i<data.size(); i++)
    {
        std::cout << it->second << " ";
        it++;
    }
    std::cout << std::endl;
}

template<class T>
void Multiple<T>::findAndAddMaxElement()
{
    typename std::multimap<int, T>::iterator it = data.begin();
    T max = it->second;
    for(int i=0; i<data.size(); i++)
    {
        if(max < it->second)
        {
            max = it->second;
        }
        it++;
    }
    data.emplace_hint(data.begin(), std::make_pair(0, max));
}


template<class T>
void Multiple<T>::delMinElement()
{
    typename std::multimap<int, T>::iterator it = data.begin(), pos = it;
    T min = it->second;
    for(int i=0; i<data.size(); i++)
    {
        if(min > it->second)
        {
            min = it->second;
            pos = it;
        }
        it++;
    }
    data.erase(pos);
}

template<class T>
void Multiple<T>::addArithmeticAverange()
{
    typename std::multimap<int, T>::iterator it = data.begin();
    T averange;
    for(int i=0; i<data.size(); i++)
    {
        averange = averange + it->second;
        it++;
    }
    averange = averange / data.size();
    it = data.begin();
    for(int i=0; i<data.size(); i++)
    {
        it->second = it->second + averange;
        it++;
    }
}
