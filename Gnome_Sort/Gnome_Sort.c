#include <stdio.h> 
 
  
// A function which is used to sort the algorithm using gnome sort 
void gnome_sort(int arr[], int n) 
{   
    // 
        int index = 0; 
  
        while (index < n){

        if (index == 0 || arr[index - 1] <= arr[index]){
            index++;
        }  
        else{
            int temp = arr[index-1];
            arr[index - 1] = arr[index];
            arr[index] = temp;
            index = index - 1;

        }

    }
   
} 
  
  
// Sample Test cases to test above function. 
int main() 
{ 
    int arr[] = {3, 2, 1, -5, 7}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    gnome_sort(arr, n); 

    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
  
    return 0; 
} 