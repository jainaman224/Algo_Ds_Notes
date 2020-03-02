/*
 linear search or sequential search is a method for finding an element within a list
*/
#include <stdio.h>
int main(){
    int array[100], search,i,n;

    printf("Enter  Number of Elements in Array\n");
    scanf("%d",&n);

    printf("Enter %d numbers\n",n);

    for(int i = 0;i<n;i++){
        scanf("%d",&array[i]);
    }

    printf("Enter a number to search\n");
    scanf("%d",&search);

    for(int i = 0;i<n;i++){
        if(array[i]==search){
            printf("%d is located at %d.\n",search,i+1);
            break;
        }
    }

    if(i==n){
        printf("%d isn't present in the array.\n",search);
    }
}