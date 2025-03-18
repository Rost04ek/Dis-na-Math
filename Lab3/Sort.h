#pragma once
#include <vector>

typedef std::vector<int> datatype;

void SortBubble(datatype& array, int start, int end);
void Swap(datatype& array, int i, int j);
int MinItem(datatype& array, int start, int end, int min);
void PrintArray(datatype& array); 