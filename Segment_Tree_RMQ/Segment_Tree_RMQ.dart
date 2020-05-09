/**
 *    Dart implementation of Segment Tree for Range Minimum Query
 * -------------------------------------------------------------------------
 * Segment Tree is a binary tree whose nodes are ranges of an interval.
 * Each node has a value corresponding to it's interval.
 * Construction of a Segment Tree takes O(n) time.
 * Querying on the same takes O(logn) time.
 * Hence, many queries can be answered efficiently in time using Segment Tree.
 * 
 * 
*/

// Importing required libraries
import 'dart:io';
import 'dart:math';

// Maximum range of int of 64 bits.
const int int64MaxValue = 9223372036854775807;

// Function to find logarithm to base 2.
double logtobase2(int n){

    return log(n) / log(2);

}

// Function to update value at a particular position in the tree
void updateNode(List tree , int treestart , int treeend , int nodeindex , int position , int newval){

    if (treestart == treeend){

        tree[nodeindex] = newval;

    }
    else{

        int mid = (treestart + ((treeend - treestart) / 2)).floor();

        if (position < mid){

            updateNode(tree , treestart , mid , 2 * nodeindex , position , newval);

        }
        else{

            updateNode(tree , mid + 1 , treeend, 2 * nodeindex + 1 , position, newval);

        }

        tree[nodeindex] = min<int>(tree[2 * nodeindex] , tree[2 * nodeindex + 1]);

    }
    
}

// Function to query on a Segment Tree
int queryonSegmentTree(List tree , int start , int end , int treestart , int treeend , int nodeindex){
    
    if (start > end){
    
        return int64MaxValue;
    
    }
    
    // Base Case
    if (start == treestart && end == treeend){
    
        return tree[nodeindex];
    
    }
    
    // Finding the index of midpoint
    int mid = (treestart + (treeend - treestart) / 2).floor();

    int value1 , value2;


    // Recursion to find the minimum.
    value1 = queryonSegmentTree(tree , start , min<int>(end,mid) , treestart , mid , 2 * nodeindex );
    
    value2 = queryonSegmentTree(tree , max<int>(start , mid + 1) , end , mid + 1 , treeend , 2 * nodeindex + 1 );

    // Returning minimum.
    return min<int>(value1 , value2);

}

// Function to construct the Segment Tree.
void constructSegmentTree(List tree , List numbers , int start , int end , int nodeindex){

    // Base Case
    if (start == end){
        
        tree[nodeindex] = numbers[start];
        return;
    
    }

    // Finding index of the midpoint.
    int mid = (start + ((end - start) / 2)).floor();
    
    // Recursion to find minimum.
    constructSegmentTree(tree , numbers , start , mid , 2 * nodeindex);
    
    constructSegmentTree(tree , numbers , mid + 1 , end , 2 * nodeindex + 1);

    // Finding minimum of the parent from its children.
    tree[nodeindex] = min<int>(tree[2 * nodeindex],tree[2 * nodeindex + 1]);
    
}

// Driver function of the program.
void main(){

    // Taking input of number of array elements.
    print("Enter number of elements: ");

    var input = stdin.readLineSync();
    
    int n = int.parse(input);
      
    // Taking input of the number array (num[i]).
    print("Enter array of numbers:");

    input = stdin.readLineSync();
    
    var lis = input.split(' ');
    
    List numbers = lis.map(int.parse).toList();

    // Calculating the depth of the possible binary tree.
    int depth = logtobase2(n).ceil();
    // Finding the maximum number of nodes in the binary tree.
    int num_nodes = 2 * pow(2 , depth) - 1;

    // Initializing the Segment tree.
    List<int> tree = List<int>.generate(num_nodes + 1 , (i) => 0);
    
    // Constructing the Segment Tree.
    constructSegmentTree(tree , numbers , 0 , n - 1 , 1);

    // Taking input of number of queries.
    print("Enter number of queries: ");

    input = stdin.readLineSync();
    
    int q = int.parse(input);

    List queries = List<int>(2);

    int flag;


    // Taking input of queries.
    print("Enter queries: ");

    for (int i = 0 ; i < q ; i ++){

        print("Enter 1 to retrieve minimum in a range or 2 to update a value: ");

        input = stdin.readLineSync();

        flag = int.parse(input);

        print("Enter corresponding query: ");
        
        input = stdin.readLineSync();
        
        lis = input.split(' ');

        queries = lis.map(int.parse).toList();

        if (flag == 2){

            numbers[queries[0]] = queries[1];
            updateNode(tree , 0 , n - 1 , 1 , queries[0] , queries[1]);

        }
        else{

            // Printing output of each query.
            print(queryonSegmentTree(tree , queries[0] , queries[1] , 0 , n - 1 , 1));

        }    
  
    }

}

/**
 * 
 *    Sample Input & Output 
 * ---------------------------
 * Enter number of elements:
 * 10
 * Enter array of numbers:
 * 12 43 9 -2 1 8 6 5 10 23
 * Enter number of queries:
 * 6
 * Enter queries:
 * Enter 1 to retrieve minimum in a range or 2 to update a value:
 * 1
 * Enter corresponding query:
 * 1 2
 * 9    (Output)
 * Enter 1 to retrieve minimum in a range or 2 to update a value:
 * 2
 * Enter corresponding query:
 * 0 -12
 * Enter 1 to retrieve minimum in a range or 2 to update a value:
 * 1
 * Enter corresponding query:
 * 1 2
 * -12    (Output)
 * Enter 1 to retrieve minimum in a range or 2 to update a value:
 * 2
 * Enter corresponding query:
 * 7 -100
 * Enter 1 to retrieve minimum in a range or 2 to update a value:
 * 1
 * Enter corresponding query:
 * 4 9
 * -100  (Output)
 * Enter 1 to retrieve minimum in a range or 2 to update a value:
 * 1
 * Enter corresponding query:
 * 2 6
 * -2   (Output)
 * 
 */
