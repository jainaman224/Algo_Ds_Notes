/*Problem Statement
 * Given an array of elements count the frequency of every element in the array.
 */

import java.util.HashMap;
import java.util.Scanner;

public class CountFrequencyOfArrayElements 
{

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        
        // input size of array
        int n = sc.nextInt();
        // input array
        int a[] = new int[n];
        for(int i = 0; i < n; i++)
            a[i] = sc.nextInt();

        countFreq(a, n);
        
        sc.close();
    }

    // function to count frequency 
    private static void countFreq(int[] a, int n) {
       // using hashmap to store the freq
        HashMap<Integer, Integer> hm = new HashMap<>(); 
        for(int i = 0; i < n; i++)
        {
            if( hm.containsKey(a[i]) )
                hm.put( a[i], hm.get(a[i]) + 1);
            else
                hm.put(a[i], 1);
        }

        //display the frequencies	
        System.out.println("Element \t Frequency");
        hm.forEach(
            (k,v) ->
            {
                System.out.println(k + " \t\t " + v);
            }
        );
    }

}

/*
 * Input : 
5
2 1 1 6 1
  
 * Output :
Element 	 Frequency
1 		 3
2 		 1
6 		 1
  
 * */
