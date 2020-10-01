// Chocolate Distribution problem 
#include <stdio.h>

void merge_array(int a[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    //array creation
    int L[n1], R[n2]; 
  
    //Copy data to temp arrays L[] and R[] 
    for (i = 0; i < n1; i++) 
        L[i] = a[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = a[m + 1 + j]; 
  
    //Merge the temp arrays back into arr[l..r]
    i = 0; 
    j = 0;  
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            a[k] = L[i]; 
            i++; 
        } 
        else
        { 
            a[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    //Copy the remaining elements of L[], if there are any 
    while (i < n1) 
    { 
        a[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    //Copy the remaining elements of R[], if there  are any 
    while (j < n2) 
    { 
        a[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
//l is for left index and r is right index of the sub-array of arr to be sorted 
void merge_sort(int a[], int left, int right) 
{ 
    if (left < right) 
    { 
        //Same as (l+r)/2, but avoids overflow for large l and h
        int m = left + (right-left) / 2; 
        
        // Sort first and second halves 
        merge_sort(a, left, m); 
        merge_sort(a, m+1, right); 
        merge_array(a, left, m, right); 
    } 
} 
  
int min_diff(int a[], int num_packets, int num_children)
{
    int i, j, diff = 0, required_diff, first = 0, last = 0;
    if(num_children == 0 || num_packets == 0)
        return 0;
    if(num_children > num_packets)
        return -1;
    merge_sort(a, 0, num_packets);
    required_diff = a[num_packets - 1] + 1;
    merge_sort(a, 0, num_packets);

    for(i = 0; i + num_children - 1 < num_packets; i++)
    {
        diff = a[i + num_children - 1] - a[i];
        if(diff < required_diff)
        {
            required_diff = diff;
            first = i;
            last = i + num_children - 1;
        }
    }
    return required_diff;
}

int main()
{
    int num_packets, num_children, i, j, k;
    scanf("%d", &num_children);  //size of group in which chocolates  needs to be distributed
    scanf("%d", &num_packets);  //size of array
    int a[num_packets];
    for (i = 0; i < num_packets; i++)
        scanf("%d", &a[i]);  //taking input for the quantity of chocolate contained in each packet
    if (min_diff(a, num_packets, num_children) >= 0)
         printf("The minimum difference of chocolates distributed between children who got maximum and minimum is %d",min_diff(a, num_packets, num_children));
    else
         printf("As the number of students is less than number of packets hence no minimum difference is valid or is -1");
    return 0;
}

//input:
//5
//8
//3 4 1 9 56 7 9 12
//output:
//The minimum difference of chocolates distributed between children who got maximum and minimum is 6


