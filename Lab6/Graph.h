#pragma once
#include <vector>
#include <iostream>
#include <string>
using namespace std;

struct Vertex {
    int name;
    bool visited;
    int dfsNumber;
    std::vector<Vertex*> neighbours;
};

vector<int> split(string str);
vector<Vertex *> readGraph();

void printCarcass(vector<vector<int>> &carcass);
void DFS(vector<Vertex *> &graph, Vertex *start);
void BFS(vector<Vertex *> &graph, Vertex *start);
void DFSRecursive(vector<Vertex *> &graph, Vertex *start, int &DFS, vector<vector<int>> &carcass);