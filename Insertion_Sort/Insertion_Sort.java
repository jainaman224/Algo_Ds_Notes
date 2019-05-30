import java.util.Scanner;

class Insertion_Sort
{
    // function for insertion sort
    public static void InsertionSort(int[] array, int size)
    {
        int temp, j;

        for(int i = 1; i < size; i++)
        {
            temp = array[i];
            j = i - 1;

            // Do swapping
            while(j >= 0 && array[j] > temp)
            {
                array[j + 1] = array[j];
                j--;
            }

            array[j + 1] = temp;
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
        int num;
        Scanner s = new Scanner(System.in);
        num = s.nextInt();
        int array[] = new int[num];
        for (int i = 0; i < num; i++) {
            array[i] = s.nextInt();
        }
        InsertionSort(array, num);
        Print_Array(array, num);
    }
}

/*
Input :
num = 6
array = [1, 6, 3, 3, 5, 2]

Output :
[1, 2, 3, 3, 5, 6]
*/
