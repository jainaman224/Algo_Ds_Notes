using System;

internal class BinaryIndexedTree 
{
    // Max tree size
    internal
    const int MAX = 1000;
    internal static int[] BITree = new int[MAX];

    internal virtual int getSum(int index) 
    {
        // Iniialize result
        int sum = 0;

        // index in BITree[] is 1 more than
        // the index in arr[]
        index = index + 1;

        // Traverse ancestors of BITree[index]
        while (index > 0) {
            sum += BITree[index];
            index -= index & (-index);
        }
        return sum;
    }

    // Updates a node in Binary Index Tree (BITree) at given index in BITree.  
    public static void updateBIT(int n, int index, int val) 
    {
        // index in BITree[] is 1 more than 
        // the index in arr[]
        index = index + 1;

        // Traverse all ancestors and add 'val'
        while (index <= n) 
        {
            BITree[index] += val;
            index += index & (-index);
        }
    }

    /* Function to construct fenwick tree 
     from given array.*/
    internal virtual void constructBITree(int[] arr, int n) 
    {
        // Initialize BITree[] as 0
        for (int i = 1; i <= n; i++) 
        {
            BITree[i] = 0;
        }

        // Store the actual values in BITree[]
        // using update()
        for (int i = 0; i < n; i++) 
        {
            updateBIT(n, i, arr[i]);
        }
    }

    // Main function
    public static void Main(string[] args) 
    {
        int[] freq = new int[] {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
        int n = freq.Length;
        BinaryIndexedTree tree = new BinaryIndexedTree();
        // Build fenwick tree from given array
        tree.constructBITree(freq, n);
        Console.WriteLine("Sum of elements in arr[0..5]" + " is = " + tree.getSum(5));
        freq[3] += 6;
        updateBIT(n, 3, 6);
        // Find sum after the value is updated
        Console.WriteLine("Sum of elements in arr[0..5]" + " after update is = " + tree.getSum(5));
    }
}

/*Output:-
Sum of elements in arr[0..5] is = 12
Sum of elements in arr[0..5] after update is = 18*/
