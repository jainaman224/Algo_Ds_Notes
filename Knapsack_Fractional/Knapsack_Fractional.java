/*
Fractional Knapsack problem is a variation of Knapsack problem where we can choose items by breaking them in fractions. The objective is to fill the knapsack with items to get maximum benefit without crossing the weight capacity of the knapsack.
*/
class Knapsack
{
    // Function to get index of next maximum ratio of value/ weight of items
    public static int getNext(double ratio[])
    {
        double max = 0;
        int index = -1;
        for (int i = 0; i < ratio.length; ++i)
        {
            if (ratio[i] > max) 
            {
                max = ratio[i];
                index = i;
            }
        } 
        return index;
    }
    // Function to compute maximum profit obtainable
    public static double fractionalKnapsackProblem(int wt[], int val[], double ratio[], int W)
    {
        /* variable weight to keep track of current weight added to Knapsack
        variable value to keep track of current value obtained from Knapsack
        variable remain to keep track of additional weight that can still be added to Knapsack*/
        double weight = 0.0; 
        double value = 0;
        double remain;
        while (weight <= W)
        {
            // call to function getNext to obtain next maximum ratio
            int item = getNext(ratio);
            // if current weight plus weight of the item to be added doesn't exceed Knapsack capacity select it
            if (weight + wt[item] <= W) 
            {
                weight += wt[item];
                value += val[item];
                //mark as used for the getNext() ratio function
                ratio[item] = 0;
            } 
            else 
            {
                /* if current weight plus weight of the item to be added exceeds Knapsack capacity, break the item into fractional part, and select the portion out of it which doesn't exceed the Knapsack capacity*/
                remain = (W - weight);
                value += (ratio[item] * remain);
                //the knapsack is full
                break; 
            }
        }
        // (12+ 5+ 15+ 20 + 30*(12-11)/10)
        return value;
    }

    // Driver function
    public static void main(String args[])
    {
        int wt[] = {6, 10, 3, 5, 1, 2};
        int val[] = {12, 30, 15, 20, 5, 12};
        int n = wt.length;
        double[] ratio = new double[n];
        for (int i = 0; i < n; i++) 
            ratio[i] = val[i] / wt[i];
        // Knapsack Capacity
        int W=12;
        Knapsack obj = new Knapsack();
        // call to fractionalKnapsackProblem function
        double value = obj.fractionalKnapsackProblem(wt, val, ratio, W);
        System.out.println("The maximum profit that can be obtained is :"+value);
    }   
}
/*
Output:
The maximum profit that can be obtained is :55
*/
