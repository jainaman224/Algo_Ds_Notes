class BinarySearchTree
{
    node head;

    static class node
    {
        int data;
        node left;
        node right;

        node(int d)
        {
            data = d;
            left = null;
            right = null;
        }
    }

    public void Insert(int value)
    {
        node temp = new node(value);

        if (head == null)
            head = temp;
        else
        {
            node current;
            current = head;

            while (current != null)
            {
                if (value < current.data)
                {
                    if (current.left != null)
                        current = current.left;
                    else
                    {
                        current.left = temp;
                        return ;
                    }
                }
                else
                {
                    if (current.right != null)
                        current = current.right;
                    else
                    {
                        current.right = temp;
                        return ;
                    }
                }
            }
        }
    }

    public void Search(int value)
    {
        node current;
        current = head;

        while (current != null)
        {
            if (value < current.data)
                current = current.left;
            else if (value > current.data)
                current = current.right;
            else
            {
                System.out.println("Element " + value + " Found");
                return ;
            }
        }

        System.out.println("Element " + value + " not Found");
    }

    public int Min_Value(node head)
    {
        while (head.left != null)
            head = head.left;
        return head.data;
    }

    public node Delete_Key(node head, int value)
    {
        if (head == null)
            return head;

        if (value < head.data)
            head.left = Delete_Key(head.left, value);
        else if (value > head.data)
            head.right = Delete_Key(head.right, value);
        else
        {
            if (head.left == null)
                return head.right;
            else if (head.right == null)
                return head.left;

            head.data = Min_Value(head.right);
            head.right = Delete_Key(head.right, head.data);
        }

        return head;
    }

    public void Delete(int value)
    {
        head = Delete_Key(head, value);
    }

    public static void main(String[] args)
    {
        BinarySearchTree BST = new BinarySearchTree();

        BST.Insert(5);
        BST.Insert(7);
        BST.Insert(9);
        BST.Insert(8);
        BST.Insert(6);
        BST.Insert(4);

        BST.Search(9);
        BST.Search(2);

        BST.Delete(7);
        BST.Delete(5);
        BST.Delete(4);

        BST.Search(9);
        BST.Search(2);
        BST.Search(5);
        BST.Search(6);
    }
}

/* Output

Element 9 Found
Element 2 not Found
Element 9 Found
Element 2 not Found
Element 5 not Found
Element 6 Found

*/
