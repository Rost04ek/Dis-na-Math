#include <iostream>
#include <algorithm>
#include <windows.h>
#include "Comp.h"
using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    while (true)
    {
        int mode;
        cout << "\n1. Перестановка\n2. Сполучення\n3. Перестановка з повтореннями\n4. Сполучення з повтореннями\n5. Показати все\nВиберіть метод (1 - 5): ";
        cin >> mode;
        if (mode != 1 && mode != 2 && mode != 3 && mode != 4 && mode != 5)
        {
            cout << "Неправильний ввід\n";
            continue;
        }
        int n, k;
        cout << "\nВведіть n: ";
        cin >> n;
        cout << "Введіть k: ";
        cin >> k;
        if (k > n)
        {
            cout << "Неправильний ввід" << endl;
            continue;
        }
        switch (mode)
        {
        case 1:
            cout << "\nПерестановка: " << A(k, n) << endl;
            break;
        case 2:
            cout << "\nСполучення: " << C(k, n) << endl;
            break;
        case 3:
            cout << "\nПерестановка з повтореннями: " << _A(k, n) << endl;
            break;
        case 4:
            cout << "\nСполучення з повтореннями: " << _C(k, n) << endl;
            break;
        case 5:
            cout << "\nПерестановка: " << A(k, n) << endl;
            cout << "Перестановка з повтореннями: " << _A(k, n) << endl;
            cout << "Сполучення: " << C(k, n) << endl;
            cout << "Сполучення з повтореннями: " << _C(k, n) << endl;
            break;
        }
        string userAnswer;
        cout << "\nБажаєте продовжити? (y/n): ";
        cin >> userAnswer;
        if (userAnswer != "y")
        {
            break;
        }
    }
}
