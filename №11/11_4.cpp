#include <iostream>

using namespace std;

struct queue
{
    double info;
    queue *next;
};
queue *last;

queue *makeQueue(int size);
void printQueue(queue *first);
void delElemFromQueue(queue *first, int size);

int main()
{
    cout << "Введите размер очереди: ";
    int size;
    cin >> size;
    queue *list = makeQueue(size);
    printQueue(list);
    cout << "Удалены элементы с четными индексами: " << endl;
    delElemFromQueue(list, size);
    printQueue(list);
}

queue *makeQueue(int size)
{
    cout << "Введите вашу очередь: ";
    queue *first = new queue;
    cin >> first->info;
    queue *second = first;
    for(int i=2; i<=size; i++)
    {
        queue *third = new queue;
        second->next = third;
        second = third;
        cin >> second->info;
        second->next = NULL;
    }
    last = second;
    return first;
}

void printQueue(queue *first)
{
    cout << "Ваша очередь: " << endl;
    int count=1;
    while(first!=NULL)
    {
        cout << count << ": " << first->info << endl;
        first = first->next;
        count++;
    }
}

void delElemFromQueue(queue *first, int size)
{
    for(int i=1; i<=size; i++)
    {
        queue *helper = first;
        first = first->next;
        if(i%2==0)
        {
            delete helper;
        }
        else
        {
            helper->next = NULL;
            last->next = helper;
            last = helper;
        }
    }
}