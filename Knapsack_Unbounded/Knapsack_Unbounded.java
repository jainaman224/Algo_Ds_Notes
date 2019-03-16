import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static int unboundedKnapsack(int W,int n, int wt[],int val[]){
        int[] dp = new int[W+1];
        for(int i=0;i<=W;i++){
            dp[i]=0;
        }
        for(int i=0;i<=W;i++){
            for(int j=0;j<n;j++){
                if(wt[j]<=i){
                    dp[i]=Math.max(dp[i],dp[i-wt[j]]+val[j]);
                }
            }
        }
        return dp[W];
    }


   public static void main(String[] args) {
       // No. of items
       int n = 4;
       // Values(Profits) of items
       int val[] = {40,30,50,25};
       // Weight of items
       int wt[] = {5,10,8,15};
       // Knapsack capacity
       int W = 120;
       System.out.println("Maximum value that can be achieved is: "+unboundedKnapsack(W,n,wt,val));
   }
}
