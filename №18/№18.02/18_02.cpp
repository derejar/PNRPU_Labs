#include <iostream>
#include "country.cpp"

using namespace std;

country make_country()
{
    string n;
    int k;
    double s;
    cout << "Введите название страны: ";
    cin >> n;
    cout << "Введите количество жителей: ";
    cin >> k;
    cout << "Введите площадь страны: ";
    cin >> s;
    country temp(n, k, s);
    return temp;
}

void printCountry(country a)
{
    a.show();
}

int main()
{
    country a1;
    a1.show();
    cout << endl;
    country a2("Стокгольм", 10380, 450.5);
    a2.show();
    cout << endl;
    country a3 = a2;
    a3.setCapital("Копенгаген");
    a3.setCountOfResidents(5837);
    a3.setArea(43.094);
    cout << endl;
    printCountry(a3);
    cout << endl;
    a1 = make_country();
    a1.show();
}