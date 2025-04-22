#include <iostream>
#include "Graph.h"
#include <vector>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    
    while (true)
    {
        int userChoice;
        cout << "\n1. Обхід у глибину (без рекурсії)\n";
        cout << "2. Обхід у глибину (рекурсивний)\n";
        cout << "3. Обхід у ширину\n";
        cout << "4. Вийти\n";
        cout << "Введіть ваш вибір: ";
        cin >> userChoice;

        if (userChoice == 1)
        {
            // Обхід у глибину без рекурсії
            vector<Vertex *> graph = readGraph();
            cout << endl;
            DFS(graph, graph[0]);
        }
        else if (userChoice == 2)
        {
            // Обхід у глибину з рекурсією та виведення кістяка
            vector<Vertex *> graph = readGraph();
            cout << endl;
            int dfs = 1;
            vector<vector<int>> carcass;
            DFSRecursive(graph, graph[0], dfs, carcass);
            cout << endl;
            printCarcass(carcass);
        }
        else if (userChoice == 3)
        {
            // Обхід у ширину
            vector<Vertex *> graph = readGraph();
            cout << endl;
            BFS(graph, graph[0]);
        }
        else if (userChoice == 4)
        {
            // Вихід з програми
            break;
        }
        else
        {
            cout << "Некоректне введення. Спробуйте ще раз." << endl;
            continue;
        }
    }
}