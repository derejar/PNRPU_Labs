/*
Сформировать двоичный файл из элементов,
заданной в варианте структуры,
распечатать его содержимое,
выполнить удаление и добавление элементов в соответствии со своим вариантом
используя для поиска удаляемых или добавляемых элементов функцию.
Формирование, печать, добавление и удаление эле-ментов оформить в виде функций.
Предусмотреть сообщения об ошибках при открытии файла и выполнении операций ввода/вывода.

6.	 Структура "Школьник":
-	фамилия, имя, отчество;
-	класс;
-	номер телефона;
-	оценки по предметам (математика, физика, русский язык, литература).
Удалить все элементы, у которых есть 2 хотя бы по одному предмету, добавить элемент в начало файла.
*/
#include <iostream>
#include <stdio.h>
#include <windows.h>

using namespace std;

FILE *lab8;

int count;
int *ptrCount = &count;

struct schoolBoy
{
string firstName, secondName, fatherName, phoneNumber;
int maths, phys, russian, literature;     
};

void errorCheck()
{
   if(lab8 == NULL)
   {
      perror("Ошибка! ");
      exit(1);
   }
}
void create(int);
void print(int);
void deleteSchoolBoy(int);
void add(int);
void readData(int, schoolBoy);

int main()
{
   setlocale(LC_ALL, "Russian");
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251); 

   int choose;
   count=0;
   while(choose!=3)
   {
      cout << endl;
      cout << "Выберите действие: " << endl;
      cout << "[0] Удаление элементов с 2 хотя бы по одному предмету" << endl;
      cout << "[1] Добавление элементов в начало файла" << endl;
      cout << "[2] Напечатать содержимое файла" << endl;
      cout << "[3] Выход" << endl;
      cin >> choose;
      cout << endl;
      switch(choose)
      {
         case 0:
            deleteSchoolBoy(count); break;
         case 1:
            add(count); break;
         case 2:
            print(count); break;
         case 3:
            choose=3; break;
         default:
            cout << "Введено неверное значение. Попробуйте еще раз." << endl; break;
      }
   }
   return 0;
}

void readData(int i, schoolBoy *memory)
{
   cout << "Введите имя: ";
   cin >> memory[i].firstName;
   cout << "Введите фамилию: ";
   cin >> memory[i].secondName;
   cout << "Введите отчество: ";
   cin >> memory[i].fatherName;
   cout << "Введите номер телефона: ";
   cin >> memory[i].phoneNumber;
   cout << "Введите оценку по математике: ";
   cin >> memory[i].maths;
   cout << "Введите оценку по физике: ";
   cin >> memory[i].phys;
   cout << "Введите оценку по русскому языку: ";
   cin >> memory[i].russian;
   cout << "Введите оценку по литературе: ";
   cin >> memory[i].literature;
   cout << endl;
}

void print(int count)
{
   if(count==0)
   {
      cout << "Файл пуст. Выполните добавление элементов в файл.";
   }
   else
   {
      schoolBoy *memory = new schoolBoy[count];
      cout << "Содержимое файла:" << endl;
      cout << endl;
      lab8 = fopen("school.txt", "rb");
      errorCheck();
      fread(&memory, sizeof(count), 1, lab8);
      for(int i=0; i<count; i++)
      {
         cout << "Cтудент №" << i+1 << ":" << endl;
         cout << "ФИО: " << memory[i].firstName << " " << memory[i].secondName << " " << memory[i].fatherName << endl;
         cout << "Номер телефона: " << memory[i].phoneNumber << endl;
         cout << "Оценки: " << endl;
         cout << "Математика: " << memory[i].maths << endl; 
         cout << "Физика: " << memory[i].phys << endl; 
         cout << "Русский язык: " << memory[i].russian << endl;  
         cout << "Литература: " << memory[i].literature << endl;
         cout << endl;
      }
      fclose(lab8);
   }
}

