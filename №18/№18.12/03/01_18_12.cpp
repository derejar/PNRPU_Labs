#include <iostream>
#include <map>
#include "money.h"
#include "multiple.h"

using namespace std;

int main()
{
    Multiple<Money> test(5);
    cout << "Создан контейнер: " << endl;
    test.print();
    cout << "Поиск максимального элемента и добавление его в начало контейнера: " << endl;
    test.findAndAddMaxElement();
    test.print();
    cout << "Удаление минимального элемента из контейнера: " << endl;
    test.delMinElement();
    test.print();
    cout << "Добавление ко всем элементам среднего арифметического контейнера: " << endl;
    test.addArithmeticAverange();
    test.print();
}