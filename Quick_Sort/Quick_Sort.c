#include <bits/stdc++.h>
using namespace std;
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
    int n,i;
    scanf("%d",&n);
    int arr[100];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    quickSort(arr, 0, n-1);
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
    return 0;
}
// sample input : 
// 2
// 5
// 1 5 8 32 46
// 10
// 3 3 4 23 356 12 523 43 67 864

// sample output :
// 1 5 8 32 46 
// 3 3 4 12 23 43 67 356 523 864 
