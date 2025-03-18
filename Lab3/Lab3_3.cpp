#include <iostream>
#include <vector>
#include "Comp.h"
#include "Sort.h"
#include <windows.h>
using namespace std;
int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    while (true)
    {
        int n;
        int k;
        cout << "\nВведіть довжину множини: ";
        cin >> n;
        if (n < 2)
        {
            cout << "Неправильний ввід.";
            continue;
        }
        datatype array(n);
        for (int i = 0; i < n; i++)
        {
            cout << "Введіть елемент " << i << ": ";
            cin >> array[i];
        }
        SortBubble(array, 0, n);
        cout << "\nВведіть довжину сполучення: ";
        cin >> k;
        if (k < 2 || k > n)
        {
            cout << "Неправильний ввід.";
            continue;
        }
        datatype comb(k);
        for (int i = 0; i < k; i++)
        {
            cout << "Введіть елемент " << i << ": ";
            cin >> comb[i];
        }
        SortBubble(comb, 0, k);
        for (int i = 1; i < C(k, n); i++)
        {
            GenComb(array, comb);
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