/*
Fractional Knapsack problem is a variation of Knapsack problem where we can choose items by breaking them in fractions.
The objective is to fill the knapsack with items to get maximum benefit without crossing the weight capacity of the knapsack.
*/
import java.util.Arrays;
import java.util.Comparator;

// Class as type to hold item's weight, value and ratio 
class Item 
{
    int weight;
    int value;
    Double ratio;
    public Item (int val, int wt) 
    {
        this.weight = wt;
        this.value = val;
        ratio = new Double((double) val / wt);
    }
}

class FractionalKnapsack
{
    // Function to compute maximum profit obtainable
    double fractionalKnapsackProblem(Item arr[], int nItems, int Capacity)
    {
        /* We sort arr on the basis of ratio value/weight, so arr becomes:
        { (12,2), (5,1), (15,3), (20,5), (30,10), (12, 6)} */
        Arrays.sort(arr, new Comparator<Item>(){
            @Override
            public int compare (Item myItem1, Item myItem2) {
                return myItem2.ratio.compareTo(myItem1.ratio); 
            }
        });
        /* variable weight to keep track of current weight added to Knapsack
        variable value to keep track of current value obtained from Knapsack
        variable remain to keep track of additional weight that can still be added to Knapsack*/
        double weight = 0.0;
        double value = 0.0;
        double remain;
        // Items with greater value/weight are selected first
        for (int i = 0; i < nItems; i++)
        {
            // if current weight plus weight of the item to be added doesn't exceed Knapsack capacity select it
            if ((weight + arr[i].weight) <= Capacity) 
            {
                weight += (arr[i].weight);
                value += (arr[i].value);
            }
             /* if current weight plus weight of the item to be added exceeds Knapsack capacity, break the item into fractional part, and select the portion out of it which doesn't exceed the Knapsack capacity*/
            else
            {
                remain = (Capacity - weight);
                value += ((arr[i].value) * (remain / arr[i].weight));
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
        // storing number of items
        int nItems = wt.length;
        Item[] arr = new Item[nItems];
        /* storing values in arr of type class Item, so array will hold: 
        {(12, 6), (30,10), (15,3), (20,5), (5,1), (12,2)}*/
        for (int i = 0; i < nItems; i++)
            arr[i] = new Item(val[i], wt[i]);
        // Knapsack Capacity
        int Capacity = 12;
        // Call to Knapsack function
        FractionalKnapsack obj = new FractionalKnapsack();
        double value = obj.fractionalKnapsackProblem(arr, nItems, Capacity);
        System.out.println("The maximum profit that can be obtained is :"+value);
    }
}
/*
Output:
The maximum profit that can be obtained is :55.0
*/
