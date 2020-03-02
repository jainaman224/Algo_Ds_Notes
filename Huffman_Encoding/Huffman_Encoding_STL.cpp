#include<bits/stdc++.h>
using namespace std;

// A Huffman tree node 
struct MinHeap_Node{    
    // Count of the character
    int count; 

    // One of the input characters 
    char data; 

    // Left and right child 
    MinHeap_Node *left, *right;
    MinHeap_Node(int count, char data){    
        left = right = NULL;
        this -> count = count;
        this -> data = data;
    }
};

// For comparison of two heap nodes(needed in min heap)
struct compare{    
    bool operator()(MinHeap_Node *l, MinHeap_Node *r){
        return l -> count > r -> count;
    }
};

// Prints huffman codes from the root of Huffman Tree
void print_node(MinHeap_Node *node, string s){
    if(!node)
        return;
    if(node -> data != '#')
        cout << node -> data << " " << s << endl;
    print_node(node -> left, s + "0");
    print_node(node -> right, s + "1");
}

// The main function that builds a Huffman Tree 
// and print codes by traversing the built Huffman Tree 
void Huffman(int count[], char data[], int n){  
    // Min heap & inserting all characters of data[] 
    priority_queue<MinHeap_Node*, vector<MinHeap_Node*>, compare> heap;  
 
    for(int i = 0; i < n; i++)
        queue.push(new MinHeap_Node(count[i], data[i]));
    
    while(heap.size() != 1){
        // Extract the two minimum freq items from min heap 
        MinHeap_Node *left = heap.top();
        heap.pop();
        MinHeap_Node *right = heap.top ();
        queue.pop();
      
        /* Create a new internal node with count equal to the sum of
        the two nodes counts.Make the two extracted node as left and 
        right children of this new node.Add this node to the min heap 
        '#' is a special value for internal nodes, not used */

        MinHeap_Node *top = new MinHeap_Node(left -> count + right -> count, '#');
        top -> left = left;
        top -> right = right;
        queue.push(top);
    }

    // Print Huffman codes using the Huffman tree
    print_node(heap.top(), "");
}

int main (){
    cout << "Enter the number of input characters: ";
    int n;
    cin >> n;

    cout << "\nEnter the characters and corresponding count: ";
    char data[n];
    int count[n];
    for(int i = 0; i < n; i++)
        cin >> data[i] >> count[i];
    
    cout << "Following is the Huffman Encoding:\n";
    Huffman(count, data, n);
}

/* Sample Input-Output
Enter the number of input characters: 6                                                                                         
                                                                                                                                
Enter the characters and corresponding count: a 5                                                                               
b 9                                                                                                                             
c 12                                                                                                                            
d 13                                                                                                                            
e 16                                                                                                                            
f 45                                                                                                                            
Following is the Huffman Encoding:                                                                                              
f 0                                                                                                                            
c 100                                                                                                                          
d 101                                                                                                                          
a 1100              
b 1101                                                                                                                         
e 111
*/
