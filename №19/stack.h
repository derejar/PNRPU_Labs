#pragma once
#include <iostream>

template <class T>
struct Node
{
    T data;
    Node<T> *prev;
};

template <class T>
class Stack
{
    public:
        Node<T> *t;
        Stack();
        T top();
        bool empty();
        int size();
        void push(T);
        void emplace(T);
        void pop();
    private:
        int s = 0;
};

#include "stack.cpp"