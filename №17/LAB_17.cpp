#include <iostream>
#include <vector>
#include <windows.h>
#include <time.h>
#include <cmath>
#include "LAB_17.h"

using namespace std;

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    *arrSize = 100;
    int choose = 0;
    while(choose < 1 || choose > 3)
    {
        cout << "Выберите размер хеш-таблицы: " << endl;
        cout << "[1] 40 элементов." << endl;
        cout << "[2] 75 элементов." << endl;
        cout << "[3] 90 элементов." << endl;
        cout << "Выш выбор: ";
        cin >> choose;
        cout << endl;
        switch(choose)
        {
            case 1: *tableSize = 40; break;
            case 2: *tableSize = 75; break;
            case 3: *tableSize = 90; break;
            default: cout << "Вы ввели неправильное значение! Попробуйте еще раз!" << endl << endl; break;
        }
    }
    vector<humanInfo> hashTable(*tableSize);
    for(int i=0; i<*arrSize; i++)
    {
        if( (float)(*countOfElements)/(*tableSize) > 0.7 )
        {
            resizeTable(hashTable);
        }
        elemOfTableGenerator(hashTable);
    }
    cout << "Количество коллизий: " << *countOfCollusions << endl << endl;
    choose = -1;
    while(choose)
    {
        cout << "Выберите действие: " << endl;
        cout << "[1] Поиск элемента." << endl;
        cout << "[2] Распечатать таблицу." << endl;
        cout << "[0] Выход из программы." << endl;
        cout << "Ваш выбор: ";
        cin >> choose;
        cout << endl;
        switch(choose)
        {
            case 1: searchElem(hashTable); break;
            case 2: print(hashTable); break;
            case 0: break;
            default: cout << "Вы ввели неправильное значение! Попробуйте еще раз!" << endl << endl; break;
        }
    }
}