#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int *arrSize = new int;
int *countOfDeletedElements = new int(0);
int *countOfFullyDeletedElements = new int(0);
int *sizeSavedToFile = new int;

bool *smthingDeleted = new bool(false);
bool *savedToFile = new bool(false);

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
    short isDeleted=0; //показатель, был ли удален элемент. Если достигает значения 2 и более - очищать из массива
};

void printArray(humanInfo *infoArr)
{
    int count=1;
    cout << endl << "ВАШ МАССИВ: " << endl;
    for(int i=0; i<*arrSize; i++)
    {
        if(infoArr[i].isDeleted == 0)
        {
                cout << endl; 
                cout << count << " элемент:" << endl;
                cout << "ФИО: " << infoArr[i].fio << endl;
                cout << "Номер паспорта: " << infoArr[i].passNum << endl;
                cout << "Улица " << infoArr[i].registration->streetName << ", дом " << infoArr[i].registration->houseNum << ", кв. " << infoArr[i].registration->apartNum << endl;
            count++;  
        }
    }
}

void infoGenerator(humanInfo *infoArr, int startingElem, int endingElem)
{
    for(int i=startingElem; i<endingElem; i++)
    {
        string firstNames[] = {"Александр", "Алексей", "Анатолий", "Андрей", "Антон", "Арсений", "Артем", "Борис", "Вадим", "Валентин",
        "Валерий", "Василий", "Виктор", "Виталий", "Владимир", "Георгий", "Даниил", "Денис", "Дмитрий", "Евгений"};

        string familyNames[] = {"Воробьев", "Богданов", "Виноградов", "Голубев", "Семенов", "Павлов", "Зайцев", "Васильев", "Соловьев",
        "Волков", "Петров", "Морозов", "Новиков", "Козлов", "Лебедев", "Соколов", "Попов", "Кузнецов", "Иванов", "Смирнов"};

        string fatherNames[] = {"Александрович", "Андреевич", "Богданович", "Валентинович", "Витальевич", "Георгиевич", "Григорьевич", "Игоревич", "Иванович", "Ильич",
        "Кириллович", "Константинович", "Максимович", "Михайлович", "Николаевич", "Олегович", "Павлович", "Петрович", "Романович", "Сергеевич"};

        infoArr[i].fio = familyNames[rand()%20] + " " + firstNames[rand()%20] + " " + fatherNames[rand()%20]; //генерация фио

        infoArr[i].passNum = (100+rand()%900)*1000+(100+rand()%900); //генерация номера паспорта (3 первых цифры + 3 последних)

        //генерация улицы, номера дома, номера квартиры:
        string streetNames[] = {"Центральная", "Молодежная", "Школьная", "Лесная", "Советская", "Новая", "Садовая", "Набережная", "Заречная", "Зеленая",
        "Мира", "Ленина", "Полевая", "Луговая", "Октябрьская", "Комсомольская", "Гагарина", "Первомайская", "Северная", "Солнечная"};
        infoArr[i].registration->streetName = streetNames[rand()%20];
        infoArr[i].registration->houseNum = rand()%150;
        infoArr[i].registration->apartNum = rand()%80;
    }
}

void manualInput(humanInfo *infoArr, int startingElem, int endingElem)
{
    int count=1;
    for(int i=startingElem; i<endingElem; i++)
    {
        cout << endl;
        cout << "Ввод " << count << " элемента: " << endl;
        string firstName, familyName, fatherName;
        cout << "Введите фамилию: ";
        cin >> familyName;
        cout << "Введите имя: ";
        cin >> firstName;
        cout << "Введите отчество: ";
        cin >> fatherName;
        infoArr[i].fio = familyName + " " + firstName + " " + fatherName;
        cout << "Введите номер паспорта (6 цифр): ";
        cin >> infoArr[i].passNum;
        cout << "Введите название улицы: ";
        cin >> infoArr[i].registration->streetName;
        cout << "Введите номер дома: ";
        cin >> infoArr[i].registration->houseNum;
        cout << "Введите номер квартиры: ";
        cin >> infoArr[i].registration->apartNum;
        count++;
    }
}

void saveToFile(humanInfo *infoArr)
{
    *savedToFile = true;
    *sizeSavedToFile = (*arrSize) - ((*countOfFullyDeletedElements) + (*countOfDeletedElements));
    ofstream file;
    file.open("HumansInfo.txt");
    for(int i=0; i<*arrSize; i++)
    {
        file << infoArr[i].fio << endl << infoArr[i].passNum;
        file << infoArr[i].registration->streetName << " " << infoArr[i].registration->houseNum << " " << infoArr[i].registration->apartNum << endl;
        file << infoArr[i].isDeleted << endl;
    }
    file.close();
    cout << endl << "Массив успешно сохранен в файл." << endl;
}

void downloadFromFile(humanInfo *infoArr)
{
    ifstream file("HumansInfo.txt");
    *smthingDeleted = false;
    string familyName, firstName, fatherName;
    for(int i=0; i<*sizeSavedToFile; i++)
    {
        file >> familyName >> firstName >> fatherName;
        infoArr[i].fio = familyName + " " + firstName + " " + fatherName;
        file >> infoArr[i].passNum;
        file >> infoArr[i].registration->streetName;
        file >> infoArr[i].registration->houseNum;
        file >> infoArr[i].registration->apartNum;
        file >> infoArr[i].isDeleted;
        if(infoArr[i].isDeleted > 0)
        {
            i--;
        }
    }
    cout << endl;
    *arrSize = *sizeSavedToFile;
    file.close();
}

