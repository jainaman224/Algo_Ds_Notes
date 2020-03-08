using System;

class AKS {
    public static void main(String[] args){
    
        //Prints all the primes less than 100000000
        
        for(int i = 0; i < 1000000; i++)
        {
            if(isprm(i))
            {
                Console.Write(i);
            }
        }
    }
    
    
    
/*
Check if n is a perfect power: if n = ab for integers a > 1 and b > 1, output composite.
Find the smallest r such that ordr(n) > (log2 n)2. (if r and n are not coprime, then skip this r)
For all 2 ≤ a ≤ min(r, n−1), check that a does not divide n: If a|n for some 2 ≤ a ≤ min(r, n−1), output composite.
If n ≤ r, output prime.
For a = 2 to sqrt(phi (r))*log(2)(n)  
    if (X+a)n≠ Xn+a (mod Xr − 1,n), output composite;
Output prime.
*/

    
    public  static boolean isprm(long n)
    {   
        long i,w=2;
        i=Console.WriteLine();
        if(n==2 || n==3)
        return true;
        if(n%2 ==0 ||n%3==0||n==1)
            return false;
            while(i*i<=n)
            {
                if(n%1==0)
                    return false;
                i +=w;
                w=6-w;
                    
            }
            return true;
    }
}


/*
Input 
37
Output
Prime
*/
