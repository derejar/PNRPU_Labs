/*
6.
1) 	Скопировать из файла F1 в файл F2 строки, начиная с N до K.
2) 	Подсчитать количество согласных букв в файле F2.
*/

#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int num; //количество строчек для добавления в файл
    string line;

    cout << "Введите количество строк для добавления в файл: ";
    cin >> num;

    ofstream f1Write("f1.txt");
    if(!f1Write.is_open())
    {
        cout << "Не удалось открыть файл!";
        exit(1);
    }

    cout << "Вводите строки:" << endl;
    for (int i=0; i<num; i++)
    {
        cout << "[" << i+1 << "] ";
        cin >> line;
        f1Write << line << "\n"; 
    }
    f1Write.close();
    
    int start, end;
    cout << "\n" << "Введите номер строки с которой должно быть произведено копирование в другой файл: ";
    cin >> start;
    cout << "Введите номер строки, по которую будет выполнено копирование: ";
    cin >> end;
    cout << endl;

    ifstream f1Read("f1.txt");
    ofstream f2Write("f2.txt");
    
    if(!f2Write.is_open())
    {
        cout << "Не удалось открыть файл!";
        exit(2);
    }

    for(int i=0; i<end; i++)
    {
        getline(f1Read, line);

        if(i+1>=start)
        {
            f2Write << line << "\n";
        }
    }
    f1Read.close();
    f2Write.close();

    ifstream f2Read("f2.txt");

    cout << "Содержание второго файла: " << endl;
    int lineNum=0;
    while(getline(f2Read, line))
    {
        lineNum++;
        cout << "[" << lineNum << "] " << line << endl;
    }
    
    //Поиск согласных букв через гласные (их меньше в языке, следовательно поиск произведется быстрее)

    int choose;
    while(choose!=1 && choose!=2)
    {
        cout << "Выберите язык, на котором был записан текст в файлы: " << endl;
        cout << "[1] Русский" << endl;
        cout << "[2] Английский" << endl;
        cin >> choose;
    }

    f2Read.clear();
    f2Read.seekg(0);//Возврат к началу файла

    int countOfConsonants = 0;

    if(choose==1)
    {
        char searchRusConsonants[] = "аоуыэяёюиеъьАОУЫЭЯЁЮИУЬЪ"; //24
        while(getline(f2Read, line))
        {   
            for(int i=0; i<line.size(); i++)
            {
                bool find=false; //Показатель, найдена ли буква из файла среди гласных букв и букв "ъ, ъ"
                int j=0;
                while(j!=24 && find==false) //Использован while чтобы выходить из цикла при совпадении букв (break запрещен)
                {
                    if(line[i]==searchRusConsonants[j] && find==false)
                    {
                        find=true;
                    }
                    j++;
                }
                if(find==false)
                {
                    countOfConsonants++;
                }
            }
        }
    }

    else if(choose==2)
    {
        char searchEngConsonants[] = "aeiouyAEIOUY";
        while(getline(f2Read, line))
        {   
            for(int i=0; i<line.size(); i++)
            {
                bool find=false; //Показатель, найдена ли буква из файла среди гласных букв
                int j=0;
                while(j!=12 && find==false) //Использован while чтобы выходить из цикла при совпадении букв (break запрещен)
                {
                    if(line[i]==searchEngConsonants[j] && find==false)
                    {
                        find=true;
                    }
                    j++;
                }
                if(find==false)
                {
                    countOfConsonants++;
                }
            }
        }
    }
    f2Read.close();
    cout << "Количество согласных букв во втором файле: " << countOfConsonants << endl;
    return 0;
}