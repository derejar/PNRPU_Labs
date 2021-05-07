#include "multiple.h"

template <class T>
Multiple<T>::Multiple(int s)
{
    size = s;
    data = new T[size];
    for(int i=0; i<size; i++)
    {
        data[i] = 0;
    }
}

template <class T>
Multiple<T>::Multiple(const Multiple<T> &a)
{
    size = a.size;
    data = new T[size];
    for(int i=0; i<size; i++)
    {
        data[i] = a.data[i];
    }
}

template <class T>
Multiple<T>::~Multiple()
{
    delete[] data;
    data = 0;
}

template <class T>
Multiple<T> &Multiple<T>::operator=(const Multiple<T> &a)
{
    if(this == &a)
    {
        return *this;
    }
    if(data !=0)
    {
        delete[] data;
    }
    size = a.size;
    data = new T[size];
    for(int i=0; i<size; i++)
    {
        data[i] = a.data[i];
    }
    return *this;
}

template <class T>
T &Multiple<T>::operator[](int index)
{
    if(index < size)
    {
        return data[index];
    }
    else
    {
        std::cout << std::endl << "Ошибка! Выполнено обращение к элементу вне множества!" << std::endl;
    }
    return data[index];
}

template <class T>
Multiple<T> &Multiple<T>::operator+(Multiple<T> second)
{
    Multiple<T> *temp = new Multiple<T>(size+second.size);
    for(int i=0; i<size; i++)
    {
        temp->data[i] = data[i];
    }
    for(int i=size; i<size+second.size; i++)
    {
        temp->data[i] = second.data[i-size];
    }
    return *temp;
}

template <class T>
int Multiple<T>::operator()()
{
    return size;
}

template <class T>
std::ostream &operator<< (std::ostream &out, const Multiple<T> &temp)
{
    for(int i=0; i<temp.size; i++)
    {
        out << temp.data[i] << " ";
    }
    return out;
}

template <class T>
std::istream &operator>>(std::istream &in, Multiple<T> &temp)
{
    for(int i=0; i<temp.size; i++)
    {
        if(temp.data[i]==0)
        {
            in >> temp.data[i];
        }
    }
    return in;
}