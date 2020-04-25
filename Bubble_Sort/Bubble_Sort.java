class Bubble_Sort
{
    // function for bubble sort
    public static void BubbleSort(int[] array, int size)
    {
        int temp;

        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (array[j] > array[j + 1])
                {
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }

    // function ro print array
    public static void Print_Array(int[] array, int size)
    {
        for (int i = 0; i < size; i++)
            System.out.print(array[i] + " ");

        System.out.println();
    }

    public static void main(String[] args)
    {
        int[] array = {2, 4, 3, 1, 6, 8, 4};
        BubbleSort(array, 7);
        Print_Array(array, 7);
    }
}

// Output
// 1 2 3 4 4 6 8
/*
Test Case 1:
Input: 1 7 99 2 0 12 15
Output: 0 1 2 7 12 15 99

Test Case 2:
Input: 8 5 3 1 9 6 0 7 4 2 5
Output: 0 1 2 3 4 5 5 6 7 8 9

Test Case 3:
Input: 10 9 8 7 6 5 4 3 2 1 0
Output: 0 1 2 3 4 5 6 7 8 9 10 */
