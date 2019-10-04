#include <iostream>

using namespace std;

// Function for linear search
int linearSearch(int array[], int size, int desired)
{
    for(int i = 0; i < size; i++)
    {
        // return position if element is found
        if(array[i] == desired)
            return i;
    }

    return -1;
}

// Driver Function
int main()
{
    int num;
    cin >> num;
	int arr[num];
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	int desired;
	cin >> desired;
    if(linearSearch(array, num, desired) != -1)
        cout << "Found" << endl;
    else
        cout << "Number not found" << endl;
    return 0;
}

/*
Input :
num = 5
arr = [1,4,5,6,3]
desired = 3

Output :
Number not found
*/
