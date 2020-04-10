//Program to print nodes at depth k in a generic tree

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Following is the TreeNode structure

template <typename T>
class TreeNode 
{
    public:
    
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) 
        {
           this->data = data;
        }
    
    ~TreeNode()
     {
          for (int i = 0; i < children.size(); i++) 
            {
                 delete children[i];
            }
     }
    
};

//  Following is the function to print the nodes at depth k

void printNodesAtDepthK(TreeNode<int>* root, int k) 
{
     if(k==0)
      { 
         cout<<root->data<<" ";
         return;
      }
      
     for(int i=0;i<root->children.size();i++)
     {     
         TreeNode<int>* t=root->children[i];
          printNodesAtDepthK(t,k-1);
      }
    
}
//Taking input level wise
TreeNode<int>* takeInputLevelWise()
{
    int rootData;
    
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);   
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    while (pendingNodes.size() != 0) 
    {
        int numChild;
        
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop(); 
        cin >> numChild;
        
        for (int i = 0; i < numChild; i++) 
        {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
        
    }
    
    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    int k;
    cin >> k;
    printNodesAtDepthK(root, k);
}


/***
Sample input:
10 3 20 30 40 2 40 50 0 0 0 0 
1

Output:
20 30 40

****/
