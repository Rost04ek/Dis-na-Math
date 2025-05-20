#pragma once
#include <vector>
#include <string>

const int INF = 1000000000;

void dijkstra(const std::vector<std::vector<int>>& adj, int start, std::vector<int>& dist, std::vector<int>& prev);
std::string getPath(int start, int end, const std::vector<int>& prev);