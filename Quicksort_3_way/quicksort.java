import java.util.*;
class quicksort.java{
public static int sorting(int high,int low,int [] arr){
     int i=0;int j=0;
    while(j<=high){
     if(arr[j]<=high){
         int temp=arr[i];
         arr[i]=arr[j];
         arr[j]=temp;
         i++;j++;
     }
     else{
         j++;
     }
     }
     return i-1;
}
public static void quicksort(int low,int high,int [] arr){
    
    if(low>=high){
        return;
    }
    int pivot=sorting(0,arr.length-1,arr);
     quicksort(low,pivot-1,arr);
     quicksort(pivot+1,high,arr);

}
public static void main(String[] args){
int[] arr={3,10,12,9,5,12,13,6,2,15,20,10};//iput can be taken using loop
quicksort(0,arr.length-1,arr);
//array after sorting//
for(int i=0;i<=arr.length-1;i++){
    System.out.print(arr[i]+" ");
}
}
}