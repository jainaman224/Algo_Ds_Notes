import java.util.Scanner;

class Selection_Sort
{
    // function for selection sort
    public static void SelectionSort(int[] array, int size)
    {
        int min_index, temp;

        for(int i = 0; i < size - 1; i++)
        {
            min_index = i;

            for(int j = i + 1; j < size; j++)
                if(array[j] < array[min_index])
                    min_index = j;

            temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
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
        Scanner s = new Scanner(System.in);
        int num;
        num = s.nextInt();
        int array[] = new int[num];
        for(int i = 0; i < num; i++) {
            array[i] = s.nextInt();
        }
        SelectionSort(array, num);
        Print_Array(array, num);
    }
}

// Output
// 1 2 3 4 4 6 8
