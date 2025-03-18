#include <vector>
#include <iostream>
#include "Comp.h"
#include "Sort.h"

typedef std::vector<int> datatype;

int Factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * Factorial(n - 1);
    }
}

int A(int k, int n)
{
    return Factorial(n) / Factorial(n - k);
}

int C(int k, int n)
{
    return Factorial(n) / (Factorial(k) * Factorial(n - k));
}

int _A(int k, int n)
{
    int result = 1;
    while (k > 0)
    {
        result *= n;
        k--;
    }
    return result;
}

int _C(int k, int n)
{
    return Factorial(n + k - 1) / (Factorial(k) * Factorial(n - 1));
}

void GenPerm(datatype &array, int len)
{
    for (int i = len - 1; i > 0; i--)
    {
        int j = i - 1;
        if (array[j] < array[i])
        {
            int min = MinItem(array, i, array.size(), array[j]);
            Swap(array, min, j);
            SortBubble(array, i, array.size());
            break;
        }
    }
    PrintArray(array);
}

void GenComb(datatype &array, datatype &comb)
{
    int n = array.size();
    int k = comb.size();
    for (int i = k - 1; i >= 0; i--)
    {
        if (comb[i] != array[n - k + i])
        {
            comb[i] = array[FindIndex(array, comb[i]) + 1];
            for (int j = i + 1; j < k; j++)
            {
                comb[j] = array[MinItem(array, 0, n, comb[j - 1])];
            }
            break;
        }
    }
    PrintArray(comb);
}

int FindIndex(datatype &array, int num)
{
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] == num)
        {
            return i;
        }
    }
    return -1;
}
