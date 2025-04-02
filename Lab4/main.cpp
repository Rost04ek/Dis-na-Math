#include <iostream>
#include "List.h"
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    Node *head = nullptr;
    Node *front = nullptr;
    Node *rear = nullptr;
    Node *first = nullptr;
    Node *last = nullptr;
    
    while (true)
    {
        int userAnswer;
        cout << "\n1. Стек\n2. Черга\n3. Двоспрямований список\n4. Вихід" << endl;
        cout << "Оберіть опцію: ";
        cin >> userAnswer;
        
        if (userAnswer == 1)
        {
            cout << "\n1. Додати до стеку\n2. Видалити зі стеку" << endl;
            cout << "Оберіть опцію: ";
            cin >> userAnswer;
            if (userAnswer == 1)
            {
                int num;
                cout << "Введіть число для додавання: ";
                cin >> num;
                push(head, num);
                show(head);
            }
            else if (userAnswer == 2)
            {
                pop(head);
                show(head);
            }
            else
            {
                cout << "Неправильний ввід" << endl;
                continue;
            }
        }
        else if (userAnswer == 2)
        {
            cout << "\n1. Додати до черги\n2. Видалити з черги" << endl;
            cout << "Оберіть опцію: ";
            cin >> userAnswer;
            if (userAnswer == 1)
            {
                int num;
                cout << "Введіть число для додавання: ";
                cin >> num;
                enqueue(front, rear, num);
                show(front);
            }
            else if (userAnswer == 2)
            {
                dequeue(front);
                show(front);
            }
            else
            {
                cout << "Неправильний ввід" << endl;
                continue;
            }
        }
        else if (userAnswer == 3)
        {
            cout << "\n1. Додати на початок\n2. Додати в кінець\n3. Видалити з початку\n4. Видалити з кінця\n5. Додати в середину\n6. Видалити з середини" << endl;
            cout << "Оберіть опцію: ";
            cin >> userAnswer;
            if (userAnswer == 1)
            {
                int num;
                cout << "Введіть число для додавання: ";
                cin >> num;
                addBegin(first, last, num);
                show(first);
            }
            else if (userAnswer == 2)
            {
                int num;
                cout << "Введіть число для додавання: ";
                cin >> num;
                addEnd(first, last, num);
                show(first);
            }
            else if (userAnswer == 3)
            {
                delBegin(first, last);
                show(first);
            }
            else if (userAnswer == 4)
            {
                delEnd(first, last);
                show(first);
            }
            else if (userAnswer == 5)
            {
                int num;
                cout << "Введіть число для додавання: ";
                cin >> num;
                int key;
                cout << "Введіть число, після якого потрібно додати: ";
                cin >> key;
                addMid(first, last, num, key);
                show(first);
            }
            else if (userAnswer == 6)
            {
                int key;
                cout << "Введіть число, яке потрібно видалити: ";
                cin >> key;
                delMid(first, last, key);
                show(first);
            }
            else
            {
                cout << "Неправильний ввід" << endl;
                continue;
            }
        }
        else if (userAnswer == 4)
        {
            cout << "Дякуємо за використання програми!" << endl;
            break;
        }
        else
        {
            cout << "Неправильний ввід" << endl;
            continue;
        }
    }
    return 0;
}