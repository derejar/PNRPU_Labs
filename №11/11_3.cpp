#include <iostream>

using namespace std;

struct stack
{
    char info;
    stack *prev;
};

stack *makeStack(int size);
void printStack(stack *first);
stack *addElemToStack(stack *first, int elem);

int main()
{
    cout << "Введите размер стека: ";
    int size;
    cin >> size;
    stack *list = makeStack(size);
    printStack(list);
    cout << "Введите номер элемента, на место которого нужно поставить элемент: ";
    int elem;
    cin >> elem;
    size++;
    stack *newList = addElemToStack(list, elem);
    printStack(newList);
}

stack *makeStack(int size)
{
    cout << "Введите ваш стек: ";
    stack *first = new stack;
    first->prev=NULL;
    cin >> first->info;
    for(int i=2; i<=size; i++)
    {
        stack *second = new stack;
        second->prev = first;
        cin >> second->info;
        first = second;
    }
    return first;
}

void printStack(stack *first)
{
    cout << "Ваш стек: " << endl;
    int count=1;
    while(first!=NULL)
    {
        cout << count << " элемент стека: " << first->info << endl;
        first=first->prev;
        count++;
    }
}

stack *addElemToStack(stack *first, int elem)
{
    cout << "Введите значение для добавляемого элемента: ";
    char addedElem;
    cin >> addedElem;
    if(elem==1)
    {
        stack *newFirst = new stack;
        newFirst->prev = first;
        newFirst->info = addedElem;
        return newFirst;
    }
    else
    {
        int *mas = new int[elem-1];
        int index=0;
        stack *helper;
        for(int i=1; i<elem; i++)
        {
            helper = first;
            mas[index] = helper->info;
            first = helper->prev;
            delete helper;
            index++;
        }
        helper = new stack;
        helper->prev = first;
        helper->info = addedElem;
        first = helper;
        while (index--)
        {
            helper = new stack;
            helper->info = mas[index];
            helper->prev = first;
            first = helper;
        }
        return first;
    }
}