#pragma once
#include <vector>

typedef std::vector<int> datatype;
int Factorial(int num);
int A(int k, int n);
int C(int k, int n);
int _A(int k, int n);
int _C(int k, int n);
void GenPerm(datatype &array, int len);
void GenComb(datatype &array, datatype &comb);
int FindIndex(datatype &array, int num);