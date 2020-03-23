// C# program to print all primes  smaller than or equal to n  using Sieve of Eratosthenes 
using System; 
  
namespace prime 
{ 
    public class GFG 
    {      
                  
        public static void SieveOfEratosthenes(int n) 
        { 
              
        // Creating a boolean array "prime[0..n]" and initialize  all entries as true. A value in prime[i] will  finally be false if i is Not a prime, else condition holds true. 
  
        bool[] prime = new bool[n+1]; 
          
        for(int i = 0; i < n; i++) 
            prime[i] = true; 
          
        for(int p = 2; p*p <= n; p++) 
        { 
            // If prime[p] is not changed,  then it is a prime number
            if(prime[p] == true) 
            { 
                // Update all multiples of p 
                for(int i = p*p; i <= n; i += p) 
                    prime[i] = false; 
            } 
        } 
          
        // Print all prime numbers 
        for(int i = 2; i <= n; i++) 
        { 
            if(prime[i] == true) 
                Console.Write(i + " "); 
        } 
              
        } 
          
        // Driver Code 
        public static void Main() 
        { 
            
            int n = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("The prime numbers"); 
            Console.WriteLine("smaller than or equal to " + n); 
            SieveOfEratosthenes(n); 
              
        } 
    } 
} 




// input:
Input : n =15
Output : 2 3 5 7 11 13

Input : n = 20 
Output: 2 3 5 7 11 13 17 19
