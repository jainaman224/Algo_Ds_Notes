/*
One other way to represent a mathematical equation is Expression Tree. It is a binary
tree in which every parent node corresponds to the operator and the leaf nodes correspond
to operands.
Expression Tree of a + b is :

      +
     / \
    a   b
Preorder traversal of expression tree will give us prefix to of the expression and inorder
traversal will results to infix expression.
*/

#include<bits/stdc++.h>
using namespace std;

// node class for expression tree
class node
{
    public:
    char data;
    node *left, *right;
    node(char data)
    {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

//expression tree class
class exp_tree
{
    string postfix_exp;
    node *root;
    public:
    exp_tree(string postfix_exp)
    {
        this -> postfix_exp = postfix_exp;
        root = NULL;
        create_tree(postfix_exp);
    }

    private:
    bool is_operator(char c)
    {
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') // if given char is operator
        {
            return true; // then return true
        }
        return false; // else return false
    }

    void create_tree(string exp)
    {
        int len = exp.length();
        stack<node *> s; // store those operator node whose any child node is NULL
        root = new node(exp[len-1]);
        s.push(root); // last character of postfix expression is always an operator
        for (int i = len-2; i >= 0; i--) // travel on rest of the postfix expression
        {
            node* curr_node = s.top();
            if (curr_node -> right == NULL) // if right node of current node is NULL
            {
                node *temp = new node(exp[i]);
                curr_node -> right = temp;
                if (is_operator(exp[i]))
                {
                    s.push(temp);
                }
            }
            else // if left node of current node is NULL
            {
                node *temp = new node(exp[i]);
                curr_node -> left = temp;
                // if no child node of current node is NULL
                s.pop(); // pop current from stack
                if (is_operator(exp[i]))
                {
                    s.push(temp);
                }
            }
        }
    }
    void inorder_traversal(node *head) // inorder traversal of expression tree
    {
        // inorder traversal => left,root,right
        if (head -> left != NULL)
        {
            inorder_traversal(head -> left);
        }
        cout << head -> data << " ";
        if (head -> right != NULL)
        {
            inorder_traversal(head -> right);
        }
        return;
    }
    public:
    void infix_exp() // inorder traversal of expression tree will give infix expression
    {
        inorder_traversal(root);
        cout << endl;
        return;
    }
};

int main()
{
    string postfix_exp;
    getline(cin, postfix_exp);
    exp_tree et(postfix_exp);
    et.infix_exp();
    return 0;
}

/*
sample input  : 395+2*+
sample output : 3 + 9 + 5 * 2
*/

/*
This code is contributed by raghav
https://github.com/raghav-dalmia
*/

