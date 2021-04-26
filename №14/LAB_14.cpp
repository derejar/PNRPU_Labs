#include <iostream>
#include <time.h>
#include <algorithm>
#include <windows.h>
#include "functionality.h"

using namespace std;

void printArray(humanInfo *infoArr); //печать массива

void infoGenerator(humanInfo *infoArr, int startingElem, int endingElem); //автоматическая генерация информации
void manualInput(humanInfo *infoArr, int startionElem, int endingElem); //ввод информации пользователем

void saveToFile(humanInfo *infoArr); //сохранение масисва в файл
void downloadFromFile(humanInfo *infoArr); //загрузка массива из файла

humanInfo *addElement(humanInfo *infoArr); //добавление элемента в массив
void delElements(humanInfo *infoArr); //удаление элемента из массива
void cancelDel(humanInfo *infoArr); //отмена удаления

void kmpSearch(humanInfo *infoArr, string streetName, int houseNum, int apartNum);
void boyerMooreSearch(humanInfo *infoArr, string streetName, int houseNum, int apartNum);

void chooseSearch(humanInfo *infoArr); //выбор поиска (подменю)

int menu() //основное меню
{
    int num=5;
    int choose;
    cout << endl << "Выберите действие: " << endl;
    cout << "[1] Добавление элементов." << endl;
    cout << "[2] Удаление элементов." << endl;
    cout << "[3] Поиск элемента." << endl;
    cout << "[4] Распечатать массив." << endl;
    cout << "[5] Сохранить массив в файл." << endl;
    if(*savedToFile)
    {
        cout << "[" << num + (int)*savedToFile << "] Загрузка массива из файла." << endl;
    }
    if(*smthingDeleted)
    {
        cout << "[" << num + (int)*savedToFile + 1 << "] Отменить последнее удаление." << endl;
    }
    cout << "[0] Выход из программы." << endl;
    cout << "Ваш выбор: ";
    cin >> choose;
    return choose;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 
    srand(time(0));
    humanInfo *infoArr = new humanInfo[100];
    *arrSize = 100;
    infoGenerator(infoArr, 0, *arrSize);
    int a = 86;
    infoArr[a].fio = "Derbenev Jaroslav Evg";
    infoArr[a].passNum = 123456;
    infoArr[a].registration->streetName = "Gaydara";
    infoArr[a].registration->houseNum = 12;
    infoArr[a].registration->apartNum = 20;
    int choose=1;
    while(choose)
    {
        choose = menu();
        if(choose == 6 && !*savedToFile)
        {
            choose++;
        }
        switch(choose)
        {
            case 1:
                infoArr = addElement(infoArr); break;
            case 2:
                delElements(infoArr); break;
            case 3:
                chooseSearch(infoArr); break;
            case 4:
                printArray(infoArr); break;
            case 5:
                saveToFile(infoArr); break;
            case 6:
                {
                    if(*savedToFile)
                    {
                        humanInfo *newArr = new humanInfo[*sizeSavedToFile];
                        downloadFromFile(newArr);
                        delete[] infoArr;
                        infoArr = newArr;
                    }
                }   break;
            case 7:
                {
                    if(*smthingDeleted)
                    {
                        cancelDel(infoArr);
                    }
                }   break;
            case 0:
                break;
        }
    }
}

