#include <iostream>
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
        int len;
        cout << "\nВведіть довжину перестановки: ";
        cin >> len;
        if (len < 2)
        {
            cout << "Неправильний ввід (занадто короткий)\n";
            continue;
        }
        if (len > 10)
        {
            cout << "Неправильний ввід (занадто довгий)\n";
            continue;
        }
        datatype array(len);
        for (int i = 0; i < len; i++)
        {
            cout << "Елемент " << i << ": ";
            cin >> array[i];
        }
        PrintArray(array);
        bool hasNext = true;
        while (hasNext)
        {
            GenPerm(array, array.size());
            for (int i = 1; i < array.size(); i++)
            {
                if (array[i - 1] < array[i])
                {
                    hasNext = true;
                    break;
                }
                hasNext = false;
            }
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