humanInfo *addElement(humanInfo *infoArr)
{
    int newArrSize = *arrSize;
    int methodChoosing;
    cout << endl;
    cout << "Выберите метод добавления элеменов: " << endl;
    cout << "[1] Ручной ввод." << endl;
    cout << "[2] Автоматическая генерация." << endl;
    cout << "Ваш выбор: ";
    while(methodChoosing!=1 && methodChoosing!=2)
    {
        cin >> methodChoosing;    
    }
    int addChoosing=10;
    cout << endl;
    cout << "Выберите место для добавления элементов: " << endl;
    cout << "[1] В начало массива." << endl;
    cout << "[2] В конец массива." << endl;
    cout << "[3] На указанный номер." << endl;
    cout << "Ваш выбор: ";
    while(addChoosing<0 || addChoosing>4)
    {
        cin >> addChoosing;
    }
    int elementNumber=0;
    if(addChoosing == 3)
    {
        while(elementNumber < 1 || elementNumber > *arrSize+1)
        {
            cout << "Введите номер элемента: ";
            cin >> elementNumber;
            if(elementNumber < 1 || elementNumber > *arrSize+1)
            {
                cout << "Введен неправильный номер! Попробуйте снова." << endl;
            }
        }
    }
    cout << "Введите количество элементов для добавления: ";
    int countOfElements;
    cin >> countOfElements;
    newArrSize += countOfElements - (*countOfFullyDeletedElements);
    humanInfo *newArr = new humanInfo[newArrSize];
    if(addChoosing == 1)
    {
        if(methodChoosing == 1)
        {
            manualInput(newArr, 0, countOfElements);
        }
        else if (methodChoosing == 2)
        {
            infoGenerator(newArr, 0, countOfElements);
        }
    }
    else if (addChoosing == 2)
    {
        if(methodChoosing == 1)
        {
            manualInput(newArr, ((newArrSize)-countOfElements), newArrSize);
        }
        else if (methodChoosing == 2)
        {
            infoGenerator(newArr, ((newArrSize)-countOfElements), newArrSize);
        }
    }
    else if(addChoosing == 3)
    {
        if(methodChoosing == 1)
        {
            manualInput(newArr, elementNumber-1, (elementNumber+countOfElements)-1);
        }
        else if (methodChoosing == 2)
        {
            infoGenerator(newArr, elementNumber-1, (elementNumber+countOfElements)-1);
        }
    }
    int *elemNum = new int(0);
    for(int i=0; i<newArrSize; i++)
    {
        if(newArr[i].fio == "" && newArr[i].registration->streetName == "")
        {
            while(infoArr[*elemNum].isDeleted > 1 && (*elemNum) < ((*arrSize)))
            {
                (*elemNum)++;
            }
            newArr[i] = infoArr[*elemNum];
            (*elemNum)++;
        }
    }
    *arrSize = newArrSize;
    *countOfFullyDeletedElements=0;
    delete elemNum;
    delete[] infoArr;
    return newArr;
}

void delElements(humanInfo *infoArr)
{
    *smthingDeleted = true;
    for(int i=0; i<*arrSize; i++)
    {
        if(infoArr[i].isDeleted == 1)
        {
            infoArr[i].isDeleted++;
        }
    }
    int elemCounts = -1;
    while(elemCounts > *arrSize || elemCounts < 1)
    {
        cout << "Введите количество элементов для удаления: ";
        cin >> elemCounts;
        if(elemCounts > *arrSize || elemCounts < 1)
        {
            cout << "Невозможно удалить указанное количество элементов! Попробуйте ввести другое число." << endl;
        }
    }
    *countOfFullyDeletedElements += *countOfDeletedElements;
    *countOfDeletedElements = 0;
    *countOfDeletedElements += elemCounts;
    cout << "Выберите способ удаления: " << endl;
    cout << "[1] По номеру элемента." << endl;
    cout << "[2] По адресу." << endl;
    cout << "Ваш выбор: ";
    int delMode=0;
    while(delMode!=1 && delMode!=2)
    {
        cin >> delMode;
    }
    for(int i=0; i<elemCounts; i++)
    {
        if(delMode == 1)
        {
            int delNum = -1;
            while(delNum < 1 || delNum > *arrSize+1)
            {
                cout << "Введите номер элемента для удаления: ";
                cin >> delNum;
                if(delNum < 1 || delNum > *arrSize+1)
                {
                    cout << "Введен неправильный номер! Попробуйте снова." << endl;
                }
            }
            infoArr[delNum-1].isDeleted++;
        }
        else if(delMode == 2)
        {
            string streetName;
            int houseNum, apartNum;
            cout << "Введите название улицы: ";
            cin >> streetName;
            cout << "Введите номер дома: ";
            cin >> houseNum;
            cout << "Введите номер квартиры: ";
            cin >> apartNum;
            
            bool smthingDeleted = false;
            for(int i=0; i<*arrSize; i++)
            {
                if(infoArr[i].registration->streetName == streetName && infoArr[i].registration->houseNum == houseNum
                    && infoArr[i].registration->apartNum == apartNum && infoArr[i].isDeleted == 0)
                {
                    cout << "Элемент успешно найден и удален." << endl;
                    smthingDeleted = true;
                    infoArr[i].isDeleted++;
                }
            }
            if(!smthingDeleted)
            {
                cout << "Элемент не найден!" << endl;
            }
        }
    }
}

void cancelDel(humanInfo *infoArr)
{
    *smthingDeleted = false;
    *countOfDeletedElements = 0;
    for(int i=0; i<*arrSize; i++)
    {
        if(infoArr[i].isDeleted == 1)
        {
            infoArr[i].isDeleted--;
        }
    }
    cout << endl << "Последнее удаление отменено." << endl;
}