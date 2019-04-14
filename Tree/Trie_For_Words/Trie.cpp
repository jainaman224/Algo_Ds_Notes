#include <iostream>

using namespace std;

struct node
{
    node *alphabet[26];
    bool isLeaf;
} *root = NULL;

node *getNode()
{
    node *temp = new node();
    temp -> isLeaf = false;

    for(int i = 0; i < 26; i++)
    {
        temp -> alphabet[i] = NULL;
    }

    return temp;
}

void insert(string a)
{
    if(root == NULL)
        root = getNode();

    node *current = root;

    for(unsigned int i = 0; i < a.length(); i++)
    {
        a[i] = tolower(a[i]);

        if(current -> alphabet[int(a[i]) - 97] == NULL)
        {
            node *new_node = getNode();
            current -> alphabet[int(a[i]) - 97] = new_node;
            current = new_node;
        }
        else
            current = current -> alphabet[int(a[i]) - 97];
    }

    current -> isLeaf = true;
}

void search(string a)
{
    if(root == NULL)
        cout << "There is no word in Trie" << endl;

    node *current = root;
    unsigned int i;

    for(i = 0; i < a.length(); i++)
    {
        a[i] = tolower(a[i]);

        if(current -> alphabet[int(a[i] - 'a')] == NULL)
        {
            break;
        }
        else
            current = current -> alphabet[int(a[i] - 'a')];
    }

    if(i == a.length() && current -> isLeaf == true)
        cout << a << " Found" << endl;
    else
        cout << a << " Not Present" << endl;
}

bool isFreeNode(node *root)
{
    for(int i = 0; i < 26; i++)
    {
        if(root -> alphabet[i] != NULL)
            return false;
    }

    return true;
}

bool removeWord(node *root, string a, unsigned int i)
{
    if(root)
    {
        if(i == a.length())
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
            a[i] = tolower(a[i]);

            if(removeWord(root -> alphabet[int(a[i]) - 97], a, i + 1))
            {
                delete root -> alphabet[int(a[i]) - 97];
                root -> alphabet[int(a[i]) - 97] = NULL;

                return (!root -> isLeaf && isFreeNode(root));
            }
        }
    }

    return false;
}

void remove(string a)
{
    if(a.length() && root != NULL)
        removeWord(root, a, 0);
}

int main()
{
    string a = "aman", b = "akshit", c = "adish", d = "akshay", e = "akash";

    insert(a);
    insert(b);
    insert(c);
    insert(d);
    insert(e);

    search(a);
    search(b);
    search(e);
    search("swati");

    remove(a);

    search(a);

    return 0;
}

/* Output

aman Found
akshit Found
akash Found
swati Not Present
aman Not Present

*/
