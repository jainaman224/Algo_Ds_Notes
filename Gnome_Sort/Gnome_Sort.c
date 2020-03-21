#include <stdio.h> 
  
// A function which is used to sort the algorithm using gnome sort 
void gnome_sort(int arr[], int n) {   

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
  
// Main function. 
int main() 
{ 
    int n;
    printf("Enter the size of an Array: ");
    scanf("%d", &n);
    int arr[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    gnome_sort(arr, n); 

    for(int i = 0; i < n; i++){
        printf("%d\n", arr[i]);
    }
  
    return 0; 
} 

/*
    Sample Driver Code:
    INPUT: 
    Enter the size of an Array: 5
    3
    2
    1
    -5
    7

    OUTPUT:
    -5
    1
    2
    3
    7

*/
