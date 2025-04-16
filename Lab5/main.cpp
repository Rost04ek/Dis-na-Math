#ifdef _WIN32
#include <windows.h>
#pragma comment(linker, "/SUBSYSTEM:CONSOLE")
#endif
#include <iostream>
#include "Converter.h"
#include <string>
using namespace std;

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    while (true)
    {
        int mode;
        cout << "1. Перетворити інфіксний у постфіксний вираз\n";
        cout << "2. Перетворити інфіксний у префіксний вираз\n";
        cout << "3. Перетворити постфіксний у інфіксний вираз\n";
        cout << "4. Перетворити префіксний у інфіксний вираз\n";
        cout << "5. Обчислити значення постфіксного виразу\n";
        cout << "6. Обчислити значення префіксного виразу\n";
        cout << "7. Вийти\n";
        cout << "Введіть ваш вибір: ";
        cin >> mode;
        if (mode == 7)
            break;
        datatype expression;
        cout << "Введіть вираз: ";
        cin.ignore();
        getline(cin, expression);
        if (mode == 1)
        {
            cout << "Постфіксний вигляд: " << InfixToPostfix(expression) << endl;
        }
        else if (mode == 2)
        {
            cout << "Префіксний вигляд: " << InfixToPrefix(expression) << endl;
        }
        else if (mode == 3)
        {
            cout << "Інфіксний вигляд: " << PostfixToInfix(expression) << endl;
        }
        else if (mode == 4)
        {
            cout << "Інфіксний вигляд: " << PrefixToInfix(expression) << endl;
        }
        else if (mode == 5)
        {
            cout << "Значення постфіксного виразу: " << countPostfix(expression) << endl;
        }
        else if (mode == 6)
        {
            cout << "Значення префіксного виразу: " << countPrefix(expression) << endl;
        }
        else
        {
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
            continue;
        }
    }
    return 0;
}