#include "pair.cpp"
#include "LONG.cpp"
#include <iostream>
using namespace std;

int main()
{
    Pair a(43,24);
    cout << "Пара a: " << a << endl;
    Pair b;
    cin >> b;
    cout << "Пара b: " << b << endl;
    cout << "Сложение пар: a + b = " << a+b << endl;
    LONG c(934, 235); //Класс LONG - производный от Pair
    cout << "LONG c: " << c << endl;
    LONG d;
    cin >> d;
    cout << "LONG d: " << d << endl;
    cout << "c - d = " << c-d << endl;
    cout << "c + d = " << c+d << endl;
    cout << "c * d = " << c*d << endl;
}