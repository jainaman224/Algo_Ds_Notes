import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static int unboundedKnapsack(int Capacity,int n, int weight[],int value[]){
        int[] maxProfit = new int[Capacity+1];
        for(int i=0;i<=Capacity;i++){
            maxProfit[i]=0;
        }
        for(int i=0;i<=Capacity;i++){
            for(int j=0;j<n;j++){
                if(weight[j]<=i){
                    maxProfit[i]=Math.max(maxProfit[i],maxProfit[i-weight[j]]+value[j]);
                }
            }
        }
        return maxProfit[Capacity];
    }


   public static void main(String[] args) {
       // No. of items
       int n = 4;
       // Values(Profits) of items
       int value[] = {40,30,50,25};
       // Weight of items
       int weight[] = {5,10,8,15};
       // Knapsack capacity
       int Capacity = 120;
       System.out.println("Maximum value that can be achieved is: "+unboundedKnapsack(Capacity,n,weight,value));
   }
}
