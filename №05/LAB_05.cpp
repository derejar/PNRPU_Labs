/*
Элемент матрицы является седловой точкой, если он является наименьшим в своей строке и наибольшим в своем
столбце (или наоборот: наибольшим в своей строке и наименьшим в своем столбце). Для заданной матрицы
определить все седловые точки.
*/
#include <iostream>

using namespace std;

int count=0;

int isSedl(int **matrix, int max, int min, int countCols, int countLines, int line)
{
    bool flag=true;
    for(int i=0; i<countCols; i++)
    {
        flag=true;
        if(max==matrix[line][i]) //Проверка, является ли максимальный элемент строки минимальным в столбце
        {
            for(int j=0; j<countLines; j++)
            {
                if(max>matrix[j][i] && flag==true)
                {
                    flag=false;
                }
            }
            if(flag==true)
            {
               count++;
               cout << count << " седловая точка: строка №" << line+1 << ", столбец №" << i+1 << endl;
            }
        }

        else if(min==matrix[line][i])
        {
            for(int j=0; j<countLines; j++)
            {
                if(min<matrix[j][i] && flag==true)
                {
                    flag=false;
                }
            }
            if(flag==true)
            {
               count++;
               cout << count << " седловая точка: строка №" << line+1 << ", столбец №" << i+1 << endl;
            }
        }
    }
    return count;
}

int main()
{
    int countCols, countLines;
    cout << "Количество строк: ";
    cin >> countLines;
    cout << "Количество столбцов: ";
    cin >> countCols;

    int **matrix= new int *[countCols];
    for (int i=0; i<countLines; i++)
    {
        matrix[i] = new int [countCols];
    }

    cout << "Введите матрицу: " << endl;
    for (int i=0; i<countLines; i++)
    {
        for (int j=0; j<countCols; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << "Введенная матрица:" << endl;
    for (int i=0; i<countLines; i++)
    {
        for (int j=0; j<countCols; j++)
        {
            cout << matrix[i][j] << " | ";
        }
        cout << endl;
    }
    //Все выше - формирование матрицы

    int line = 0; //Строка матрицы, где ищется максимальный/минимальный элементы
    int min, max;

    for (line; line<countLines; line++)
    {
        min = max = matrix[line][0];
        for (int i=0; i<countCols; i++) //Поиск максимального/минимального элемента в строке
        {
            if (max<matrix[line][i])
            {
                max=matrix[line][i];
            }

            if (min>matrix[line][i])
            {
                min=matrix[line][i];
            }
        }
        isSedl(matrix, max, min, countCols, countLines, line);  
    }
    cout << "Количество седловых точек в матрице: " << count << endl;
    return 0;
}