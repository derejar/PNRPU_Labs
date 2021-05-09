#include <iostream>
#include <fstream>
#include "money.h"
#include "file_work.h"

using namespace std;

int main()
{
    int choose, result;
    char fileName[50];
    Money value;
    do
    {
        cout << "[1] Создать файл." << endl;
        cout << "[2] Распечатать информацию из файла." << endl; 
        cout << "[3] Удалить данные из файла." << endl;
        cout << "[4] Добавить данные в файл." << endl;
        cout << "[5] Изменить значения в файле." << endl;
        cout << "[0] Выход из программы." << endl;
        cin >> choose;
        switch(choose)
        {
            case 1:
                cout << "Введите название файла: ";
                cin >> fileName;
                result = makeFile(fileName);
                if(result < 0)
                {
                    cout << "Не удалось создать файл!" << endl;
                }
                break;
            case 2:
                cout << "Введите название файла: ";
                cin >> fileName;
                result = printFile(fileName);
                if(result == 0)
                {
                    cout << "Файл пуст!" << endl;
                }
                else if(result < 0)
                {
                    cout << "Не удалось открыть файл!" << endl;
                }
                break;
            case 3:
                cout << "Введите название файла: ";
                cin >> fileName;
                cout << "Введите значение объекта для удаления: " << endl;
                cin >> value;
                result = delElementsFromFile(fileName, value);
                if(result == 0)
                {
                    cout << "Файл пуст!" << endl;
                }
                else if(result < 0)
                {
                    cout << "Не удалось открыть файл!" << endl;
                }
                break;
            case 4:
                cout << "Введите название файла: ";
                cin >> fileName;
                cout << "Введите номер элемента, с которого осуществлять добавление новых элементов: ";
                int number;
                cin >> number;
                cout << "Введите количество добавляемых элементов: ";
                int k;
                cin >> k;
                result = addElements(fileName, number, k);
                if(result < 0)
                {
                    cout << "Не удалось открыть файл!" << endl;
                }
                if(result > 0 && result < number)
                {
                    addToEnd(fileName, k);
                }
                break;
            case 5:
                cout << "Введите название файла: ";
                cin >> fileName;
                cout << "Введите значение объекта для изменения: " << endl;
                cin >> value;
                result = changeInfo(fileName, value);
                if(result < 0)
                {
                    cout << "Не удалось открыть файл!" << endl;
                }
                break;
        }
    }while(choose);
}