#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include "money.h"

using namespace std;

Money s;
Money averange;

struct MoneyComp
{
    bool operator()(pair<int, Money> a, pair<int, Money> b)
    {
        if(a.second > b.second)
        {
            return false;
        }
        return true;
    }
};

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
    bool operator()(pair<int, Money> a)
    {
        return a.second == s;
    }
};

multimap<int, Money> create(int count)
{
    Money a;
    multimap<int, Money> creating;
    for(int i=0; i<count; i++)
    {
        cin >> a;
        creating.insert(make_pair(i, a));
    }
    return creating;
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

vector<Money> toVector(multimap<int, Money> temp)
{
    vector<Money> a;
    multimap<int, Money>::iterator it = temp.begin();
    for(int i=0; i<temp.size(); i++)
    {
        a.push_back(it->second);
        it++;
    }
    return a;
}

multimap<int, Money> toMultimap(vector<Money> temp)
{
    multimap<int, Money> a;
    for(int i=0; i<temp.size(); i++)
    {
        a.insert(make_pair(i, temp[i]));
    }
    return a;
}

int main()
{
    cout << "Введите размер контейнера: ";
    int n;
    cin >> n;
    multimap<int, Money> test = create(n);
    cout << "Созданный контейнер: " << endl;
    print(test);
    cout << "Добавление максимального элемента в начало контейнера: " << endl;
    multimap<int, Money>::iterator it;
    it = max_element(test.begin(), test.end(), MoneyComp());
    test.emplace_hint(test.begin(), make_pair(0, it->second));
    print(test);
    cout << "Контейнер, отсортированный по возрастанию: " << endl;
    vector<Money> forSort = toVector(test);
    sort(forSort.begin(), forSort.end());
    test = toMultimap(forSort);
    print(test);
    cout << "Контейнер, отсортированный по убыванию: " << endl;
    sort(forSort.begin(), forSort.end(), comp());
    test = toMultimap(forSort);
    print(test);
    cout << "Контейнер после удаления минимального элемента:" << endl;
    it = min_element(test.begin(), test.end(), MoneyComp());
    test.erase(it);
    print(test);
    cout << "Введите элемент для поиска: " << endl;
    cin >> s;
    it = find_if(test.begin(), test.end(), equal_s());
    if(it!=test.end())
    {
        cout << "Элемент найден: " << it->second << endl;
    }
    else
    {
        cout << "Элемент не найден! " << endl;
    }
    cout << "Контейнер после добавления к элементам среднего арифметического: " << endl;
    it = test.begin();
    for(int i=0; i<test.size(); i++)
    {
        averange = averange + it->second;
        it++;
    }
    averange = averange / test.size();
    it = test.begin();
    for(int i=0; i<test.size(); i++)
    {
        it->second = it->second + averange;
        it++;
    }
    print(test);
}
