// A Dynamic programming solution for Rod Cutting problem 

import java.util.*;
import java.lang.*;
import java.io.*;

class RodCutting
{   //a fxn for calculating max of two nos.
	static int max(int a,int b)
     { 
     	 return(a > b) ? a : b ;
     	 
     }
     
     // returns the max obtainable cost
     static int CutRod(int cost[],int n)
     {  int []val=new int[n+1];
          int i,j;
         val[0]=0;
         
         for(i=1;i<=n;i++)
            { int max_value=Integer.MIN_VALUE;
              for(j=0;j<i;j++)
                max_value=max(max_value,cost[j]+val[i-j-1]);
              val[i]=max_value;
            }
         
         return val[n];
     }
     
     // driver fxn
     
     public static void main(String args[])
     { int []arr=new int [] {3,5,8,9,10,17,17,20};
       int size=arr.length;
       System.out.println("Maximum value is " + CutRod(arr,size));
     }
}   


/*OUTPUT
Maximum value is 24 */




  
