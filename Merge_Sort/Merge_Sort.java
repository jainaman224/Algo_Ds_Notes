class Merge_Sort
{
    public static int temp[];

    // Conquer
    public static void conquer_merge(int[] array, int left, int right, int mid)
    {
        int k = left, i, j;

        for(i = left, j = mid + 1; i <= mid && j <= right; k++)
        {
            if(array[i] <= array[j])
            {
                temp[k] = array[i];
                i++;
            }
            else
            {
                temp[k] = array[j];
                j++;
            }
        }

        while(i <= mid)
        {
            temp[k] = array[i];
            i++;
            k++;
        }

        while(j <= right)
        {
            temp[k] = array[j];
            j++;
            k++;
        }

        for(i = left; i <= right; i++)
            array[i] = temp[i];
    }

    // Divide array into halves
    public static void divide(int[] array, int left, int right)
    {
        if(left < right)
        {
            int mid = left + (right - left) / 2;

            divide(array, left, mid);
            divide(array, mid + 1, right);

            conquer_merge(array, left, right, mid);
        }
    }

    public static void MergeSort(int array[], int size)
    {
        temp = new int[size];
        divide(array, 0, size - 1);
        temp = null;
    }

    // function ro print array
    public static void Print_Array(int[] array, int size)
    {
        for(int i = 0; i < size; i++)
            System.out.print(array[i] + " ");

        System.out.println();
    }

    public static void main(String[] args)
    {
        int[] array = {2, 4, 3, 1, 6, 8, 4};
        MergeSort(array, 7);
        Print_Array(array, 7);
    }
}

// Output
// 1 2 3 4 4 6 8
