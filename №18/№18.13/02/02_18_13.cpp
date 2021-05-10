#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include "money.h"

using namespace std;

struct comp
{
    bool operator()(Money a, Money b)
    {
        if(a > b)
        {
            return true;
        }
        return false;
    }
};

stack<Money> create(int count)
{
    Money a;
    stack<Money> temp;
    for(int i=0; i<count; i++)
    {
        cin >> a;
        temp.push(a);
    }
    return temp;
}

vector<Money> toVector(stack<Money> temp)
{
    vector<Money> a;
    while(!temp.empty())
    {
        a.push_back(temp.top());
        temp.pop();
    }
    return a;
}

stack<Money> toStack(vector<Money> temp)
{
    stack<Money> a;
    for(int i=temp.size()-1; i>=0; i--)
    {
        a.push(temp[i]);
    }
    return a;
}

stack<Money> plusAverange(stack<Money> temp, Money avg)
{
    vector<Money> a;
    while(!temp.empty())
    {
        a.push_back((temp.top()+avg));
        temp.pop();
    }
    temp = toStack(a);
    return temp;
}

void print(stack<Money> temp)
{
    while(!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

void search(stack<Money> temp)
{
    cout << "Задайте элемент для поиска: " << endl;
    Money search;
    cin >> search;
    bool isFinded = false;
    while(!temp.empty() && isFinded == false) 
    {
        if(temp.top() == search)
        {
            cout << "Элемент найден: " << temp.top() << endl;
            isFinded = true;
        }
        temp.pop();
    }
    if(isFinded == false)
    {
        cout << "Элемент не найден!" << endl;
    }
}

Money getAvg(stack<Money> temp)
{
    Money avg;
    int a = temp.size();
    while(!temp.empty())
    {
        avg = avg + temp.top();
        temp.pop();
    }
    avg = avg / a;
    return avg;
}

int main()
{
    cout << "Введите размер контейнера: ";
    int n;
    cin >> n;
    stack<Money> test = create(n);
    cout << "Созданный контейнер: " << endl;
    print(test);
    cout << "Добавление максимального элемента в начало контейнера: " << endl;
    vector<Money> temp = toVector(test);
    vector<Money>::iterator it;
    it = max_element(temp.begin(), temp.end());
    temp.insert(temp.begin(), *(it));
    test = toStack(temp);
    print(test);
    cout << "Контейнер, отсортированный по возрастанию: " << endl;
    sort(temp.begin(), temp.end());
    test = toStack(temp);
    print(test);
    cout << "Контейнер, отсортированный по убыванию: " << endl;
    sort(temp.begin(), temp.end(), comp());
    test = toStack(temp);
    print(test);
    cout << "Контейнер после удаления минимального элемента: " << endl;
    it = min_element(temp.begin(), temp.end());
    temp.erase(it);
    test = toStack(temp);
    print(test);
    search(test);
    cout << "Контейнер после добавления к элементам среднего арифметического контейнера: " << endl;
    Money avg = getAvg(test);
    test = plusAverange(test, avg);
    print(test);
}