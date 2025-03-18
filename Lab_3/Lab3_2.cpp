#include <iostream>
#include "Comp.h"
#include "Sort.h"

using namespace std;
int main()
{
    while (true)
    {
        int len;
        cout << "\nEnter the length of the permutation: ";
        cin >> len;
        if (len < 2)
        {
            cout << "Invalid input (too short)\n";
            continue;
        }
        if (len > 10)
        {
            cout << "Invalid input (too long)\n";
            continue;
        }
        datatype array(len);
        for (int i = 0; i < len; i++)
        {
            cout << "Element " << i << ": ";
            cin >> array[i];
        }
        PrintArray(array);
        bool hasNext = true;
        while (hasNext)
        {
            GenPerm(array, array.size());
            for (int i = 1; i < array.size(); i++)
            {
                if (array[i - 1] < array[i])
                {
                    hasNext = true;
                    break;
                }
                hasNext = false;
            }
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
