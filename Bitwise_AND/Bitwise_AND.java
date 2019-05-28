import java.util.*;
class Bitwise_AND
{  
    // Function to find bitwise AND
    static void AND(int array[], int num) 
    { 
        int ans = array[0]; 
        for (int i = 0; i < num; i++) 
            ans &= array[i]; 
        System.out.println(ans); 
    } 

    // Driver code 
    public static void main(String[] args) 
    { 
        Scanner sc = new Scanner(System.in); 
        int num = sc.nextInt();
        int array[] = new int[num]; 
        for (int i = 0; i < num; i++)
            array[i] = sc.nextInt();
        AND(array, num); 
    } 
} 

/*
Input: 
num = 3
array[] = {4, 5, 6}
Output:
4
Because 4 = 100, 5 = 101, 6 = 110 in binary .
AND of 4 and 5 is 100(4) in binary and
AND of 4(resultant of 4 and 5) and 6 is 100(4).
so, answer is 4.
*/