void deleteSchoolBoy(int count)
{
   if(count == 0)
   {
      cout << "Файл пуст, произвести удаление невозможно. Выполните добавление элементов в файл.";
   }
   else
   {
      schoolBoy *memory = new schoolBoy[count];
      lab8 = fopen("school.txt", "rb");
      errorCheck();
      fread(&memory, sizeof(count), 1, lab8);

      int reduce=0;
      
      for(int i=0; i<count; i++)
      {
         //Проверка, есть ли у стундента 2 по какому-либо из предметов:
         if(memory[i].maths == 2 || memory[i].phys == 2 || memory[i].russian == 2 || memory[i].literature == 2)
         {
            for(int j=i; j<count-1; j++)
            {
               memory[j].firstName = memory[j+1].firstName;
               memory[j].secondName = memory[j+1].secondName;
               memory[j].fatherName = memory[j+1].fatherName;
               memory[j].phoneNumber = memory[j+1].phoneNumber;
               memory[j].maths = memory[j+1].maths;
               memory[j].phys = memory[j+1].phys;
               memory[j].russian = memory[j+1].russian;
               memory[j].literature = memory[j+1].literature;
            }
            reduce++;
            i-1;
         }
      }
      *ptrCount = count-reduce;
      count -= reduce;
      schoolBoy *clearMemory = new schoolBoy[count];
      for(int i=0; i<count; i++)
      {
         clearMemory[i].firstName = memory[i].firstName;
         clearMemory[i].secondName = memory[i].secondName;
         clearMemory[i].fatherName = memory[i].fatherName;
         clearMemory[i].phoneNumber = memory[i].phoneNumber;
         clearMemory[i].maths = memory[i].maths;
         clearMemory[i].phys = memory[i].phys;
         clearMemory[i].russian = memory[i].russian;
         clearMemory[i].literature = memory[i].literature;
      }
      delete [] memory;
      fclose(lab8);
      lab8 = fopen("school.txt", "wb");
      errorCheck();
      fwrite(&clearMemory, sizeof(schoolBoy), 1, lab8);
      fclose(lab8);
      if(reduce==0)
      {
         cout << "Не найдено элементов для удаления." << endl;
      }
      else
      {
      cout << "Элементы успешно удалены." << endl;
      }
   }
}

void add(int count)
{
   schoolBoy *oldMemory = new schoolBoy[count];//Память для информации из файла
   lab8 = fopen("school.txt", "rb");
   errorCheck();
   fread(&oldMemory, sizeof(count), 1, lab8);
   fclose(lab8);

   cout << "Введите количество элементов для добавления в начало файла: ";
   int countOfElements;
   cin >> countOfElements;
   schoolBoy *memory = new schoolBoy[countOfElements];//Память для новой информации
   for(int i=0; i<countOfElements; i++)
   {
      readData(i, memory);
   }

   int sum = count+countOfElements;
   schoolBoy *newMemory = new schoolBoy[sum];//Совместная память
   *ptrCount = count + countOfElements;
   count = count + countOfElements;
   for(int i=0; i<countOfElements; i++)
   {
      newMemory[i].firstName = memory[i].firstName;
      newMemory[i].secondName = memory[i].secondName;
      newMemory[i].fatherName = memory[i].fatherName;
      newMemory[i].phoneNumber = memory[i].phoneNumber;
      newMemory[i].maths = memory[i].maths;
      newMemory[i].phys = memory[i].phys;
      newMemory[i].russian = memory[i].russian;
      newMemory[i].literature = memory[i].literature;
   }
   for(int i=countOfElements; i<count; i++)  
   {
      newMemory[i].firstName = oldMemory[i-countOfElements].firstName;
      newMemory[i].secondName = oldMemory[i-countOfElements].secondName;
      newMemory[i].fatherName = oldMemory[i-countOfElements].fatherName;
      newMemory[i].phoneNumber = oldMemory[i-countOfElements].phoneNumber;
      newMemory[i].maths = oldMemory[i-countOfElements].maths;
      newMemory[i].phys = oldMemory[i-countOfElements].phys;
      newMemory[i].russian = oldMemory[i-countOfElements].russian;
      newMemory[i].literature = oldMemory[i-countOfElements].literature;
   }
   lab8 = fopen("school.txt", "wb");
   errorCheck();
   fwrite(&newMemory, sizeof(schoolBoy), 1, lab8);
   fclose(lab8);
}