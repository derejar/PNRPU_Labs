#include <iostream>
#include <stack>
#include <vector>
#include "money.h"

using namespace std;

stack<Money> makeStack(int count); //Создание стека
stack<Money> toStack(vector<Money> temp); //Сохранение стека в векторе

vector<Money> toVec(stack<Money> temp); //Восстановление стека из вектора

void print(stack<Money> &temp); //Печать стека
void findAndAddMax(stack<Money> &temp); //Поиск максимального элемента в стеке и добавление его на вершину стека
void delMinElementFromVector(stack<Money> &temp); //Удаление минимального элемента из стека
void addArithmeticAverange(stack<Money> &temp); //Добавление ко всем элементам стека среднего арифметического

int main()
{
    stack<Money> test;
    test = makeStack(5);
    cout << "Создан стек: " << endl;
    print(test);
    cout << "Максимальный элемент добавлен в начало стека: " << endl;
    findAndAddMax(test);
    print(test);
    cout << "Минимальный элемент удален из стека: " << endl;
    delMinElementFromVector(test);
    print(test);
    cout << "Ко всем элементам прибавлено среднее арифметическое стека: " << endl;
    addArithmeticAverange(test);
    print(test);
}

stack<Money> makeStack(int count)
{
    stack<Money> temp;
    Money a;
    for(int i=0; i<count; i++)
    {
        cin >> a;
        temp.push(a);
    }
    return temp;
}

stack<Money> toStack(vector<Money> temp)
{
    stack<Money> st;
    for(int i=temp.size()-1; i>=0; i--)
    {
        st.push(temp[i]);
    }
    return st;
}

vector<Money> toVec(stack<Money> temp)
{
    vector<Money> vecT;
    while(!temp.empty())
    {
        vecT.push_back(temp.top());
        temp.pop();
    }
    return vecT;
}

void print(stack<Money> &temp)
{
    vector<Money> a = toVec(temp);
    while(!temp.empty())
    {
        cout << temp.top() << " | ";
        temp.pop();
    }
    cout << endl;
    temp = toStack(a);
}

void findAndAddMax(stack<Money> &temp)
{
    vector<Money> a = toVec(temp);
    Money max = temp.top();
    while(!temp.empty())
    {
        if(temp.top() > max)
        {
            max = temp.top();
        }
        temp.pop();
    }
    a.insert(a.cbegin(), max);
    temp = toStack(a);
}

void delMinElementFromVector(stack<Money> &temp)
{
    vector<Money> a = toVec(temp);
    Money min = temp.top();
    int pos = 0;
    int i = 0;
    while(!temp.empty())
    {
        if(temp.top() < min)
        {
            min = temp.top();
            pos = i;
        }
        temp.pop();
        i++;
    }
    a.erase(a.cbegin()+pos);
    temp = toStack(a);
}

void addArithmeticAverange(stack<Money> &temp)
{
    vector<Money> a = toVec(temp);
    int size = temp.size();
    Money averange;
    while(!temp.empty())
    {
        averange = averange + temp.top();
        temp.pop();
    }
    averange = averange / size;
    for(int i=0; i<a.size(); i++)
    {
        a[i] = a[i] + averange;
    }
    temp = toStack(a);
}