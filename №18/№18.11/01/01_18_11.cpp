#include <iostream>
#include <vector>

using namespace std;

vector<double> makeVector(int count); //Создание вектора размера count

void print(vector<double> temp); //Печать вектора в консоль
void findAndAddMax(vector<double> &temp); //Поиск максимального элемента и добавление его в начало вектора
void delMinElementFromVector(vector<double> &temp); //Удаление минимального элемента из вектора
void addArithmeticAverange(vector<double> &temp); //Добавление ко всем элементам вектора среднее арифметическое

int main()
{
    vector<double> test;
    test = makeVector(10);
    cout << "Создан вектор: " << endl;
    print(test);
    findAndAddMax(test);
    cout << "Максимальный элемент добавлен в начало вектора: " << endl;
    print(test);
    delMinElementFromVector(test);
    cout << "Минимальный элемент удален из вектора: " << endl;
    print(test);
    cout << "Ко всем элементам прибавлено среднее арифметическое вектора: " << endl;
    addArithmeticAverange(test);
    print(test);
}

vector<double> makeVector(int count)
{
    vector<double> temp(count);
    for(int i=0; i<count; i++)
    {
        temp[i] = rand()%100-50;
    }
    return temp;
}

void print(vector<double> temp)
{
    for(int i=0; i<temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
}

void findAndAddMax(vector<double> &temp)
{
    double max = temp[0];
    for(int i=0; i<temp.size(); i++)
    {
        if(temp[i] > max)
        {
            max = temp[i];
        }
    }
    temp.insert(temp.cbegin(), max);
}

void delMinElementFromVector(vector<double> &temp)
{
    double min = temp[0];
    int pos = 0;
    for(int i=0; i<temp.size(); i++)
    {
        if(temp[i] < min)
        {
            min = temp[i];
            pos = i;
        }
    }
    temp.erase(temp.cbegin()+pos);
}

void addArithmeticAverange(vector<double> &temp)
{
    double averange=0;
    for(int i=0; i<temp.size(); i++)
    {
        averange+=temp[i];
    }
    averange/=temp.size();
    for(int i=0; i<temp.size(); i++)
    {
        temp[i]+=averange;
    }
}