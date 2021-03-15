/*
1. Ввести размер массива;
2.Сформировать массив с помощью операции new или биб-лиотечных функций malloc (calloc);
3.Заполнить массив (можно с помощью датчика случайных чисел);
4.Выполнить задание варианта, сформировать новый мас-сив(ы)-результат(ы);
5.Напечатать массив(ы)-результат(ы);
6.Удалить динамические массивы с помощью операции de-lete или библиотечной функции free.

6.	Сформировать двумерный массив. Удалить из него строку с заданным номером;
*/

#include <iostream>

using namespace std;

void printMatrix(int **matrix, int countCols, int countLines); //матрица, колво столбцов, колво строк. Печатает матрицу.

int main()
{
    int countLines, countCols;
    cout << "Введите количество строк в двумерном массиве: ";
    cin >> countLines;
    cout << "Введите количество столбцов в двумерном массиве: ";
    cin >> countCols;

    int **matrix = new int *[countCols];
    for (int i=0; i<countLines; i++)
    {
        matrix[i] = new int [countCols];
    }

    for (int i=0; i<countLines; i++) //Заполнение массива рандомными числами
    {
        for (int j=0; j<countCols; j++)
        {
            matrix[i][j]=rand()%10;
        }
    }

    printMatrix(matrix, countCols, countLines);
    
    int lineNum;
    bool isLineTrue=false;
    while(!isLineTrue)
    {
        cout << "Введите номер строки массива для удаления: ";
        cin >> lineNum;
        lineNum--;
        if(lineNum<countLines && lineNum>=0)
        {
            isLineTrue=true;
        }
        else
        {
            cout << "Введен неверный номер строки! Попробуйте еще раз." << endl;
        }
    }

    for(int i=lineNum; i<countLines-1; i++)
    {
        for(int j=0; j<countCols; j++)
        {
            matrix[i][j]=matrix[i+1][j];
        }
    }
    countLines--;
    printMatrix(matrix, countCols, countLines);
    
    return 0;
}

void printMatrix(int **matrix, int countCols, int countLines)
{
    cout << endl << "Двумерный массив:" << endl;
    for (int i=0; i<countLines; i++)
    {
        cout << "[" << i+1 << "]: ";
        for (int j=0; j<countCols; j++)
        {
            cout << " | " << matrix[i][j];
        }
        cout << " | " << endl;
    }
    cout << endl;
}