void boyerMooreSearch(humanInfo *infoArr, string streetName, int houseNum, int apartNum)
{
    bool finded = false;
    int lastChar=0;
    string bigLine="", searchLine="";
    for(int i=0; i<*arrSize; i++)
    {
        bigLine += infoArr[i].registration->streetName + "$" + to_string(infoArr[i].registration->houseNum) + "$" + to_string(infoArr[i].registration->apartNum) + "#";
    }
    searchLine += streetName + "$" + to_string(houseNum) + "$" + to_string(apartNum) + "#";
    bigLine+="!";
    while(searchLine[lastChar]!='#')
    {
        lastChar++;
    }
    int *a = new int[lastChar]{0};
    a[lastChar]=lastChar+1;
    int *countNums = new int;
    *countNums = 1;
    for(int i=lastChar-1; i>=0; i--)
    {
        for(int j=lastChar-1; j>i; j--)
        {
            if(searchLine[i] == searchLine[j])
            {
                a[i] = a[j];
                break;
            }
        }
        if(a[i]==0)
        {
            a[i] = *countNums;
        }
        (*countNums)++;
    }
    int num=lastChar;
    while(bigLine[num]!='!' && !finded && num <= bigLine.length())
    {
        if(bigLine[num]!=searchLine[lastChar])
        {
            for(int i=lastChar; i>=0; i--)
            {
                if(bigLine[num]==searchLine[i])
                {
                    num+=a[i];
                    break;
                }
                if(bigLine[num]!=searchLine[i] && i==0)
                {
                    num+=a[lastChar];
                }
            }
        }
        else if(bigLine[num]==searchLine[lastChar])
        {
            for(int i=1; i<=lastChar; i++)
            {
                if(bigLine[num-i] != searchLine[lastChar-i])
                {
                    num+=a[lastChar-i];
                    finded = false;
                    break;
                }
                finded = true;
            }
            
        }
    }
    if(finded)
    {
        cout << endl; 
        cout << "Элемент найден!" << endl;
        int res = bigLine.length()/(*arrSize);
        res = (num/res)-10;
        for(int i=res; i<*arrSize; i++)
        {
            if(infoArr[i].registration->streetName == streetName && infoArr[i].registration->houseNum == houseNum && infoArr[i].registration->apartNum == apartNum)
            {
                cout << i+1 << " элемент:" << endl;
                cout << "ФИО: " << infoArr[i].fio << endl;
                cout << "Номер паспорта: " << infoArr[i].passNum << endl;
                cout << "Улица " << infoArr[i].registration->streetName << ", дом " << infoArr[i].registration->houseNum << ", кв. " << infoArr[i].registration->apartNum << endl;
    
            }
        }
    }
    else
    {
        cout << "Элемент не найден!" << endl;
    }
    delete countNums;
}

void kmpSearch(humanInfo *infoArr, string streetName, int houseNum, int apartNum)
{
    string bigLine, searchLine;
    for(int i=0; i<*arrSize; i++)
    {
        bigLine += infoArr[i].registration->streetName + "$" + to_string(infoArr[i].registration->houseNum) + "$" + to_string(infoArr[i].registration->apartNum) + "#";
    }
    searchLine += streetName + "$" + to_string(houseNum) + "$" + to_string(apartNum) + "#";
    bigLine+="!";
    int *a = new int[searchLine.length()];
    a[0]=0;
    int j=0, i=1;
    while(searchLine[i-1]!='#')
    {
        if(searchLine[i] == searchLine[j])
        {
            a[i] = j+1;
            i++;
            j++;
        }
        else if(j == 0)
        {
            a[i] = 0;
            i++;
        }
        else
        {
            j = a[j-1];
        }
    }

    i=0;
    j=0;
    int count=0, finded=-1;

    while(bigLine[i]!='!' && finded == -1)
    {
        if(bigLine[i] == searchLine[j])
        {
            i++;
            j++;
            if(searchLine[j] == '#')
            {
                finded = count;
            }
        }
        else if(j==0)
        {
            i++;
        }
        else
        {
            j = a[j-1];
        }
        if(bigLine[i]=='#')
        {
            count++;
        }
    }
    if(finded!=-1)
    {
        cout << endl; 
        cout << "Элемент найден!" << endl;
        cout << finded+1 << " элемент:" << endl;
        cout << "ФИО: " << infoArr[finded].fio << endl;
        cout << "Номер паспорта: " << infoArr[finded].passNum << endl;
        cout << "Улица " << infoArr[finded].registration->streetName << ", дом " << infoArr[finded].registration->houseNum << ", кв. " << infoArr[finded].registration->apartNum << endl;
    }
    else
    {
        cout << endl << "Элемент не найден!" << endl;
    }
    delete[] a;
}

void chooseSearch(humanInfo *infoArr)
{
    cout << endl;
    cout << "Выберите способ поиска элементов: " << endl;
    cout << "[1] Поиск Кнута-Морриса-Пратта." << endl;
    cout << "[2] Поиск Бойера-Мура" << endl;
    int againChoose;
    while(againChoose < 1 || againChoose > 2)
    {
        cout << "Ваш выбор: ";
        cin >> againChoose;
    }
    string streetName;
    int houseNum, apartNum;
    cout << endl;
    cout << "Введите название улицы: ";
    cin >> streetName;
    cout << "Введите номер дома: ";
    cin >> houseNum;
    cout << "Введите номер квартиры: ";
    cin >> apartNum;
    if(againChoose == 1)
    {
        kmpSearch(infoArr, streetName, houseNum, apartNum);
    }
    else if(againChoose == 2)
    {
        boyerMooreSearch(infoArr, streetName, houseNum, apartNum);
    }
}