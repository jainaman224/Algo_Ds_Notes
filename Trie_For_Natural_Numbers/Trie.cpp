#include <iostream>

using namespace std;

struct node
{
    node *number[10];
    bool isLeaf;
} *root = NULL;

node *getNode()
{
    node *temp = new node();
    temp -> isLeaf = false;

    for(int i = 0; i < 10; i++)
    {
        temp -> number[i] = NULL;
    }

    return temp;
}

void insert(int a)
{
    if(root == NULL)
        root = getNode();

    node *current = root;

    while(a != 0)
    {
        if(current -> number[a % 10] == NULL)
        {
            node *new_node = getNode();
            current -> number[a % 10] = new_node;
            current = new_node;
        }
        else
            current = current -> number[a % 10];

        a /= 10;
    }

    current -> isLeaf = true;
}

void search(int value)
{
    if(root == NULL)
        cout << "There is no word in Trie" << endl;

    node *current = root;
    int a = value;

    while(a != 0)
    {
        if(current -> number[a % 10] == NULL)
        {
            break;
        }
        else
            current = current -> number[a % 10];

        a /= 10;
    }

    if(a == 0 && current -> isLeaf == true)
        cout << value << " Found" << endl;
    else
        cout << value << " Not Present" << endl;
}

bool isFreeNode(node *root)
{
    for(int i = 0; i < 10; i++)
    {
        if(root -> number[i] != NULL)
            return false;
    }

    return true;
}

bool removeNumber(node *root, int a)
{
    if(root)
    {
        if(a == 0)
        {
            if(root -> isLeaf)
            {
                root -> isLeaf = false;

                if(isFreeNode(root))
                    return true;
            }

            return false;
        }
        else
        {
            if(removeNumber(root -> number[a % 10], a / 10))
            {
                delete root -> number[a % 10];
                root -> number[a % 10] = NULL;

                return (!root -> isLeaf && isFreeNode(root));
            }
        }
    }

    return false;
}

void remove(int a)
{
    if(a != 0 && root != NULL)
        removeNumber(root, a);
}

int main()
{
    int a = 99, b = 9999, c = 9987, d = 8687, e = 5499;

    insert(a);
    insert(b);
    insert(c);
    insert(d);
    insert(e);

    search(a);
    search(b);
    search(e);
    search(7676);

    remove(a);

    search(a);

    return 0;
}

/* Output

99 Found
9999 Found
5499 Found
7676 Not Present
99 Not Present

*/
