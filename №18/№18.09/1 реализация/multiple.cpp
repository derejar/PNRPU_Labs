#include "multiple.h"

Multiple::Multiple(int s, int k=0)
{
    size = s;
    data = new int[size];
    for(int i=0; i<size; i++)
    {
        data[i] = k;
    }
}

Multiple::Multiple(const Multiple &a)
{
    size = a.size;
    data = new int[size];
    for(int i=0; i<size; i++)
    {
        data[i] = a.data[i];
    }
}

Multiple::~Multiple()
{
    delete[] data;
    data = 0;
}

Multiple &Multiple::operator=(const Multiple &a)
{
    if(this == &a)
    {
        return *this;
    }
    if(data != 0)
    {
        delete[] data;
    }
    data = new int[size]{0};
    for(int i=0; i<a.size; i++)
    {
        data[i] = a.data[i];
    }
    return *this;
}

Multiple &Multiple::operator+(Multiple &second)
{
    if(size+second.size > MAX_SIZE)
    {
        throw 3;
    }
    Multiple *temp = new Multiple(size+second.size);
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

Multiple &Multiple::operator++(int a)
{
    if((size + 1) > MAX_SIZE)
    {
        throw 1;
    }
    Multiple temp(size);
    for(int i=0; i<size; i++)
    {
        temp.data[i] = data[i];
    }
    delete[] data;
    size++;
    data = new int[size];
    for(int i=0; i<temp.size; i++)
    {
        data[i] = temp.data[i];
    }
    std::cout << "Введите элемент для добавления в множество: ";
    std::cin >> data[temp.size];
    return *this;
}

int &Multiple::operator[](int index)
{
    if(index >= size || index < 0)
    {
        throw 2;
    }
    return data[index];
}

int Multiple::operator()()
{
    return size;
}

std::ostream &operator<<(std::ostream &out, const Multiple &temp)
{
    for(int i=0; i<temp.size; i++)
    {
        out << temp.data[i] << " ";
    }
    return out;
}

std::istream &operator>>(std::istream &in, Multiple &temp)
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