#include "multiple.h"

Multiple::Multiple(int s, int k=0)
{
    size = s;
    data = new int[size];
    for(int i=0; i<size; i++)
    {
        data[i] = k;
    }
    start.element = &data[0];
    end.element = &data[size];
}

Multiple::Multiple(const Multiple &a)
{
    size = a.size;
    data = new int[size];
    for(int i=0; i<size; i++)
    {
        data[i] = a.data[i];
    }
    start = a.start;
    end = a.end;
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
    start = a.start;
    end = a.end;
    return *this;
}

Multiple &Multiple::operator+(Multiple &second)
{
    Multiple *temp = new Multiple(size+second.size);
    for(int i=0; i<size; i++)
    {
        temp->data[i] = data[i];
    }
    for(int i=size; i<size+second.size; i++)
    {
        temp->data[i] = second.data[i-size];
    }
    temp->start.element = &temp->data[0];
    temp->end.element = &temp->data[temp->size];
    return *temp;
}

int Multiple::operator[](int index)
{
    if(index < size)
    {
        return data[index];
    }
    else
    {
        std::cout << std::endl << "Ошибка! Выполнено обращение к элементу вне множества!" << std::endl;
    }
    return -2147483648;
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