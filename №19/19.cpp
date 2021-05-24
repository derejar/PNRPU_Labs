#include "stack.h"
#include <iostream>

using namespace std;

template<typename T>
void print(Stack<T> a)
{
    cout << endl << "Ваш стек: " << endl;
    while(!a.empty())
    {
        cout << a.top() << " ";
        a.pop(); 
    }
}

int main()
{
    Stack<int> a;
    cout << "Введите количество элементов для добавления в стек: ";
    int n;
    cin >> n;
    cout << "Введите элементы стека: " << endl;
    for(int i=0; i<n; i++)
    {
        int elem;
        cin >> elem;
        a.push(elem);
    }
    print(a);
    cout << endl << "Размер стека: " << a.size() << endl;
    cout << "Введите элемент, который должен встать на место верхнего элемента стека: ";
    cin >> n;
    a.emplace(n);
    cout << "Верхний элемент стека: " << a.top();
}