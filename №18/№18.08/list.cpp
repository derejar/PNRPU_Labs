#include "list.h"
#include "person.h"
#include "student.h"
#include <iostream>

List::List()
{
    start = new Node;  
    currentPosition = start;
    size = 0;
    start->data = nullptr;
    start->next = nullptr;
}

void List::add()
{
    std::cout << "Выберите, какого типа объект вы хотите создать: " << std::endl;
    std::cout << "[1] Человек." << std::endl << "[2] Студент." << std::endl << "Ваш выбор: ";
    int choose;
    std::cin >> choose;

    Node *temp = new Node;
    currentPosition->next = temp;
    temp->next = nullptr;

    if(choose==1)
    {
        temp->data = new Person;
        temp->data->input();
    }
    else if(choose==2)
    {
        temp->data = new Student;
        temp->data->input();
    }
    else
    {
        std::cout << "Введено неверное значение!" << std::endl;
        return;
    }

    if(size==0)
    {
        start = currentPosition = temp;
    }
    else
    {
        currentPosition = temp;
    }
    size++;
}

void List::del()
{
    if(size==0)
    {
        std::cout << "Список пуст!" << std::endl;
        return;
    }
    std::cout << "Введите имя элемента для его удаления: ";
    std::string toDel;
    std::cin >> toDel;
    Node *temp = start;
    Node *forChange;
    while(toDel != temp->data->getName() && temp != nullptr)
    {
        forChange = temp;
        temp = temp->next;
    }
    if(toDel == temp->data->getName())
    {
        forChange->next = temp->next;
        delete temp;
        size--;
    } 
}

void List::show()
{
    if(size==0)
    {
        std::cout << "Список пуст!" << std::endl;
        return;
    }
    else
    {
        Node *temp = start;
        int counter = 1;
        while(temp!=nullptr)
        {
            std::cout << counter << " элемент: " << std::endl;
            temp->data->show();
            temp = temp->next;
            std::cout << std::endl;
            counter++;
        }
    }
}

void List::getInfo(int index)
{
    if(index > size || index == 0)
    {
        std::cout << "Указанный элемент не существует!" << std::endl;
        return;
    }
    else
    {
        int counter = 1;
        Node *temp = start;
        while(counter != index)
        {
            temp = temp->next;
            counter++;
        }
        std::cout << counter << " элемент: " << std::endl;
        temp->data->show();
        temp = temp->next;
        std::cout << std::endl;
    }
}