import java.util.*;
public class Main
{   
    public static void mergeSort3Way(int[] arr)
    {
        if(arr == null)
        {
            return;
        }
        int[] duplicateArr = new int[arr.length];
        for(int i=0;i<duplicateArr.length;i++)
        {
            duplicateArr[i] = arr[i];
        }
        mergeSort3wayHelper(duplicateArr,0,arr.length,arr);
        for(int i=0;i<duplicateArr.length;i++)
        {
            arr[i] = duplicateArr[i];
        }

    }

    public static void mergeSort3wayHelper( int[] arr, int start, int end , int[] finalArray)
    {
         if(end-start<2)
         {
             return;
         }

         int mid1 = start + (end-start)/3;
         int mid2 = start + 2* ((end-start)/3)+1;
         mergeSort3wayHelper(finalArray, start, mid1, arr);
         mergeSort3wayHelper(finalArray, mid1, mid2, arr);
         mergeSort3wayHelper(finalArray, mid2, end, arr);

        mergeSort(finalArray, start, mid1, mid2, end, arr);

    }
    
    public static void mergeSort(int[] arr, int start, int mid1, int mid2, int end, int[] finalArray)
    {
        int i=start;
        int j=mid1;
        int k=mid2;
        int l=start;
        while(i<mid1 && j<mid2 && k<end)
        {
             if(arr[i] < arr[j])
             {
                  if(arr[i] < arr[k])
                  {
                      finalArray[l++] = arr[i++];
                  }
                  else
                  {
                      finalArray[l++] = arr[k++];
                  }
             }
             else{
                 if(arr[j] < arr[k])
                 {
                      finalArray[l++] = arr[j++];
                 }
                 else
                 {
                      finalArray[l++] = arr[k++];
                 }
             }
        }

        while(i<mid1 && j<mid2)
        {
            if(arr[i] < arr[j])
            {
                finalArray[l++] = arr[i++];
            }
            else
            {
                finalArray[l++] = arr[j++];
            }
        }

        while( j < mid2 && k < end)
        {
            if(arr[j] < arr[k])
                 {
                      finalArray[l++] = arr[j++];
                 }
                 else
                 {
                      finalArray[l++] = arr[k++];
                 }
        }

        while( i < mid1 && k < end)
        {
            if(arr[i] < arr[k])
                 {
                      finalArray[l++] = arr[i++];
                 }
                 else
                 {
                      finalArray[l++] = arr[k++];
                 }
        }

        while(i<mid1)
        {
            finalArray[l++] = arr[i++];

        }
        
        while(j<mid2)
        {
            finalArray[l++] = arr[j++];
        }

        while(k<end)
        {
            finalArray[l++] = arr[k++];
        }
    }

    public static void main(String[] args) {
        
        Scanner s = new Scanner(System.in);
        System.out.println("Enter number of elements of array");
        int n = s.nextInt();
        int[] val = new int[n];
        System.out.println("Enter array");
        for(int i=0;i<n;i++)
        {
            val[i] = s.nextInt();
        }
        mergeSort3Way(val);

         System.out.println("After 3-Way merge sort:");
         for(int i=0;i<n;i++)
        {
            System.out.println(val[i] + " ");
        }
    }
}
