#include "List.h"
#include <iostream>
#include <windows.h>
#include <locale>

// Встановлення української локалізації
void setUkrainianLocale() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Ukrainian");
}

void push(Node *&head, datatype key)
{
    try {
        Node *temp = new Node;
        temp->key = key;
        temp->next = head;
        head = temp;
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Помилка: Не вдалося виділити пам'ять." << std::endl;
    }
}

void pop(Node *&head)
{
    if (head == nullptr)
    {
        std::cout << "Стек порожній." << std::endl;
        return;
    }
    Node *temp = head;
    head = temp->next;
    delete temp;
}

void show(Node *head)
{
    if (head == nullptr)
    {
        std::cout << "Список порожній." << std::endl;
        return;
    }
    Node *temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->key << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void enqueue(Node *&front, Node *&rear, datatype data)
{
    try {
        Node *temp = new Node;
        temp->key = data;
        temp->next = nullptr;
        if (rear == nullptr)
        {
            front = temp;
        }
        else
        {
            rear->next = temp;
        }
        rear = temp;
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Помилка: Не вдалося виділити пам'ять." << std::endl;
    }
}

void dequeue(Node *&front)
{
    if (front == nullptr)
    {
        std::cout << "Черга порожня." << std::endl;
        return;
    }
    Node *temp = front;
    front = temp->next;
    delete temp;
}

void addBegin(Node *&first, Node *&last, datatype data)
{
    try {
        Node *temp = new Node;
        temp->key = data;
        temp->next = first;
        temp->previous = nullptr;
        if (first == nullptr && last == nullptr)
        {
            last = temp;
        }
        else
        {
            first->previous = temp;
        }
        first = temp;
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Помилка: Не вдалося виділити пам'ять." << std::endl;
    }
}

void addEnd(Node *&first, Node *&last, datatype data)
{
    try {
        Node *temp = new Node;
        temp->key = data;
        temp->next = nullptr;
        temp->previous = last;
        if (first == nullptr && last == nullptr)
        {
            first = temp;
        }
        else
        {
            last->next = temp;
        }
        last = temp;
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Помилка: Не вдалося виділити пам'ять." << std::endl;
    }
}

void delBegin(Node *&first, Node *&last)
{
    if (first == nullptr)
    {
        std::cout << "Список порожній." << std::endl;
        return;
    }
    Node *temp = first;
    first = temp->next;
    if (first == nullptr)
    {
        last = nullptr;
    }
    else
    {
        first->previous = nullptr;
    }
    delete temp;
}

void delEnd(Node *&first, Node *&last)
{
    if (last == nullptr)
    {
        std::cout << "Список порожній." << std::endl;
        return;
    }
    Node *temp = last;
    last = temp->previous;
    if (last == nullptr)
    {
        first = nullptr;
    }
    else
    {
        last->next = nullptr;
    }
    delete temp;
}

Node *search(Node *first, datatype data)
{
    if (first == nullptr) {
        std::cout << "Список порожній." << std::endl;
        return nullptr;
    }
    Node *temp = first;
    while (temp != nullptr)
    {
        if (data == temp->key)
        {
            return temp;
        }
        temp = temp->next;
    }
    std::cout << "Елемент " << data << " не знайдено у списку." << std::endl;
    return nullptr;
}

void addMid(Node *&first, Node *&last, datatype data, datatype key)
{
    Node *p = search(first, key);
    if (p == nullptr)
    {
        return;
    }
    try {
        if (p == last)
        {
            addEnd(first, last, data);
        }
        else
        {
            Node *temp = new Node;
            temp->key = data;
            temp->next = p->next;
            temp->previous = p;
            p->next = temp;
            (temp->next)->previous = temp;
        }
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Помилка: Не вдалося виділити пам'ять." << std::endl;
    }
}

void delMid(Node *&first, Node *&last, datatype key)
{
    Node *p = search(first, key);
    if (p == nullptr)
    {
        return;
    }
    if (p == last)
    {
        delEnd(first, last);
    }
    else if (p == first)
    {
        delBegin(first, last);
    }
    else
    {
        (p->previous)->next = p->next;
        (p->next)->previous = p->previous;
        delete p;
    }
}
