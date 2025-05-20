#include <iostream>
#include <vector>
#include "dijkstra.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    // Матриця суміжності (INF - немає ребра)
    std::vector<std::vector<int>> adj = {
        {0,   4,   1, INF, INF, INF, INF},
        {4,   0,   8, 21,  INF, INF, INF},
        {1,   8,   0, 15,  3,   INF, INF},
        {INF, 21, 15, 0,   7,   20,  INF},
        {INF, INF, 3, 7,   0,   8,   9},
        {INF, INF, INF, 20, 8,   0,   5},
        {INF, INF, INF, INF, 9,   5,   0}
    };

    int N = adj.size();
    int start, end, mode;
    std::cout << "Введіть режим (1 - від вершини до всіх, 2 - між двома вершинами): ";
    std::cin >> mode;
    std::cout << "Введіть початкову вершину (0-" << N-1 << "): ";
    std::cin >> start;

    std::vector<int> dist, prev;
    dijkstra(adj, start, dist, prev);

    if (mode == 1) {
        for (int v = 0; v < N; ++v) {
            std::cout << "Шлях до " << v << ": ";
            if (dist[v] == INF)
                std::cout << "немає шляху\n";
            else
                std::cout << getPath(start, v, prev) << " (довжина: " << dist[v] << ")\n";
        }
    } else if (mode == 2) {
        std::cout << "Введіть кінцеву вершину (0-" << N-1 << "): ";
        std::cin >> end;
        std::cout << "Шлях: ";
        if (dist[end] == INF)
            std::cout << "немає шляху\n";
        else
            std::cout << getPath(start, end, prev) << " (довжина: " << dist[end] << ")\n";
    }
    return 0;
}