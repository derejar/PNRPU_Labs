#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    int size, element;
    bool flag=false;

    cout << "Задайте размер массива: ";
    cin >> size;
    int a[size]; //Выделение места для массива указанного пользователем размера

    srand(time(0));

    for (int i=0; i<size; i++)
    {
        a[i]=rand() % 100 - 50; //Инициализация массива
        cout << "№" << i+1 << ": " << a[i] << endl;
    }

    cout << "Задайте номер элемента для удаления из массива: ";
    cin >> element;
    cout << "Массив после удаления " << element << " элемента: " << endl;
    element=element-1;

    for (int i=0; i<size-1; i++) //Перебор всех элементов массива
    {
        if (i==element)
        {
            for (int j=i; j<size; j++) //Смещение элементов массива на место удаляемого
            {
                a[j]=a[j+1];
            }
        }
        cout << "№" <<  i+1 << ": " << a[i] << endl;
    }

    cout << "Добавление нового элемента массива после первого четного: " << endl;

    for (int i=0; i<size; i++)
    {
        if (((i+1)%2)==0 && (i!=0) && (flag==false)) //Поиск первого четного элемента (не нуля)
        {
            flag=true;
            for (int j=size; j>i; j--) //Смещение элементов массива для добавления нового элемента
            {
                a[j]=a[j-1];
            }
            a[i+1]=a[i-1]+2;
        }
        cout << "№" << i+1 << ": " << a[i] << endl;
    }
    return 0;
}