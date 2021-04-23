#include <iostream>
#include <time.h>
#include <algorithm>
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

void linearSearch(humanInfo *infoArr, string streetName, int houseNum, int apartNum); //линейный поиск
void directSearch(humanInfo *infoArr, string streetName, int houseNum, int apartNum); //прямой поиск подстроки в строке
void interpolationSearch(humanInfo *infoArr, string streetName, int houseNum, int apartNum); //интерполяционный поиск

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
    srand(time(0));
    humanInfo *infoArr = new humanInfo[100];
    *arrSize = 100;
    infoGenerator(infoArr, 0, *arrSize);
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

void chooseSearch(humanInfo *infoArr)
{
    cout << endl;
    cout << "Выберите способ поиска элементов: " << endl;
    cout << "[1] Линейный поиск." << endl;
    cout << "[2] Прямой поиск подстроки в строке." << endl;
    cout << "[3] Интерполяционный поиск." << endl;
    int againChoose;
    while(againChoose < 1 || againChoose > 3)
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
        linearSearch(infoArr, streetName, houseNum, apartNum);
    }
    else if(againChoose == 2)
    {
        directSearch(infoArr, streetName, houseNum, apartNum);
    }
    else if(againChoose == 3)
    {
        interpolationSearch(infoArr, streetName, houseNum, apartNum);
    }
}

void interpolationSearch(humanInfo *infoArr, string streetName, int houseNum, int apartNum)
{
    for(int dist=*arrSize/2; dist>0; dist/=2)
    {
        for(int i=0; i<*arrSize; i++)
        {
            for(int j=i+dist; j<*arrSize; j+=dist)
            {
                if(infoArr[i].registration->houseNum > infoArr[j].registration->houseNum)
                {
                    humanInfo temp = infoArr[j];
                    infoArr[j] = infoArr[i];
                    infoArr[i] = temp;
                }
            }
        }
    }
    cout << "Отсортированный массив: ";
    printArray(infoArr);
    int findedNum=0;
    int left=0, right=*arrSize-1;
    int mid;
    while(infoArr[left].registration->houseNum <= houseNum && infoArr[right].registration->houseNum >= houseNum && findedNum == 0)
    {
        mid = left+(((houseNum-infoArr[left].registration->houseNum)*(right-left))/(infoArr[right].registration->houseNum-infoArr[left].registration->houseNum));
        cout << infoArr[left].registration->houseNum << "<=" << houseNum << "&&" << infoArr[right].registration->houseNum << ">=" << houseNum << endl;
        if(infoArr[mid].registration->houseNum < houseNum)
        {
            left = mid+1;
        }
        else if(infoArr[mid].registration->houseNum > houseNum)
        {
            right = mid-1;
        }
        else if(infoArr[mid].registration->houseNum == houseNum && infoArr[mid].registration->apartNum!=apartNum && infoArr[mid].registration->streetName!=streetName)
        {
            int temp;
            for(int i=mid; i<*arrSize; i++)
            {
                if(infoArr[i].registration->houseNum == houseNum)
                {
                    temp=i;
                }
                else
                {
                    break;
                }
            }
            for(int i=temp; i>=0; i--)
            {
                if(infoArr[i].registration->houseNum == houseNum && infoArr[i].registration->apartNum == apartNum && infoArr[i].registration->streetName == streetName)
                {
                    findedNum=i;
                    break;
                }
            }
        }
        else if(infoArr[mid].registration->apartNum == apartNum && infoArr[mid].registration->streetName == streetName)
        {
            findedNum = mid;
            break;       
        }
    }
    if(infoArr[left].registration->houseNum == houseNum && findedNum == 0 && infoArr[mid].registration->apartNum == apartNum && infoArr[mid].registration->streetName == streetName)
    {
        findedNum = left;
    }
    else if(findedNum == 0)
    {
        cout << endl << "Ничего не найдено!" << endl;
    }
    if(findedNum!=0)
    {
        cout << endl; 
        cout << "Элемент найден!" << endl;
        cout << findedNum+1 << " элемент:" << endl;
        cout << "ФИО: " << infoArr[findedNum].fio << endl;
        cout << "Номер паспорта: " << infoArr[findedNum].passNum << endl;
        cout << "Улица " << infoArr[findedNum].registration->streetName << ", дом " << infoArr[findedNum].registration->houseNum << ", кв. " << infoArr[findedNum].registration->apartNum << endl;
    }
  }

void linearSearch(humanInfo *infoArr, string streetName, int houseNum, int apartNum)
{
    bool isSmthingFinded = false;
    for(int i=0; i<*arrSize; i++)
    {
        if(infoArr[i].registration->streetName == streetName && infoArr[i].registration->houseNum == houseNum
            && infoArr[i].registration->apartNum == apartNum)
        {
            cout << endl; 
            cout << "Элемент найден!" << endl;
            cout << i+1 << " элемент:" << endl;
            cout << "ФИО: " << infoArr[i].fio << endl;
            cout << "Номер паспорта: " << infoArr[i].passNum << endl;
            cout << "Улица " << infoArr[i].registration->streetName << ", дом " << infoArr[i].registration->houseNum << ", кв. " << infoArr[i].registration->apartNum << endl;
            isSmthingFinded = true;
        }
    }
    if(!isSmthingFinded)
    {
        cout << endl << "Ничего не найдено!" << endl;
    }
}

void directSearch(humanInfo *infoArr, string streetName, int houseNum, int apartNum)
{
    bool anythingFinded = false;
    string bigLine, searchLine;
    for(int i=0; i<*arrSize; i++)
    {
        bigLine += infoArr[i].registration->streetName + "$" + to_string(infoArr[i].registration->houseNum) + "$" + to_string(infoArr[i].registration->apartNum) + "#";
    }
    searchLine += streetName + "$" + to_string(houseNum) + "$" + to_string(apartNum) + "#";
    bigLine+="!";
    int strInt=0, endOfLine=0;
    while(bigLine[strInt]!='!')
    {
        if(bigLine[strInt]=='#')
        {
            endOfLine++;
        }
        if(bigLine[strInt]==searchLine[0])
        {
            bool find = true;
            for(int i=1; i<searchLine.length(); i++)
            {
                if(bigLine[strInt+i]!=searchLine[i])
                {
                    find = false;
                    break;
                }
            }
            if(find == true)
            {
                anythingFinded = true;
                cout << endl; 
                cout << "Элемент найден!" << endl;
                cout << endOfLine+1 << " элемент:" << endl;
                cout << "ФИО: " << infoArr[endOfLine].fio << endl;
                cout << "Номер паспорта: " << infoArr[endOfLine].passNum << endl;
                cout << "Улица " << infoArr[endOfLine].registration->streetName << ", дом " << infoArr[endOfLine].registration->houseNum << ", кв. " << infoArr[endOfLine].registration->apartNum << endl;
            }
        }
        strInt++;
    }
    if(!anythingFinded)
    {
        cout << endl << "Ничего не найдено!" << endl;
    }
}
