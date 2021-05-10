#include <iostream>
#include <map>

using namespace std;

multimap<double, double> create(int count); //Создание контейнера

void print(multimap<double, double> temp); //Печать содержимого контейнера
void findAndAddMaxElement(multimap<double, double> &temp); //Поиск максимального элемента и добавление его в начало контейнера
void delMinElement(multimap<double, double> &temp); //Удаление минимального элемента из контейнера
void addArithmeticAverange(multimap<double, double> &temp); //Добавление к элементам контейнера среднего арифметического контейнера

int main()
{
    multimap<double, double> test;
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

multimap<double, double> create(int count)
{
    multimap<double, double> temp;
    double value;
    cout << "Введите значение для " << count << " элементов: " << endl;
    for(int i=0; i<count; i++)
    {
        cin >> value;
        temp.insert(make_pair(i, value));
    }
    return temp;
}

void print(multimap<double, double> temp)
{
    multimap<double, double>::iterator it = temp.begin();
    for(int i=0; i<temp.size(); i++)
    {
        cout << it->second << " ";
        it++;
    }
    cout << endl;
}

void findAndAddMaxElement(multimap<double, double> &temp)
{
    multimap<double, double>::iterator it = temp.begin();
    double max = it->second;
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

void delMinElement(multimap<double, double> &temp)
{
    multimap<double, double>::iterator it = temp.begin(), pos = it;
    double min = it->second;
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

void addArithmeticAverange(multimap<double, double> &temp)
{
    multimap<double, double>::iterator it = temp.begin();
    double averange = 0;
    for(int i=0; i<temp.size(); i++)
    {
        averange += it->second;
        it++;
    }
    averange /= temp.size();
    it = temp.begin();
    for(int i=0; i<temp.size(); i++)
    {
        it->second += averange;
        it++;
    }
}