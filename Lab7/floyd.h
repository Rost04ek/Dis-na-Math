#pragma once
#include <vector>
#include <string>

const int INF = 1000000000;

void floydWarshall(
    const std::vector<std::vector<int>>& d0,
    std::vector<std::vector<int>>& d,
    std::vector<std::vector<int>>& p,
    std::vector<std::vector<int>>& historyD,
    std::vector<std::vector<int>>& historyP
);

void printMatrix(const std::vector<std::vector<int>>& mat, const std::string& name);
void printPred(const std::vector<std::vector<int>>& pred, const std::string& name);
void printPath(int u, int v, const std::vector<std::vector<int>>& pred);