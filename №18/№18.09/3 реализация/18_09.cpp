#include <iostream>
#include "multiple.h"

using namespace std;

int main()
{
    try
    {
        int size;
        cout << "Введите размер множества: ";
        cin >> size; //Если размер будет больше максимального, сработает исключение
        Multiple x(size);
        cout << "Введите вектор х размером " << size << ": " << endl;
        cin >> x;
        cout << x << endl;
        cout << "Введите номер элемента: ";
        int i;
        cin >> i;
        cout << "x[" << i << "] = " << x[i] << endl; //При отрицательном или i>size сработает исключение
        x++; //Если множество станет больше максимального размера, сработает исключение
        cout << x;
        Multiple y(10);
        for(int i=0; i<10; i++)
        {
            y[i] = rand()%1000;
        }
        cout << "Множество y:" << endl << y << endl;
        x=x+y; //Если множество станет больше максимального размера, сработает исключение
        cout << "x+y: " << endl << x << endl;
    }
    catch(Error &error)
    {
        error.what();
    }
}