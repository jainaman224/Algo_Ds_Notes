

// cpp program of BTree on insert and traverse the tree ,BTree is tree data structure which use to
 //indexing of database.//

#include <iostream>
using namespace std;
class create_tree_node{
    public :
    int *Key;
    int no_of_key;
    create_tree_node **child;
    int count_of_keys;
    bool leaf;
    
    create_tree_node(int t1,bool leaf1){
        no_of_key=t1;
        leaf=leaf1;
        Key=new int[2*no_of_key-1];
        child=new create_tree_node *[2*no_of_key];
        count_of_keys=0;
    }
    //Function to split note and creayte new node
    void split(int i,create_tree_node *y){
        create_tree_node *z=new create_tree_node(y->no_of_key,y->leaf);   // create a new node pointer
        z->count_of_keys=no_of_key-1;   //new node t-1 node
       
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
        
        //create a space of new child in node
        for (int j = count_of_keys; j >= i+1; j--)
            child[j+1] = child[j];
        
        child[i+1] = z;  //link node with new child
        
        // A key of y will move to this node. Find the location of
        // new key and move all greater keys one space ahead
        for (int j = count_of_keys-1; j >= i; j--)
            Key[j+1] = Key[j];
        
        Key[i] = y->Key[no_of_key-1];
        
        count_of_keys = count_of_keys + 1;// inc the count of key
        
    }
    
    // function to insert a key to node if the node is not full
    void insertnonfull(int k){
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
            
            Key[i+1] = k;
            count_of_keys = count_of_keys+1; // incementing values of key
        }
        else   // If this node is not leaf
        {
            // Find the child which is going to have the new key
            while (i >= 0 && Key[i] > k)
                i--;
            
            if (child[i+1]->count_of_keys == 2*no_of_key-1)
            {
                split(i+1, child[i+1]);   // If the child is full, then split it
                
                if (Key[i+1] < k)
                    i++;
            }
            child[i+1]->insertnonfull( k);
        }
        
    }
    void traverse(){
        int i;
        for (i = 0; i < count_of_keys; i++)
        {
            if (leaf == false)
                child[i]->traverse();
            cout <<"\n"<< Key[i];
        }
        
        
        if (leaf == false)
            child[i]->traverse();
    }
    friend class btree;
};
class btree{
    public:
        create_tree_node  *root;   //pointer to root node
        int t,temp;          //min degree
        btree(int t1){       //contructor of class btree for initializes the root to null
            root=NULL;
            t=t1;
        }
        void traverse()         //tree traverse function
        {
            if (root != NULL) root->traverse();
            
        }
        void insert(){      //first call to insert the data in to tree
            cout<<" "<<"Enter the number to add"<<"\n" ;
            cin>>temp;      //value to be insert to tree
            if(root==NULL){     //if tree is empty
                root=new create_tree_node(t,true);  //create a memory location for root
                root->Key[0]=temp;       //assigning a key  to root node
                root->count_of_keys=1;          // update a number of key in node
            
        }
        else{
            if(root->count_of_keys==(2*t-1)){//check count of key in node is equal min degree the tree grown in height
                create_tree_node *s=new create_tree_node(t,false);//Allocate memory location for new root
                s->child[0]=root;   // make a old root to child of new root
                s->split(0,root); //function to split old node by creating new node and move one 1 key in one node
                int i=0;
                
                
                
                if (s->Key[0] < temp)
                    i++;
                s->child[i]->insertnonfull( temp);
                root = s;
                
            }
            
            else{
                root->insertnonfull( temp);
            }
        }
    }
    
};

int main()
{
    btree t(3);
    int opt;
    while(1){ // infinte loop for inserting  or traverse or exit according to user choice
        cout<<" \npress 1 for insert \npress 2 for traverse \npress 3 for Exit ";
        cin>>opt;
        switch(opt){
            case 1:
                t.insert(); // function call to inset of Btree class
                break;
            case 2:
                t.traverse(); //// function call to traverse of Btree class
                break;
            case 3:
                exit(0); // to exit from current working program
        }
    }
    return 0;
}
/*
 //Sample input :
 10 21 31 41 51
 output
 10 21 31 41 51
 //Sample input :
 70 31 31 21 51
 output
 21 21 31 51 70
 */
