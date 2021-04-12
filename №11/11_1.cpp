#include <iostream>

using namespace std;

struct singleList
{
    char info;
    singleList *next;
};

singleList *makeList(int size)
{
    singleList *second = new singleList;
    cout << "Введите значение элемента: ";
    cin >> second->info;
    singleList *first = new singleList;
    first=second;

    for(int i=1; i<size; i++)
    {
        singleList *third = new singleList;
        second->next = third;
        cout << "Введите значение элемента: ";
        cin >> third->info;
        second = third;
        second->next=NULL;
    }
    return first;
}

void printList(singleList *first)
{
    cout << "Ваш список: " << endl;
    int count = 1;
    cout << count << " : " << first->info << endl;
    count++;
    singleList *p = new singleList;
    p=first->next;
    while (p!=NULL)
    {
        cout << count << " : " << p->info << endl;
        p=p->next;
        count++;
    }
}

void addElem(singleList *first)
{
    int num;
    cout << "Введите номер элемента, на который нужно поставить элемент: ";
    cin >> num;
    if(num==1)
    {
        singleList *newEl = new singleList;
        cout << "Введите значение нового элемента: ";
        cin >> newEl->info;
        newEl->next = first;
        first = newEl;
    }
    else
    {
            singleList *newEl = new singleList;
            singleList *p = first;
            cout << "Введите значение нового элемента: ";
            cin >> newEl->info;
        for(int i=1; i<num; i++)
        {
            if(i==(num-1))
            {
                newEl->next = p->next;
                p->next = newEl;
            }
            else
            {
                p=p->next;
            }
        }
    }
}

int main()
{
    int size;
    cout << "Введите размер однонаправленного списка: ";
    cin >> size;
    singleList *list = makeList(size);
    printList(list);
    addElem(list);
    printList(list);

    return 0;
}