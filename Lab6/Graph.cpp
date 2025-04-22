#include "Graph.h"
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// Функція для розділення рядка на числа (сусіди)
vector<int> split(string str)
{
    string temp = "";
    vector<int> neighbours;
    if (str == "-")
        return neighbours;
    for (int i = 0; i < str.length(); i++)
    {
        if (std::isdigit(str[i]))
        {
            temp += str[i];
        }
        else if (str[i] == ' ' && temp != "")
        {
            neighbours.push_back(stoi(temp));
            temp = "";
        }
    }
    if (temp != "")
    {
        neighbours.push_back(stoi(temp));
    }
    return neighbours;
}

// Зчитування графа з консолі
vector<Vertex *> readGraph()
{
    vector<Vertex *> graph;
    int vertexNumber;
    cout << "Введіть кількість вершин: ";
    cin >> vertexNumber;
    cin.ignore();
    for (int i = 0; i < vertexNumber; i++)
    {
        Vertex *v = new Vertex;
        v->name = i;
        v->visited = false;
        graph.push_back(v);
    }
    cout << "Введіть сусідів для кожної вершини.\nЯкщо немає сусідів, введіть -." << endl;
    for (int i = 0; i < graph.size(); i++)
    {
        string answer;
        cout << i << ": ";
        getline(cin, answer);
        vector<int> neighbourIndexes = split(answer);
        for (int j = 0; j < neighbourIndexes.size(); j++)
        {
            graph[i]->neighbours.push_back(graph[neighbourIndexes[j]]);
        }
    }
    return graph;
}

// Виведення ребер кістяка
void printCarcass(vector<vector<int>> &carcass)
{
    cout << "Ребра каркаса:" << endl;
    for (int i = 0; i < carcass.size(); i++)
    {
        cout << carcass[i][0] << " - " << carcass[i][1] << endl;
    }
}

// Обхід у глибину без рекурсії
void DFS(vector<Vertex *> &graph, Vertex *start)
{
    int DFSnum = 1;
    vector<vector<int>> carcass;
    stack<Vertex *> stack;
    start->visited = true;
    start->dfsNumber = DFSnum;
    stack.push(start);
    cout << "Вершина: " << start->name << " Номер обходу (DFS): " << start->dfsNumber << endl;
    while (!stack.empty())
    {
        bool neighboursVisited = true;
        for (int i = 0; i < stack.top()->neighbours.size(); i++)
        {
            Vertex *current = stack.top()->neighbours[i];
            if (current->visited == false)
            {
                carcass.push_back({stack.top()->name, current->name});
                current->visited = true;
                current->dfsNumber = ++DFSnum;
                stack.push(current);
                neighboursVisited = false;
                cout << "Вершина: " << current->name << " Номер обходу (DFS): " << current->dfsNumber << endl;
                break;
            }
        }
        if (neighboursVisited)
        {
            stack.pop();
        }
    }
    cout << endl;
    printCarcass(carcass);
}

// Рекурсивний обхід у глибину
void DFSRecursive(vector<Vertex *> &graph, Vertex *start, int &DFS, vector<vector<int>> &carcass)
{
    start->visited = true;
    start->dfsNumber = DFS++;
    cout << "Вершина: " << start->name << " Номер обходу (DFS): " << start->dfsNumber << endl;
    for (int i = 0; i < start->neighbours.size(); i++)
    {
        Vertex *current = start->neighbours[i];
        if (current->visited == false)
        {
            carcass.push_back({start->name, current->name});
            DFSRecursive(graph, current, DFS, carcass);
        }
    }
}

// Обхід у ширину
void BFS(vector<Vertex *> &graph, Vertex *start)
{
    int BFSnum = 1;
    queue<Vertex *> queue;
    vector<vector<int>> carcass;
    start->visited = true;
    start->dfsNumber = BFSnum;
    queue.push(start);
    cout << "Вершина: " << start->name << " Номер обходу (BFS): " << start->dfsNumber << endl;
    while (!queue.empty())
    {
        bool neighboursVisited = true;
        for (int i = 0; i < queue.front()->neighbours.size(); i++)
        {
            Vertex *current = queue.front()->neighbours[i];
            if (current->visited == false)
            {
                carcass.push_back({queue.front()->name, current->name});
                current->visited = true;
                current->dfsNumber = ++BFSnum;
                queue.push(current);
                neighboursVisited = false;
                cout << "Вершина: " << current->name << " Номер обходу (BFS): " << current->dfsNumber << endl;
                break;
            }
        }
        if (neighboursVisited)
        {
            queue.pop();
        }
    }
    cout << endl;
    printCarcass(carcass);
}
