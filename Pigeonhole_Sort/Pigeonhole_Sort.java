import java.util.Scanner;

class Pigeonhole_Sort {
    // Method for getting the maximum value
    public static int getMax(int[] inputArray) {
        int maxValue = inputArray[0];
        for (int i = 1; i < inputArray.length; i++) {
            if (inputArray[i] > maxValue) {
                maxValue = inputArray[i];
            }
        }
        return maxValue;
    }

    // Method for getting the minimum value
    public static int getMin(int[] inputArray) {
        int minValue = inputArray[0];
        for (int i = 1; i < inputArray.length; i++) {
            if (inputArray[i] < minValue) {
                minValue = inputArray[i];
            }
        }
        return minValue;
    }

    public static void sort(int[] input) {
        //calculate size for array( no of pigeon holes)
        int max_no = getMax(input);
        int min_no = getMin(input);
        int size = max_no - min_no + 1;

        //create holes
        int[] holes = new int[size];
        for (int i = 0; i < input.length; i++)
            holes[input[i] - min_no]++;

        int index = 0;

        for (int j = 0; j < size; j++)
            while (holes[j]-- > 0)
                input[index++] = j + min_no;
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter size of array");
        int n = sc.nextInt();  
        int[] array = new int[n];
        System.out.println("Enter elements of array");
        for(int i = 0; i < n; i++)
            array[i] = sc.nextInt();
        sort(array);
        for(int i = 0; i < n; i++)
             System.out.println(array[i] + " ");
    }
}

/*
Input:
n = 4
array = [1, 4, 32, 2]

Output 
array = [1, 2, 4, 32]
*/
