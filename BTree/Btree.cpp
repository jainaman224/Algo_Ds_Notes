/*
 B Tree is a specialized m-way tree that can be widely used for disk access.
 A B-Tree of order m can have at most m-1 keys and m children,where (m is order of tree) .
 One of the main reason of using B tree is its capability to store large number of keys in
 a single node and large key values by keeping the height of the tree relatively small
 */

/* properties -
 Every node in a B-Tree contains at most m children.
 Every node in a B-Tree except the root node and the leaf node contain at least m/2 children.
 The root nodes must have at least 2 nodes.
 All leaf nodes must be at the same level.
 */

#include <iostream>

using namespace std;

class create_tree_node
{
    public :
        
        int *Key;                       // An array of keys
        int no_of_key;                  // total number of key value in a node
        create_tree_node **child;       // An array of child pointers
        int count_of_keys;              // Current number of keys
        bool leaf;                      // Is true when node is leaf. Otherwise false
    
    create_tree_node(int t1, bool leaf1)
    {
        no_of_key = t1;
        leaf = leaf1;
        count_of_keys = 0;               // Initialize the number of keys as 0
        
        // Allocate memory for maximum number of possible keys and child pointers
        Key = new int[2*no_of_key-1];
        child = new create_tree_node *[2*no_of_key];
     
    }
    
    // Function to split note and create new node
    void split(int i,create_tree_node *y)
    {
        // create a new node pointer
        create_tree_node *z = new create_tree_node(y->no_of_key,y->leaf);
        
        // new node t-1 node
        z->count_of_keys = no_of_key-1;
        
        // Copy the last (t-1) keys of y to z
        for (int j = 0; j < no_of_key-1; j++)
            z->Key[j] = y->Key[j+no_of_key];
        
        // Copy the last t children of y to z
        if (y->leaf == false)
        {
            for (int j = 0; j < no_of_key; j++)
                z->child[j] = y->child[j+no_of_key];
        }
        
        y->count_of_keys = no_of_key - 1;
        
        // create a space of new child in node
        for (int j = count_of_keys; j >= i+1; j--)
            child[j+1] = child[j];
        
        child[i+1] = z;    //link node with new child
        
        // A key of y will move to this node. Find the location of
        // new key and move all greater keys one space ahead
        
        for (int j = count_of_keys-1; j >= i; j--)
            Key[j+1] = Key[j];
        
        Key[i] = y->Key[no_of_key-1];
        
        count_of_keys = count_of_keys + 1;// inc the count of key
        
    }

    // function to insert a key to node if the node is not full
    void insertnonfull(int k)
    {
        // Initialize index as index of rightmost element
        int i = count_of_keys-1;
        
        // If this is a leaf node
        if (leaf == true)
        {
            // find location of new keys in node move all key greater than key to be insert in one side
            while (i >= 0 && Key[i] > k)
            {
                Key[i+1] = Key[i];
                i--;
            }
            
            Key[i+1] = k;   // incementing values of key
            
            count_of_keys = count_of_keys+1;
        }
        
        // If this node is not leaf
        else
        {
            // Find the child which is going to have the new key
            while (i >= 0 && Key[i] > k)
                i--;
            
            if (child[i+1]->count_of_keys == 2*no_of_key-1)
            {
                // If the child is full, then split i
                split(i+1, child[i+1]);
                
                if (Key[i+1] < k)
                    i++;
            }
            child[i+1]->insertnonfull( k);
        }
    }
    
    // Function to traverse all nodes in a subtree rooted with this node
    void traverse()
    {
        int i;
        
        // There are n keys and n+1 children, traverse through n keys and first n children
        for (i = 0; i < count_of_keys; i++)
        {
            // If this is not leaf, then before printing key[i],
            // traverse the subtree rooted with child .
            if (leaf == false)
                child[i]->traverse();
            cout <<"\n"<< Key[i];
        }
        
        if (leaf == false)
            child[i]->traverse();
     }
   
     friend class btree;
    
};

class btree
{

    public:
        
        create_tree_node  *root;    // pointer to root node
        int t,temp;                 // min degree
    
        // contructor of class btree for initializes the root to null
        btree(int t1)
        {
            root = NULL;
            t = t1;
        }
    
        // tree traverse function
        void traverse()
        {
            if (root != NULL) root->traverse();
        }
    
        // first call to insert the data in to tree
        void insert()
        {
            cout<<" "<<"Enter the number to add"<<"\n" ;
            cin>>temp;                                // value to be insert to tree
        
            if(root == NULL)                          // if tree is empty
            {
                root = new create_tree_node(t,true);  // create a memory location for root
                root->Key[0] = temp;                  // assigning a key  to root node
                root->count_of_keys = 1;              // update a number of key in node
            }
        
            else
            {
                // check count of key in node is equal min degree the tree grown in height
                if(root->count_of_keys == (2*t-1))
                {
                    // Allocate memory location for new root
                    create_tree_node *s = new create_tree_node(t,false);
                    s->child[0] = root;   // make a old root to child of new root
                    s->split(0,root);  // function to split old node by creating new node and move one 1 key in one node
                    int i = 0;
                    if (s->Key[0] < temp)
                        i++;
                    s->child[i]->insertnonfull( temp);
                    root = s;
                 }
            
                else
                {
                    root->insertnonfull( temp);
                }
            }
        }
};

int main()
{
    
    btree t(3);
    int opt;
    
    // infinte loop for inserting  or traverse or exit according to user choice
    while(1)
    {
       
        cout<<" \npress 1 for insert \npress 2 for traverse \npress 3 for Exit ";
        
        cin>>opt;
        
        switch(opt)
        {
            case 1:
                
                t.insert();     // function call to inset of Btree class
                break;
            
            case 2:
                
                t.traverse();   // function call to traverse of Btree class
                break;
            
            case 3:
               
                exit(0);        // to exit from current working program
        }
     
    }
    
    return 0;
}

/*
 
 // Sample input :
 10 21 31 41 51
 // output
 10 21 31 41 51
 // Sample input :
 70 31 31 21 51
 // output
 21 21 31 51 70
 
*/
