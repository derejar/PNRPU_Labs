#include <iostream>
#include "fraction.cpp"

using namespace std;

fraction make_fraction(double a, double b)
{
    fraction temp;
    temp.init(a, b);
    return temp;
}

int main()
{
    fraction a, b;
    a.init(3.0, 2);
    b.read();
    a.show();
    a.root();
    b.show();
    b.root();

    fraction *x = new fraction;
    x->init(2.0, 5);
    x->show();
    x->root();

    fraction mas[3];
    for(int i=0; i<3; i++)
    {
        mas[i].read();
    }
    for(int i=0; i<3; i++)
    {
        mas[i].show();
        mas[i].root();
    }

    fraction *pMas = new fraction[3];
    for(int i=0; i<3; i++)
    {
        pMas[i].read();
    }
    for(int i=0; i<3; i++)
    {
        pMas[i].show();
        pMas[i].root();
    }

    double c, d;
    cout << "y=Ax+B" << endl;
    cout << "A=";
    cin >> c;
    cout << "B=";
    cin >> d;
    fraction f = make_fraction(c, d);
    f.show();
}