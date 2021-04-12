#include <iostream>

using namespace std;

struct bidirectionalList
{
    double info;
    bidirectionalList *next;
    bidirectionalList *previous;
};

bidirectionalList *makeList(int size)
{
    int count=1;
    bidirectionalList *first = new bidirectionalList;
    cout << "Введите значение " << count << " элемента: ";
    cin >> first->info;
    first->previous=NULL;
    bidirectionalList *second = first;
    for(int i=1; i<size; i++)
    {
        count++;
        bidirectionalList *third = new bidirectionalList;
        second->next=third;
        third->previous=second;
        second=third;
        cout << "Введите значение " << count << " элемента: ";
        cin >> second->info;
        second->next=NULL;
    }
    return first;
}

void printBidirectionalList(bidirectionalList *list)
{
    cout << "Ваш двунаправленный список: " << endl;
    cout << list->info << endl;
    bidirectionalList *p=list->next;
    while(p!=NULL)
    {
        cout << p->info << endl;
        p=p->next;
    }
}

void delElements(bidirectionalList *list)
{
    bidirectionalList *first, *second;
    first=second=list;
    while(second->next!=NULL && first->next!=NULL)
    {
        second=first->next;
        first->next=second->next;
        if(second->next==NULL)
        {
            delete second;
        }
        else
        {
            second=second->next;
            delete second->previous;
            second->previous=first;
            first=second;                
        }
    }
}

int main()
{
    cout << "Введите размер двунаправленного списка: ";
    int size;
    cin >> size;
    bidirectionalList *list = makeList(size);
    printBidirectionalList(list);
    delElements(list);
    printBidirectionalList(list);

    return 0;
}