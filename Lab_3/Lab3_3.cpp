#include <iostream>
#include <vector>
#include "Comp.h"
#include "Sort.h"

using namespace std;
int main()
{
    while (true)
    {
        int n;
        int k;
        cout << "\nEnter set length: ";
        cin >> n;
        if (n < 2)
        {
            cout << "Invalid input";
            continue;
        }
        datatype array(n);
        for (int i = 0; i < n; i++)
        {
            cout << "Enter element " << i << ": ";
            cin >> array[i];
        }
        SortBubble(array, 0, n);
        cout << "\nEnter combination length: ";
        cin >> k;
        if (k < 2 || k > n)
        {
            cout << "Invalid input.";
            continue;
        }
        datatype comb(k);
        for (int i = 0; i < k; i++)
        {
            cout << "Enter element " << i << ": ";
            cin >> comb[i];
        }
        SortBubble(comb, 0, k);
        for (int i = 1; i < C(k, n); i++)
        {
            GenComb(array, comb);
        }
        string userAnswer;
        cout << "\nWould you like to continue? (y/n): ";
        cin >> userAnswer;
        if (userAnswer != "y")
        {
            break;
        }
    }
}