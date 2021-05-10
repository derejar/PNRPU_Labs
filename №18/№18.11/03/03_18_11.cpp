#include <iostream>
#include "multiple.h"
#include "money.h"

using namespace std;

int main()
{
    Multiple<Money> test(5);
    cout << "Создано множество: " << endl;
    test.print();
    cout << "Максимальный элемент добавлен в начало множества: " << endl;
    test.findAndAddMax();
    test.print();
    cout << "Минимальный элемент удален из множетсва: " << endl;
    test.delMinElementFromVector();
    test.print();
    cout << "Ко всем элементам прибавлено среднее арифметическое множетсва: " << endl;
    test.addArithmeticAverange();
    test.print();
}
