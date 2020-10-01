import java.util.Scanner;

class Linear_Search
{
    // Function for linear search
    public static int linearSearch(int[] array, int size, int desired)
    {
        for(int i = 0; i < size; i++)
        {
            // return position if element is found
            if(array[i] == desired)
                return i;
        }

        return -1;
    }

    // Driver Function
    public static void main(String[] args)
    {
        int num;
        Scanner s = new Scanner(System.in);
        num = s.nextInt();
        int array[] = new int[num];
        for (int i = 0; i < num; i++) {
            array[i] = s.nextInt();
        }
        int desired = s.nextInt();
        if(linearSearch(array, num, desired) != -1)
            System.out.println("Found");
        else
            System.out.println("Number not found");
    }
}

/*
Input :
num = 5
arr = [1,4,5,6,3]
desired = 3

Output :
Number not found
*/
