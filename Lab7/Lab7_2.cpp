
#include <iostream>
#include <vector>
#include <windows.h>
#include "floyd.h"

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    // --- Крок 2: Матриця ваг (суміжності) ---
    std::vector<std::vector<int>> d0 = {
        {0,   4,   1, INF, INF, INF, INF},
        {4,   0,   8, 21,  INF, INF, INF},
        {1,   8,   0, 15,  3,   INF, INF},
        {INF, 21, 15, 0,   7,   20,  INF},
        {INF, INF, 3, 7,   0,   8,   9},
        {INF, INF, INF, 20, 8,   0,   5},
        {INF, INF, INF, INF, 9,   5,   0}
    };

    int n = d0.size();
    std::vector<std::vector<int>> d, p;
    std::vector<std::vector<int>> historyD, historyP;

    // --- Основний алгоритм ---
    floydWarshall(d0, d, p, historyD, historyP);

    // --- Перевірка наявності циклів від’ємної довжини ---
    bool negativeCycle = false;
    for (int i = 0; i < n; ++i)
        if (d[i][i] < 0)
            negativeCycle = true;

    if (negativeCycle) {
        std::cout << "У графі є цикл від’ємної довжини!\n";
        return 0;
    }

    // --- Крок 7: Відображення найкоротшого шляху між двома вершинами ---
    int u, v;
    std::cout << "Введіть початкову вершину (0-" << n-1 << "): ";
    std::cin >> u;
    std::cout << "Введіть кінцеву вершину (0-" << n-1 << "): ";
    std::cin >> v;
    std::cout << "Найкоротший шлях: ";
    printPath(u, v, p);
    if (d[u][v] == INF)
        std::cout << " (немає шляху)\n";
    else
        std::cout << " (довжина: " << d[u][v] << ")\n";

    return 0;
}