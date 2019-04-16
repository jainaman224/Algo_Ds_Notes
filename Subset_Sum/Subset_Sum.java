/* 
    Subset Sum Problem: Given an array of elements and a sum,
    is it possible to form the given sum using some or all of the
    elements of array i.e using any subset of given array. 
    Example: 1, 7, 3, 5, 6 and sum = 14, it is possible to obtain
    the sum 14 by taking the elements 1, 7 and 6 
*/

class Subset_Sum
{
    // Function to compute whether a subset of array
    // exists having the given sum
    public static boolean subsetSum(int arr[], int size, int sum)
    {

        // A 2D Matrix containing boolean values, true and false
        boolean[][] dp = new boolean[size + 1][sum + 1];

        /* Any entry of dp matrix dp[i][j] tells us that taking 
        the elements 1....i can we make the sum j, this is optimal
        substructure of this Dynamic Programming Problem. At every
        step, we have the option of either including the element in
        the subset to form the given sum, or we exclude it and keep
        the previous set chosen in our answer */
        for(int i = 0; i <= size; i++)
        {
            for(int j = 0; j <= sum; j++)
            {
                // We cannot form a sum j by taking no elements
                if (i == 0)
                    dp[0][j] = false;

                // We can always form the sum 0, 
                // by taking 0 instance of the element
                if (j == 0)
                    dp[i][0] = true;
                
                if (i > 0)
                {
                    /* when the value of current element is less than the
                    sum j, we have two options, either take it and include
                    the element in answer or leave it and take the previous
                    best given by dp[i-1][j] */
                    if (arr[i - 1] <= j)
                        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                    else
                        /* when the value of sum j is less than the element i,
                        we cannot include this element and hence take the
			previous best*/
                        dp[i][j] = dp[i - 1][j];
                }
            }
        }

        /* The last entry in table gives the answer by
        evaluating all the elements of array to compute
        the required sum */
        return dp[size][sum];
    }

    // Driver function
    public static void main(String args[])
    {
        int arr[] = { 2, 3, 5, 1, 6, 8, 7 };
        int size = arr.length;
        int sum = 12;

        // Call to SubsetSum function
        Subset_Sum obj = new Subset_Sum();
        boolean ans = subsetSum(arr, size, sum);

        // if ans evaluates to false, no such subset present
        // if ans evaluates to true , subset with given sum present
        if ( !ans )
            System.out.println( "No subset adds upto the given sum" );
        else
            System.out.println( "Subset with given sum present" );
    }
}

/* 
    Input:
    arr = { 2, 3, 5, 1, 6, 8, 7 }
    sum = 12

    Output:
    Subset with given sum present
*/
