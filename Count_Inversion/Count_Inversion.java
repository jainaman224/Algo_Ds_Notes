public class Count_Inversion {
    public static void main(String[] args) {
        int arr[] = {2, 1, 3, 1, 2};
        System.out.println(countInversions(arr, 0, arr.length-1));
    }

    public static long countInversions(int[] arr, int low, int high){
        if(arr.length<2){
            return 0;
        }
        if(low<high){
            int mid = (low+high)/2;
            return countInversions(arr,low,mid)+countInversions(arr,mid+1,high) +
                    merge(arr,low,mid,high);
        }
        return 0;
    }


    public static long merge(int[] arr, int low, int mid, int high){
        int count = 0;
        int n1 = mid-low+1;
        int n2 = high-mid;

        int i = 0;
        int j = 0;
        int k = low;

        int left[] = new int[n1];
        int right[] = new int[n2];

        for(int m=0; m<n1; m++){
            left[m] = arr[m+low];
        }

        for(int m=0; m<n2; m++){
            right[m] = arr[m+mid+1];
        }

        while (i<n1 && j<n2){
            if(left[i]<=right[j]){
                arr[k]=left[i];
                i++;
            }
            else{
                arr[k]=right[j];
                count+=n1-i;
                j++;
            }
         k++;
        }

        while (i<n1){
            arr[k]=left[i];
            i++;
            k++;
        }

        while (j<n2){
            arr[k]=right[j];
            j++;
            k++;
        }
        return count;
    }
}
