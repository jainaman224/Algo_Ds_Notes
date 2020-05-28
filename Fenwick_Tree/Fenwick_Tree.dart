/**
 *    Fenwick Tree
 * -------------------------
 * Binary Indexed tree or Fenwick tree is used to solve
 * range queries optimally. It has O(n) space complexity,
 * O(logn) time complexity to update, O(nlog(n)) time complexity to build
 * and O(logn) time complexity to find sum in a given range.
 * 
 */
// Importing required libraries
import 'dart:io';

// Updating the tree with respect to any updates or construction
void updateBITTree(List tree, int n, int index, int val){
    index = index + 1;

    while(index <= n){
        tree[index] += val;
        index += index & ( - index);        
    }

}

// Method to find the sum till a given index
int getSum(List tree, int index){

    int total = 0;
    index = index + 1;

    while(index > 0){
        total += tree[index];
        index -= index & ( - index );
    }

    return total;
}

// Method to find sum between a range using the above method.
int findSum(List tree, int left, int right){
    if(left > right){
        return -1;
    }
    else if(left == right){
        return getSum(tree, left) - getSum(tree, left - 1);
    }
    else{
        if(left > 0){
            return getSum(tree,right) - getSum(tree,left) + (getSum(tree, left) - getSum(tree, left - 1));
        }
        else if(left == 0){
            return getSum(tree,right);
        }
        else{
            return -1;
        }
    }
}

// Driver method of the program
void main(){

    // Input of number of array elements
    print("Enter number of elements in the array:");
    var input = stdin.readLineSync();
    int n = int.parse(input);

    // Input of array elements
    print("Enter array elements:");
    input = stdin.readLineSync();
    var lis = input.split(" ");
    List array = lis.map(int.parse).toList();
    
    // Fenwick tree initialization
    List tree_BIT = List(n + 1);
    for(int i = 0; i < n + 1; i ++){
        tree_BIT[i] = 0;
    }
    
    // Tree construction
    for(int i = 0; i < n; i ++){
        updateBITTree(tree_BIT, n, i, array[i]);
    }
    
    // Input of number of queries
    print("Enter number of queries:");
    input = stdin.readLineSync();
    int q = int.parse(input);

    // Input of queries
    print("Enter queries:");
    for(int i = 0 ; i < q ; i ++){

        print("Enter 1 to update, 2 to find sum:");
        input = stdin.readLineSync();
        int choice = int.parse(input);
        switch(choice){

            case 1: 
                // Input for updates
                print("Enter index and value to update");
                input = stdin.readLineSync();
                lis = input.split(" ");
                List choices = lis.map(int.parse).toList();
                array[choices[0]] += choices[1];
                // Updating value
                updateBITTree(tree_BIT, n, choices[0], choices[1]);
                break;
            case 2: 
                // Input for sum queries
                print("Enter range to find the sum");
                input = stdin.readLineSync();
                lis = input.split(" ");
                List choices = lis.map(int.parse).toList();
                // Finding sum
                int result = findSum(tree_BIT,choices[0],choices[1]);
                print(result);
                break;
        }
    }
}

/**
 * 
 *   Sample Input 
 * ------------------------------------
 * Enter number of elements in the array:
 * 12
 * Enter array elements:
 * 2 1 1 3 2 3 4 5 6 7 8 9
 * Enter number of queries:
 * 5
 * Enter 1 to update, 2 to find sum:
 * 2
 * Enter range to find the sum
 * 0 5
 * Enter 1 to update, 2 to find sum:
 * 1
 * Enter index and value to update
 * 3 9
 * Enter 1 to update, 2 to find sum:
 * 2
 * Enter range to find the sum
 * 0 5
 * Enter 1 to update, 2 to find sum:
 * 2
 * Enter range to find the sum
 * 5 9
 * Enter 1 to update, 2 to find sum:
 * 2
 * Enter range to find the sum
 * 8 8
 * 
 *   Sample Output
 * ----------------------------------------
 * 12
 * 21
 * 25
 * 6
 */
