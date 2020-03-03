/*
	In Binary Tree Pair Sum, a binary Tree and a number is given. You need
	to find the pair of all the nodes, whose elements' sum is equal to the
	given number.
*/

#include <bits/stdc++.h>
using namespace std;


// defining the class for Binary Tree where the data is of Data type 'T'
template <typename T>
class BinaryTreeNode 
{
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T d) 
    {
        this -> data = d;
        left = NULL;
        right = NULL;
    }
    // the destructor deletes all the nodes of the tree
    ~BinaryTreeNode()
     {
        // the size of all the nodes deallocated by the use of recursion  
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

void convertToArray(BinaryTreeNode<int> *root, vector<int>& output)
{
	// base case
	if (root == NULL)
	{
		return;
	}
	
	output.push_back(root->data);
	convertToArray(root->left, output);
	convertToArray(root->right, output);
}

void sortArray(vector<int>& output)
{
	sort(output.begin(), output.end());
}


void nodesSumToS(BinaryTreeNode<int> *root, int k) 
{
	vector<int> output;
	
	// put the elements of Binary Tree to Array
	convertToArray(root, output);
	
	// sort the array
	sortArray(output);
	
	int i = 0;
	int j = output.size()-1;
	while (i < j)
	{
		if (output[i] + output[j] == k)
		{
			// if duplicate elements are present
			int count1 = 1, count2 = 1;
			int l = i+1;
			
			// count the number of times 1st element is repeated
			while (output[l] + output[j] == k)
			{
				count1++;
			}
			
			l = j-1;
			
			// count the number of times 2nd element is repeated
			while (output[i] + output[l] == k)
			{
				count2++;
			} 
			
			int count = count1*count2;
			
			// print the numbers count no. times
			for (int a = 0; a < count; a++)
			{
				cout << output[i] << ' ' << output[j];
			}
		}
		else if (output[i] + output[j] > k)
		{
			j--;
		}
		else {
			i++;
		}
			
	}
	
}


// driver function
int main() 
{
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;

    // entering -1 from the user means there is no element present at that position of the tree
    if(rootData == -1) 
    {
        return -1;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
	    q.pop();
        int leftChild, rightChild;
        cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1)
         {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) 
        {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    int sum;
    cin >> sum;
    nodesSumToS(root, sum);
    delete root;
}




