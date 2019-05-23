import java.util.*;

public class SquareRootDecomposition {

    static void update (int index, int value, int blocks[], int input_arr[], int n) {
        blocks[(int)(index / Math.sqrt(n))] += value - input_arr[index];
        input_arr[index] = value;
    }

    // assuming 0 based indexing
    static int query (int low, int high, int blocks[], int input_arr[], int n) {
        int block_size = (int)Math.sqrt(n);
        int sum = 0;

        while (low % block_size != 0 && low < high) {
            sum += input_arr[low];
            low++;
        }
        while (low + block_size <= high) {
            sum += blocks[low / block_size];
            low += block_size;
        }
        while (low <= high) {
            sum += input_arr[low];
            low++;
        }

        return sum;

    }

    // divide the array in blocks of size sqrt(n), sum of elements in each block is stored in blocks
    static int[] formBlocks (int input_arr[], int n) {
        int block_size = (int)Math.sqrt(n);
        int index = -1;
        int blocks[] = new int[(int)(n / block_size) + 1];

        for (int i = 0; i < n; i++) {
            if ( i % block_size == 0){
                index++;
            }
            blocks[index] += input_arr[i];
        }

        return blocks;
    }

    /* Applying square root decomposition to perform range queries
    for finding the sum of numbers in a given range 
    Indexing : 0 based in array
    */
    public static void main (String args[]) {
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();
        int input_arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            input_arr[i] = sc.nextInt();
        }

        int blocks[] = formBlocks(input_arr,n);
        //queries
        //input queries with left and right indices to find the sum in that range
        System.out.println(query(0, 2, blocks, input_arr, n)); //find sum from index 0 to index 2
        
        System.out.println(query(3, 7, blocks, input_arr, n)); //find sum from index 3 to index 7
        
        System.out.println(query(1, 4, blocks, input_arr, n)); //find sum from index 1 to index 4
        
        //update
        update(3, 1, blocks, input_arr, n);  //update the value at index 3 with value of 1

        //query
        System.out.println(query(1, 4, blocks, input_arr, n));    //find sum from index 1 to index 4 
        
    }
}

/*
Input:
10
2 3 4 6 8 9 1 -1 0 3

Output:
9
23
21
16
*/
    