#include "floyd.h"
#include <iostream>
#include <iomanip>

// --- Вивід матриці ---
void printMatrix(const std::vector<std::vector<int>>& mat, const std::string& name) {
    std::cout << name << ":\n";
    for (const auto& row : mat) {
        for (int val : row) {
            if (val == INF)
                std::cout << std::setw(6) << "INF";
            else
                std::cout << std::setw(6) << val;
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

// --- Вивід матриці предків ---
void printPred(const std::vector<std::vector<int>>& pred, const std::string& name) {
    std::cout << name << ":\n";
    for (const auto& row : pred) {
        for (int val : row) {
            if (val == -1)
                std::cout << std::setw(6) << "-";
            else
                std::cout << std::setw(6) << val;
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

// --- Відновлення шляху ---
void printPath(int u, int v, const std::vector<std::vector<int>>& pred) {
    if (u == v) {
        std::cout << u;
        return;
    }
    if (pred[u][v] == -1) {
        std::cout << "немає шляху";
        return;
    }
    std::vector<int> path;
    int cur = v;
    while (cur != u) {
        path.push_back(cur);
        cur = pred[u][cur];
        if (cur == -1) {
            std::cout << "немає шляху";
            return;
        }
    }
    path.push_back(u);
    for (int i = path.size() - 1; i >= 0; --i) {
        std::cout << path[i];
        if (i != 0) std::cout << " -> ";
    }
}

// --- Основний алгоритм Флойда-Воршелла ---
void floydWarshall(
    const std::vector<std::vector<int>>& d0,
    std::vector<std::vector<int>>& d,
    std::vector<std::vector<int>>& p,
    std::vector<std::vector<int>>& historyD,
    std::vector<std::vector<int>>& historyP
) {
    int n = d0.size();
    d = d0;
    p.assign(n, std::vector<int>(n, -1));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j && d0[i][j] < INF)
                p[i][j] = i;

    printMatrix(d, "Матриця d(0)");
    printPred(p, "Матриця p(0)");

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (d[i][k] < INF && d[k][j] < INF && d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
        std::cout << "Після k = " << k+1 << ":\n";
        printMatrix(d, "d");
        printPred(p, "p");
    }
}