#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

int prefixsum[MAX];//array to store prefixsums

/*function that calculates prefix sum by 
forming the prefixsum array
*/
void calculate_prefix_sum (int arr[], int n)
{
    prefixsum[0] = arr[0]; //starts with the first element
    for (int i = 1; i < n; i++)
    {
	/*calculates prefixsum by adding the new element 
	with the previous element in the prefixsum array
	*/
        prefixsum[i] = prefixsum[i-1] + arr[i];
    }
}

//main function
int main()
{
    int arr[] = { 1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    calculate_prefix_sum(arr, n);
    for (int i = 0; i < n; i++)
	printf ("%d ",prefixsum[i]);
    printf("\n");
}
/* OUTPUT
1 3 6 10 15 */
