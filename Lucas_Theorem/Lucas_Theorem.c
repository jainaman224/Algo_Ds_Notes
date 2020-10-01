// Lucas's theorem expresses the remainder of division of the binomial coefficient nCr
// by a prime number p in terms of the base p expansions of the integers m and n.

# include <stdio.h>
# include <string.h>   
# include <stdlib.h>
# define MIN(a,b) (((a)<(b))?(a):(b))

int nCrModpDP (int n, int r, int p) ;
int nCrModpLucas (int n, int r, int p) ;
  
int main() 
{ 
    int n , r , p ; 
    printf ( "Enter the value of n (in nCr) : " ) ;
    scanf ( "%d" , &n ) ;
    printf ( "Enter the value of r (in nCr) : " ) ;
    scanf ( "%d" , &r ) ;
    printf ( "Enter the value of p: " ) ;
    scanf ( "%d" , &p ) ;
    
    printf("Value of nCr mod %d is %d " , p , nCrModpLucas(n, r, p)); 
    return 0; 
}

int nCrModpDP (int n, int r, int p) 
{     
    int C[r+1]; 
    memset ( C, 0, sizeof(C) ); //memset() is used to fill a block of memory with a particular value.
  
    C[0] = 1; // Top row of Pascal Triangle 
  
    // One by constructs remaining rows of Pascal Triangle  
    for (int i = 1; i <= n; i++) 
    { 
        
        for (int j = MIN(i,r); j > 0; j--)   
            // nCj = (n-1)Cj + (n-1)C(j-1); 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
}   

int nCrModpLucas(int n, int r, int p) 
{ 
   
   if (r==0) 
       return 1;    
   int ni = n % p, ri = r % p;    
   return (nCrModpLucas(n/p, r/p, p) * nCrModpDP(ni, ri, p)) % p; // Last digits of n ,r and Remaining digits 
} 

/*Enter the value of n (in nCr) : 10
Enter the value of r (in nCr) : 2
Enter the value of p: 13
Value of nCr mod 13 is 6*/
