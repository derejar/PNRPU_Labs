#include <iostream>
#include <string>

using namespace std;

int *arrSize = new int(0);
int *tableSize = new int(0);
int *countOfCollusions = new int(0);
int *countOfElements = new int(0);

struct humanInfo
{
    struct address
    {
        string streetName; //название улицы
        int houseNum; //номер дома
        int apartNum; //номер квартиры
    };
    string fio; //фио
    int passNum; //номер паспорта
    address *registration = new address; //адрес
    int hash;
};

int makeHash(string streetName, int houseNum, int apartNum);

void print(vector<humanInfo> hashTable) //Печать таблицы
{
    cout << endl << "ХЕШ-ТАБЛИЦА: " << endl;
    for(int i=0; i<*tableSize; i++)
    {
        cout << endl; 
        cout << i << " элемент:" << endl;
        if(hashTable[i].fio == "")
        {
            cout << "Элемент пуст." << endl;
        }
        else
        {
            cout << "ФИО: " << hashTable[i].fio << endl;
            cout << "Номер паспорта: " << hashTable[i].passNum << endl;
            cout << "Улица " << hashTable[i].registration->streetName << ", дом " << hashTable[i].registration->houseNum << ", кв. " << hashTable[i].registration->apartNum << endl;
            cout << "Хеш: " << hashTable[i].hash << endl;
        }  
    }
}

void elemOfTableGenerator(vector<humanInfo> &hashTable) //Создание элемента таблицы
{
    //генерация улицы, номера дома, номера квартиры:
    string streetNames[] = {"Центральная", "Молодежная", "Школьная", "Лесная", "Советская", "Новая", "Садовая", "Набережная", "Заречная", "Зеленая",
    "Мира", "Ленина", "Полевая", "Луговая", "Октябрьская", "Комсомольская", "Гагарина", "Первомайская", "Северная", "Солнечная"};
    string tempStreetName = streetNames[rand()%20];
    int tempHouseNum = rand()%150;
    int tempApartNum = rand()%80;
    int hash = makeHash(tempStreetName, tempHouseNum, tempApartNum);
    int resHash = hash;
    if(hashTable[hash%(*tableSize)].fio != "")
    {
        while(hashTable[hash%(*tableSize)].fio != "")
        {
            hash++;
            (*countOfCollusions)++;
        }
    }
    hash%=(*tableSize);

    string firstNames[] = {"Александр", "Алексей", "Анатолий", "Андрей", "Антон", "Арсений", "Артем", "Борис", "Вадим", "Валентин",
    "Валерий", "Василий", "Виктор", "Виталий", "Владимир", "Георгий", "Даниил", "Денис", "Дмитрий", "Евгений"};

    string familyNames[] = {"Воробьев", "Богданов", "Виноградов", "Голубев", "Семенов", "Павлов", "Зайцев", "Васильев", "Соловьев",
    "Волков", "Петров", "Морозов", "Новиков", "Козлов", "Лебедев", "Соколов", "Попов", "Кузнецов", "Иванов", "Смирнов"};

    string fatherNames[] = {"Александрович", "Андреевич", "Богданович", "Валентинович", "Витальевич", "Георгиевич", "Григорьевич", "Игоревич", "Иванович", "Ильич",
    "Кириллович", "Константинович", "Максимович", "Михайлович", "Николаевич", "Олегович", "Павлович", "Петрович", "Романович", "Сергеевич"};

    hashTable[hash].fio = familyNames[rand()%20] + " " + firstNames[rand()%20] + " " + fatherNames[rand()%20]; //генерация фио
    hashTable[hash].passNum = (100+rand()%900)*1000+(100+rand()%900); //генерация номера паспорта (3 первых цифры + 3 последних)
    hashTable[hash].registration->streetName = tempStreetName;
    hashTable[hash].registration->houseNum = tempHouseNum;
    hashTable[hash].registration->apartNum = tempApartNum;
    hashTable[hash].hash = resHash;
    (*countOfElements)++;
}

int makeHash(string streetName, int houseNum, int apartNum) //Расчет хеша
{
    int countToEnd=0;
    float preResult=0;
    while(countToEnd<streetName.length())
    {
        preResult += streetName[countToEnd]; 
        countToEnd++;
    }
    preResult += apartNum + houseNum;
    preResult *= 0.7835;
    float *intPart = new float;
    preResult = (round(modf(preResult, intPart)*10000)/10000);
    int result = preResult*(*tableSize);
    if(result < 0)
    {
        result*=-1;
    }
    return result;   
}

void resizeTable(vector<humanInfo> &hashTable) //Изменение размера таблицы
{
    *tableSize *= 2;
    vector<humanInfo> temp(*tableSize);
    for(int i=0; i<(*tableSize)/2; i++)
    {
        if(hashTable[i].fio != "")
        {
            int hash = makeHash(hashTable[i].registration->streetName, hashTable[i].registration->houseNum, hashTable[i].registration->apartNum);
            hashTable[i].hash = hash;
            while(temp[hash%(*tableSize)].fio != "")
            {
                hash++;
                (*countOfCollusions)++;
            }
            hash%=(*tableSize);
            temp[hash] = hashTable[i];
        }
    }
    hashTable.swap(temp);
    temp.clear();
}

void searchElem(vector<humanInfo> &hashTable)
{
    bool finded = true;
    string searchStreetName;
    int searchHouseNum, searchApartNum;
    cout << "Введите название улицы: ";
    cin >> searchStreetName;
    cout << "Введите номер дома: ";
    cin >> searchHouseNum;
    cout << "Введите номер квартиры: ";
    cin >> searchApartNum;
    int hash = makeHash(searchStreetName, searchHouseNum, searchApartNum);
    int tempHash = hash;
    while(hashTable[hash].registration->streetName != searchStreetName || hashTable[hash].registration->houseNum != searchHouseNum || hashTable[hash].registration->apartNum != searchApartNum)
    {
        if(hash%(*tableSize) == tempHash-1)
        {
            finded = false;
            break;
        }
        hash++;
        hash%=(*tableSize);
    }
    if(finded)
    {
        cout << endl << "Элемент найден!" << endl; 
        cout << hash << " элемент:" << endl;
        cout << "ФИО: " << hashTable[hash].fio << endl;
        cout << "Номер паспорта: " << hashTable[hash].passNum << endl;
        cout << "Улица " << hashTable[hash].registration->streetName << ", дом " << hashTable[hash].registration->houseNum << ", кв. " << hashTable[hash].registration->apartNum << endl;
        cout << "Хеш: " << hashTable[hash].hash << endl << endl;
    }
    else
    {
        cout << endl << "Элемент не найден!" << endl << endl;
    }
}