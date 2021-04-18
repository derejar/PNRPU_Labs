#include <iostream>

using namespace std;

struct student
{
    string name;
    int growth;
};

void shellsort(student *list, int n);
void quickSortHoare(student *list, int first, int last);
void generator(int n, student *list);
void printList(int n, student *list);

int main()
{
    int n;
    cout << "Введите количество студентов: ";
    cin >> n;
    student *list = new student[n];
    cout << "Выберите метод добавления элементов: " << endl;
    cout << "[1] Ручной ввод." << endl;
    cout << "[2] Автоматическая генерация." << endl;
    int choose;
    while(choose!=1 && choose!=2)
    {
        cout << "Ваш выбор: ";
        cin >> choose;
    }
    if(choose==1)
    {
        for(int i=0; i<n; i++)
        {
            cout << endl;
            string firstName, fatherName;
            cout << "Введите фамилию: ";
            cin >> list[i].name;
            cout << "Введите имя: ";
            cin >> firstName;
            cout << "Введите отчество: ";
            cin >> fatherName;
            list[i].name += " " + firstName + " " + fatherName;
            cout << "Введите рост: ";
            cin >> list[i].growth;
        }
    }
    if(choose==2)
    {
        generator(n, list);
    }
    cout << endl << "Ваш массив: ";
    printList(n, list);
    cout << endl;
    cout << "Выберите способ сортировки: " << endl;
    cout << "[1] Сортировка Шелла." << endl;
    cout << "[2] Быстрая сортировка Хоара." << endl;
    choose=0;
    while(choose!=1 && choose!=2)
    {
        cout << "Ваш выбор: ";
        cin >> choose;
    }
    if(choose==1)
    {
        shellsort(list, n);
    }
    else if(choose==2)
    {
        quickSortHoare(list, 0, n-1);
    }
    cout << endl;
    cout << "Отсортированный массив: ";
    printList(n, list);
}

void shellsort(student *list, int n)
{
    for(int dist=n/2; dist>0; dist/=2)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=i+dist; j<n; j+=dist)
            {
                if(list[i].growth > list[j].growth)
                {
                    student temp = list[j];
                    list[j] = list[i];
                    list[i] = temp;
                }
            }
        }
    }
}

void quickSortHoare(student *list, int first, int last)
{
    int i = first;
    int j = last;
    int x = list[(first+last)/2].growth;
    do
    {
        while(list[i].growth < x)
        {
            i++;
        }
        while(list[j].growth > x)
        {
            j--;
        }
        if(i <= j)
        {
            if(i < j)
            {
                student temp;
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if(i < last)
    {
        quickSortHoare(list, i, last);
    }
    if(first < j)
    {
        quickSortHoare(list, first, j);
    }
}

void printList(int n, student *list)
{
    for(int i=0; i<n; i++)
    {
        cout << endl;
        cout << i+1 << " студент: " << endl;
        cout << "ФИО: " << list[i].name << endl;
        cout << "Рост: " << list[i].growth << endl;
    }
}

void generator(int n, student *list)
{
    string firstNames[] = {"Александр", "Алексей", "Анатолий", "Андрей", "Антон", "Арсений", "Артем", "Борис", "Вадим", "Валентин",
        "Валерий", "Василий", "Виктор", "Виталий", "Владимир", "Георгий", "Даниил", "Денис", "Дмитрий", "Евгений"};

        string familyNames[] = {"Воробьев", "Богданов", "Виноградов", "Голубев", "Семенов", "Павлов", "Зайцев", "Васильев", "Соловьев",
        "Волков", "Петров", "Морозов", "Новиков", "Козлов", "Лебедев", "Соколов", "Попов", "Кузнецов", "Иванов", "Смирнов"};

        string fatherNames[] = {"Александрович", "Андреевич", "Богданович", "Валентинович", "Витальевич", "Георгиевич", "Григорьевич", "Игоревич", "Иванович", "Ильич",
        "Кириллович", "Константинович", "Максимович", "Михайлович", "Николаевич", "Олегович", "Павлович", "Петрович", "Романович", "Сергеевич"};
    for(int i=0; i<n; i++)
    {
        list[i].name = familyNames[rand()%20] + " " + firstNames[rand()%20] + " " + fatherNames[rand()%20];
        list[i].growth = 150+rand()%50;
    }
}