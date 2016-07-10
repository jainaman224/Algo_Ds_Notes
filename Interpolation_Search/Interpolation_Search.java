// Java Implementation of Interpolation Search

public class Interpolation_Search 
{
    public static int interpolation(int a[], int n, int search_item) // Function implementing Interpolation_Search
    {
        int high = n-1;
        int low = 0;
        int pos;

        while(low <= high && search_item >= a[low] && search_item <= a[high])
        {
            int rise = high - low;
            int run = a[high] - a[low];
            int x = search_item - a[low];
            pos = low + (rise / run) * x;

            if(a[pos] == search_item)
                return pos;
            else if(search_item < a[pos])
                high = pos - 1;
            else if(search_item > a[pos])
                low = pos + 1;
        }

        return -1;
  }

    // Driver Function
    public static void main(String[] args)
    {
        int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Sorted Input array
        int n = a.length; // Size of array
        int search_item = 8; // Element to be searched
        int index = interpolation(a, n, search_item);

        if(index == -1)
            System.out.println("Element not found");
        else
            System.out.println("Found at position " + (index + 1));
    }

}

/*

Output : Found at position 8

*/
