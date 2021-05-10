#include <iostream>
#include <vector>
#include <time.h>
#include "money.h"

using namespace std;

vector<Money> makeVector(int count); //Создание вектора размера count

void print(vector<Money> temp); //Печать вектора в консоль
void findAndAddMax(vector<Money> &temp); //Поиск максимального элемента и добавление его в начало вектора
void delMinElementFromVector(vector<Money> &temp); //Удаление минимального элемента из вектора
void addArithmeticAverange(vector<Money> &temp); //Добавление ко всем элементам вектора среднее арифметическое

int main()
{
    srand(time(0));
    vector<Money> test;
    test = makeVector(10);
    cout << "Создан вектор: " << endl;
    print(test);
    findAndAddMax(test);
    cout << "Максимальный элемент добавлен в начало вектора: " << endl;
    print(test);
    delMinElementFromVector(test);
    cout << "Минимальный элемент удален из вектора: " << endl;
    print(test);
    cout << "Ко всем элементам прибавлено среднее арифметическое вектора: " << endl;
    addArithmeticAverange(test);
    print(test);
}

vector<Money> makeVector(int count)
{
    vector<Money> temp(count);
    for(int i=0; i<count; i++)
    {
        temp[i].generateRandomValue();
    }
    return temp;
}

void print(vector<Money> temp)
{
    for(int i=0; i<temp.size(); i++)
    {
        cout << temp[i] << " | ";
    }
    cout << endl;
}

void findAndAddMax(vector<Money> &temp)
{
    Money max = temp[0];
    for(int i=0; i<temp.size(); i++)
    {
        if(temp[i] > max)
        {
            max = temp[i];
        }
    }
    temp.insert(temp.cbegin(), max);
}

void delMinElementFromVector(vector<Money> &temp)
{
    Money min = temp[0];
    int pos = 0;
    for(int i=0; i<temp.size(); i++)
    {
        if(temp[i] < min)
        {
            min = temp[i];
            pos = i;
        }
    }
    temp.erase(temp.cbegin()+pos);
}

void addArithmeticAverange(vector<Money> &temp)
{
    Money averange;
    for(int i=0; i<temp.size(); i++)
    {
        averange= averange + temp[i];
    }
    int size = temp.size();
    averange = averange / size;
    for(int i=0; i<temp.size(); i++)
    {
        temp[i] = temp[i] + averange;
    }
}