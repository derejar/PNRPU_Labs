#include <iostream>
#include <map>
#include "money.h"

using namespace std;

multimap<int, Money> create(int count); //Создание контейнера

void print(multimap<int, Money> temp); //Печать содержимого контейнера
void findAndAddMaxElement(multimap<int, Money> &temp); //Поиск максимального элемента и добавление его в начало контейнера
void delMinElement(multimap<int, Money> &temp); //Удаление минимального элемента из контейнера
void addArithmeticAverange(multimap<int, Money> &temp); //Добавление к элементам контейнера среднего арифметического контейнера

int main()
{
    multimap<int, Money> test;
    test = create(5);
    cout << "Создан контейнер: " << endl;
    print(test);
    cout << "Поиск максимального элемента и добавление его в начало контейнера: " << endl;
    findAndAddMaxElement(test);
    print(test);
    cout << "Удаление минимального элемента из контейнера: " << endl;
    delMinElement(test);
    print(test);
    cout << "Добавление ко всем элементам среднего арифметического контейнера: " << endl;
    addArithmeticAverange(test);
    print(test);
}

multimap<int, Money> create(int count)
{
    multimap<int, Money> temp;
    Money value;
    cout << "Введите значение для " << count << " элементов: " << endl;
    for(int i=0; i<count; i++)
    {
        cin >> value;
        temp.insert(make_pair(i, value));
    }
    return temp;
}

void print(multimap<int, Money> temp)
{
    multimap<int, Money>::iterator it = temp.begin();
    for(int i=0; i<temp.size(); i++)
    {
        cout << it->second << " ";
        it++;
    }
    cout << endl;
}

void findAndAddMaxElement(multimap<int, Money> &temp)
{
    multimap<int, Money>::iterator it = temp.begin();
    Money max = it->second;
    for(int i=0; i<temp.size(); i++)
    {
        if(max < it->second)
        {
            max = it->second;
        }
        it++;
    }
    temp.emplace_hint(temp.begin(), make_pair(0, max));
}

void delMinElement(multimap<int, Money> &temp)
{
    multimap<int, Money>::iterator it = temp.begin(), pos = it;
    Money min = it->second;
    for(int i=0; i<temp.size(); i++)
    {
        if(min > it->second)
        {
            min = it->second;
            pos = it;
        }
        it++;
    }
    temp.erase(pos);
}

void addArithmeticAverange(multimap<int, Money> &temp)
{
    multimap<int, Money>::iterator it = temp.begin();
    Money averange;
    for(int i=0; i<temp.size(); i++)
    {
        averange = averange + it->second;
        it++;
    }
    averange = averange / temp.size();
    it = temp.begin();
    for(int i=0; i<temp.size(); i++)
    {
        it->second = it->second + averange;
        it++;
    }
}
