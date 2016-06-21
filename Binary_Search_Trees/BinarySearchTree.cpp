#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
} *head = NULL;

void Insert(int value)
{
    node *temp = new node;
    temp -> data = value;

    if(head == NULL)
        head = temp;
    else
    {
        node *current = head;

        while(current != NULL)
        {
            if(value < current -> data)
            {
                if(current -> left != NULL)
                    current = current -> left;
                else
                {
                    current -> left = temp;
                    return ;
                }
            }
            else
            {
                if(current -> right != NULL)
                    current = current -> right;
                else
                {
                    current -> right = temp;
                    return ;
                }
            }
        }
    }
}

void Search(int value)
{
    node *current = head;

    while(current != NULL)
    {
        if(value < current -> data)
            current = current -> left;
        else if(value > current -> data)
            current = current -> right;
        else
        {
            cout << "Element " << value << " Found" << endl;
            return ;
        }
    }

    cout << "Element " << value << " not Found" << endl;
}

int Min_Value(node *head)
{
    while(head -> left != NULL)
    {
        head = head -> left;
    }
    return head -> data;
}

node* Delete_Key(node *head, int value)
{
    if(head == NULL)
        return head;

    if(value < head -> data)
        head -> left = Delete_Key(head -> left, value);
    else if(value > head -> data)
        head -> right = Delete_Key(head -> right, value);
    else
    {
        if(head -> left == NULL)
            return head -> right;
        else if(head -> right == NULL)
            return head -> left;

        head -> data = Min_Value(head -> right);
        head -> right = Delete_Key(head -> right, head -> data);
    }

    return head;
}

void Delete(int value)
{
    head = Delete_Key(head, value);
}

int main()
{
    Insert(5);
    Insert(7);
    Insert(9);
    Insert(8);
    Insert(6);
    Insert(4);

    Search(9);
    Search(2);

    Delete(7);
    Delete(5);
    Delete(4);

    Search(9);
    Search(2);
    Search(5);
    Search(6);
    return 0;
}

/* Output

Element 9 Found
Element 2 not Found
Element 9 Found
Element 2 not Found
Element 5 not Found
Element 6 Found

*/
