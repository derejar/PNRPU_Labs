#include "pair.cpp"
#include "LONG.cpp"
#include "vector.cpp"
#include <iostream>

using namespace std;

int main()
{
    Vector n(2);//Вектор из 2 элементов 
    Pair a; //Объекта класса Pair
    cin >> a;
    LONG b; //Объекта класса LONG
    cin >> b;
    Object *p; //Объявление указателя
    p = &a; //Установка указателя на объект класса Pair
    n.add(p); //Добавление объекта в вектор
    p = &b; //Установка указателя на объект класса LONG
    n.add(p); //Добавление объекта в вектор
    cout << n; //Вывод вектора
}