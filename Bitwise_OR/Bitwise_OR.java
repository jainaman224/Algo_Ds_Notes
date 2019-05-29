import java.util.*;
class Bitwise_OR
{  
    // Function to find bitwise OR
    static void OR(int array[], int num) 
    { 
        int ans = array[0]; 
        for (int i = 0; i < num; i++) 
            ans |= array[i]; 
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
        OR(array, num); 
    } 
}

/*
Input: 
num = 3
array[] = {4, 5, 6}
Output:
7
Because 4 = 100, 5 = 101, 6 = 110 in binary .
OR of 4 and 5 is 101(5) in binary and
OR of 5(resultant of 4 and 5) and 6 is 111(7).
so, answer is 7.
*/
