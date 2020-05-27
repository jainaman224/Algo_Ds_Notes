// Kotlin Code for Pancake Sort

class PancakeSorting
{   
    // This functions reverses the array upto index n
    fun reverseArray ( int:a [] , int:n ):void
    {
        int temp[] = new int [n+1] ;   
        for (i in 0 until n)
        {
            temp[i] = a[n-i];
        }
        for (i in 0 until n)
        {
        	a[i] = temp[i];
        }
    }
    
     // Function to find index of max element upto index n
     fun findMax (int:a[] , int:n ):int
     {
         int max = a[0] ; int j = 0;
         for (i in 1 until n)
         {  
             if (a[i] > max)
             {
                 max = a[i];
                 j = i;
             }
         }
         return j; 
      }
    
    fun pancakeSort (int:a [] , int:n):void
    {  
        int currentLength;
        for (currentLength in n until 0)
        {
            int j = findmax (a , currentLength-1);
            if (j != currentLength)
            {
                reverseArray (a , j);
                reverseArray (a , currentLength-1);
            }
        }
     }
    
    fun main ()
    {
        var read = Scanner(System.`in`)
        int i , j , k , l , m , n; 
        val n = read.nextLine().toInt()
        int array [] = new int [n];
        for(i in 0 until n)
        {
       	    array[i] = read.nextLine().toInt()
        }
        pancakesort (array, n);
        for (i in 0 until n)
        {
            println( array[i] + " " );	
        }
    }
}

/* 
Input
5  4  3  2  1 
Output 
1 2 3 4 5 
*/
