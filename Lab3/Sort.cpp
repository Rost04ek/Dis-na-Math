#include "Sort.h"
#include <iostream>

void SortBubble(datatype& array, int start, int end) {
    for (int i = start; i < end - 1; i++) {
        for (int j = start; j < end - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                Swap(array, j, j + 1);
            }
        }
    }
}

void Swap(datatype& array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int MinItem(datatype& array, int start, int end, int min) {
    int minIndex = start;
    for (int i = start; i < end; i++) {
        if (array[i] > min && array[i] < array[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

void PrintArray(datatype& array) {
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
} 