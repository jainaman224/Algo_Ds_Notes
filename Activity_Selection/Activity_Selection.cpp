#include <iostream>

using namespace std;

void print_activities(int start[], int finish[], int n)
{
    cout << "Following activities are selected";
    int i = 0;
    cout << "\n" << i << "\t";
    for (int j = 1; j < n; j++)
    {
        if (start[j] >= finish[i])
        {
            cout << j << "\t";
            i = j;
        }
    }
}

int main()
{
    int start[] = {1, 3, 1, 5, 8, 6};
    int finish[] = {2, 6, 6, 7, 10, 8};
    int n = sizeof(start) / sizeof(start[0]);
    print_activities(start, finish, n);
    return 0;
}

// Output
// Following activities are selected
// 0	1	4
