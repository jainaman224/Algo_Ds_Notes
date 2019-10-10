import java.util.Scanner;

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
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the size of the array");
        int size = input.nextInt();
        int[] array = new int[size];
        System.out.println("Enter elements of the array");
        for (int i = 0; i < size; i++){
            array[i] = input.nextInt();
        }
        BubbleSort(array, size);
        Print_Array(array, size);
    }
}

// Input
// 8 4 6 2 3 4 1

// Output
// 1 2 3 4 4 6 8
