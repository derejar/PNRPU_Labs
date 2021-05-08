#pragma once
#include "object.h"

struct Node
{
    Object *data;
    Node *next;
};

class List
{
    protected:
        Node *start;
        Node *currentPosition;
        int size;
    public:
        List();
        void add();
        void del();
        void show();
        void getInfo(int);
};
#include "list.cpp"