#include <iostream>
#include <time.h>
#include "multiple.h"
#include "money.h"

using namespace std;

int main()
{
    //srand(time(0));
    Multiple<Money> test(5);
    cout << "Создан вектор: " << endl;
    test.print();
    cout << "Максимальный элемент добавлен в начало вектора: " << endl;
    test.findAndAddMax();
    test.print();
    cout << "Минимальный элемент удален из вектора: " << endl;
    test.delMinElementFromVector();
    test.print();
    cout << "Ко всем элементам прибавлено среднее арифметическое вектора: " << endl;
    test.addArithmeticAverange();
    test.print();
}