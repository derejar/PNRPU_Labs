#include <iostream>

using namespace std;

float SubtractNumbers(float, float);
double SubtractNumbers(double, double);
long double SubtractNumbers(long double b, long double d);

int main()
{
    cout << "Выберите, вычитание каких чисел будет производиться." << endl 
    << "Для вычитания вещественных чисел введите \"1\", для вычитания комплексных введите "
    << "\"2\"." << endl;
    int choose;
    while(choose!=1 && choose!=2)
    {
        cin >> choose;
        if (choose==1)
        {
            float a, b;
            cout << "Введите первое число: ";
            cin >> a;
            cout << "Введите второе число: ";
            cin >> b;
            cout << a << " - " << b << " = " << SubtractNumbers(a, b);
        }
        else if (choose==2)
        {
            double a, b, c, d;
            cout << "Введите коэффициенты для первого комплексного числа: X=A+Bi" << endl;
            cout << "A=";
            cin >> a;
            cout << "B=";
            cin >> b;
            cout << "Введите коэффициенты для второго комплексного числа: Y=C+Di" << endl;
            cout << "C=";
            cin >> c;
            cout << "D=";
            cin >> d;
            cout << "X - Y = " << SubtractNumbers(a,c);
            if(SubtractNumbers(b,d)>=0)
            {
            cout << "+" << SubtractNumbers(b,d) << "i" << endl;
            }
            else
            {
            cout << SubtractNumbers(b,d) << "i" << endl;
            }
        }
        else
        {
            cout << "Вы выбрали невозможное действие. Попробуйте еще раз." << endl;
        }
    }
    return 0;
}

float SubtractNumbers(float a, float b)
{
    return (a-b);
}

double SubtractNumbers(double a, double c)
{
    return (a-c);
}
