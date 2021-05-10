#include <iostream>
#include <vector>
#include <algorithm>
#include "money.h"

using namespace std;

Money s;
Money avg;

vector<Money> create(int count)
{
    vector<Money> temp;
    Money t;
    for(int i=0; i<count; i++)
    {
        cin >> t;
        temp.push_back(t);
    }
    return temp;
}

Money averange(vector<Money> temp)
{
    Money a;
    for(int i=0; i<temp.size(); i++)
    {
        a = a + temp[i];
    }
    a = a / temp.size();
    return a;
}

void print(vector<Money> temp)
{
    for(int i=0; i<temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
}

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

struct equal_s
{
    bool operator()(Money a)
    {
        return a==s;
    }
};

struct plus_avg
{
    Money operator()(Money &a)
    {
        a = a + avg;
        return a;
    }
};

int main()
{
    vector<Money> test;
    cout << "Введите размер создаваемого контейнера: ";
    int count;
    cin >> count;
    test = create(count);
    cout << "Созданный контейнер: " << endl;
    print(test);
    vector<Money>::iterator it;
    cout << "Добавление максимального элемента в начало контейнера: " << endl;
    it = max_element(test.begin(), test.end());
    test.insert(test.cbegin(), *(it));
    print(test);
    cout << "Контейнер, отсортированный по возрастанию: " << endl;
    sort(test.begin(), test.end());
    print(test);
    cout << "Контейнер, отсортированный по убыванию: " << endl;
    sort(test.begin(), test.end(), comp());
    print(test);
    cout << "Контейнер после удаления минимального элемента: " << endl;
    it = min_element(test.begin(), test.end());
    test.erase(it);
    print(test);
    cout << "Задайте элемент для поиска: " << endl;
    cin >> s;
    it = find_if(test.begin(), test.end(), equal_s());
    if(it!=test.end())
    {
        cout << "Элемент найден: " << *(it) << endl;
    }
    else
    {
        cout << "Элемент не найден!" << endl;
    }
    cout << "Контейнер, после добавления к элементам среднего арифметического контейнера: " << endl;
    avg = averange(test);
    for_each(test.begin(), test.end(), plus_avg());
    print(test);
}