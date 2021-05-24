#include "stack.h"

template <class T>
Stack<T>::Stack()
{
    t = nullptr;
}

template <class T>
T Stack<T>::top()
{
    if(t == nullptr)
    {
        return 0;
    }
    return t->data;
}

template <class T>
bool Stack<T>::empty()
{
    if(t == nullptr)
    {
        return true;
    }
    return false;
}

template <class T>
int Stack<T>::size()
{
    return s;
}

template <class T>
void Stack<T>::push(T a)
{
    if(t == nullptr)
    {
        t = new Node<T>;
        t->data = a;
        t->prev = nullptr;
    }
    else
    {
        Node<T> *temp = t;
        t = new Node<T>;
        t->data = a;
        t->prev = temp;
    }
    s++;
}

template <class T>
void Stack<T>::emplace(T a)
{
    t->data = a;
}

template <class T>
void Stack<T>::pop()
{
    if(t != nullptr)
    {
        Node<T> *temp = t->prev;
        t = temp;
        s--;
    }
}