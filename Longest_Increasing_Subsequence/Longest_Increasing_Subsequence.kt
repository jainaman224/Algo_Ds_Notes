//Kotlin code for Longest increasing subsequence

class LIS
{
    fun lis(int:arr[], int:n):int
    {
        int lis[] = new int[n];
        int result = Integer.MIN_VALUE;

        for (i in 0 until n)
        {
            lis[i] = 1;
        }
            
        for (i in 1 until n)
        {
            for (j in 0 until i)
            {
                if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                {
                    lis[i] = lis[j] + 1;
                }
            }
            result = Math.max(result, lis[i]);
        }
        return result;
    }

    fun main()
    {
        var read = Scanner(System.`in`)
        println("Enter the size of the Array:")
        val arrSize = read.nextLine().toInt()
        var arr = IntArray(arrSize)
        println("Enter elements")

        for(i in 0 until arrSize)
        {
            arr[i] = read.nextLine().toInt()
        }
        
        int n = arrSize;
        println("\nLength of the Longest Increasing Subsequence:" + lis(arr, n))
   }
}

/*
Enter the size of the array : 8
Enter elements : 15 26 13 38 26 52 43 62
Length of the Longest Increasing Subsequence : 5
*/

