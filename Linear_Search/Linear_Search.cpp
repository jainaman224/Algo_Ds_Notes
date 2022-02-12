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


/* The following is a Better Linear Search(Sentinel Linear Search) Algorithm which only performs
    just one test in each loop iteration thereby reducing time complexity
*/
int BetterLinearSearch(int array[], int size, int desired) {
    int last = array[size-1];
    array[size-1] = desired;
    int i=0;
	while(array[i] != desired)
        i++;
    array[size-1] = last;
    if(i < size-1 || array[size-1] == desired)
        return i;
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
	cout << "Linear Search: ";
    if(linearSearch(arr, num, desired) != -1)
        cout << "Found" << endl;
    else
        cout << "Number not found" << endl;

    cout << "Better Linear Search: ";
    if(BetterLinearSearch(arr, num, desired) != -1) // Sentinel Linear Search
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


