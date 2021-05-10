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
        data.push(temp);
    }
}

template<class T>
Multiple<T>::~Multiple(){}

template<class T>
std::stack<T> Multiple<T>::toStack(std::vector<T> temp)
{
    std::stack<T> st;
    for(int i=temp.size()-1; i>=0; i--)
    {
        st.push(temp[i]);
    }
    return st;
}

template<class T>
std::vector<T> Multiple<T>::toVec(std::stack<T> temp)
{
    std::vector<T> vecT;
    while(!temp.empty())
    {
        vecT.push_back(temp.top());
        temp.pop();
    }
    return vecT;
}

template<class T>
void Multiple<T>::print()
{
    std::vector<T> a = toVec(data);
    while(!data.empty())
    {
        std::cout << data.top() << " | ";
        data.pop();
    }
    std::cout << std::endl;
    data = toStack(a);
}

template<class T>
void Multiple<T>::findAndAddMax()
{
    std::vector<T> a = toVec(data);
    T max = data.top();
    while(!data.empty())
    {
        if(data.top() > max)
        {
            max = data.top();
        }
        data.pop();
    }
    a.insert(a.cbegin(), max);
    data = toStack(a);
}

template<class T>
void Multiple<T>::delMinElementFromVector()
{
    std::vector<T> a = toVec(data);
    T min = data.top();
    int pos = 0;
    int i = 0;
    while(!data.empty())
    {
        if(data.top() < min)
        {
            min = data.top();
            pos = i;
        }
        data.pop();
        i++;
    }
    a.erase(a.cbegin()+pos);
    data = toStack(a);
}

template<class T>
void Multiple<T>::addArithmeticAverange()
{
    std::vector<T> a = toVec(data);
    int size = data.size();
    T averange;
    while(!data.empty())
    {
        averange = averange + data.top();
        data.pop();
    }
    averange = averange / size;
    for(int i=0; i<a.size(); i++)
    {
        a[i] = a[i] + averange;
    }
    data = toStack(a);
}
