import java.util.*;

public class Sparse_Table {

    static int log(int x, int base){
        return (int) (Math.log(x) / Math.log(base));
    }

    public static void main(String[] args) {

        System.out.println("Enter number of elements:");
        Scanner sc = new Scanner(System.in);

        int n;
        n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter the elements:");
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }

        // Building Sparse Table
        int sparseTable[][] = new int[n][n];

        // Transferring value from array to sparse table
        for(int i=0; i < n; i++){
            sparseTable[i][0] = arr[i];
        }

        for(int j=1; (1 << j) <= n; j++){
            //compute minimum value for all intervals with size 2^j
            for(int i=0; (i + (1 << j) - 1) < n; i++){
                if(sparseTable[i][j-1] < sparseTable[i + (1 << (j-1))][j-1]){
                    sparseTable[i][j] = sparseTable[i][j-1];
                }
                else{
                    sparseTable[i][j] = sparseTable[i + (1 << (j-1))][j-1];
                }
            }
        }

        // Range Min Query
        //To find min between L (query start) to R (query end) where 0 <= L <= R <= n-1
        System.out.print("Enter the query start: ");

        int L,R;
        L = sc.nextInt();
        System.out.print("Enter the query end: ");
        R = sc.nextInt();

        int j = log(R - L + 1, 2);

        System.out.print("The element is: ");
        if(sparseTable[L][j] <= sparseTable[R - (1 << j) + 1][j])
            System.out.println(sparseTable[L][j]);
        else
            System.out.println(sparseTable[R - (1 << j) + 1][j]);

    }
}

/*
Sample Input:
    Enter the number of elements:
    9
    Enter the elements:
    1
    2
    3
    4
    5
    6
    7
    8
    9
    Enter the query start: 2
    Enter the query end: 7

Sample Output:
    The element is: 3

*/
