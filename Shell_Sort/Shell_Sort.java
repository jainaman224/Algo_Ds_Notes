/* Java implementation of Shell Sort*/

public class Shell_Sort
{
    public void sort(int input[]) // Function implementing Insertion Sort
    {
          int n = input.length, temp, j;
          for (int gap = n / 2; gap > 0; gap /= 2)
          {
              for (int i = gap; i < n; i++) // Gapped insertion sort
              {
                  temp = input[i];

                  for (j = i; j >= gap && input[j - gap] > temp; j = j - gap)
                      input[j] = input[j - gap];

                  input[j] = temp;
              }
          }
    }

    public static void main(String[] args)
    {
        int input[] = {5, 6, 8, 4, 6, 5, 3, 3, 2, 7, 8, 45, 85, 96}; //Input array

        shellSort ob = new shellSort();

        ob.sort(input);

        System.out.print("Output : ");

        for (int i = 0; i < input.length; ++i) // Printing Sorted array
            System.out.print(input[i] + " ");
    }

}

/*

Output : 2 3 3 4 5 5 6 6 7 8 8 45 85 96

*/
