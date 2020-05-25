using System;

namespace Declaring_Methods
{
    public static class Program
    {
        public static void Main(String[] args)
        {
            RedBlackTree bst = new RedBlackTree();
            bst.insert(54);
            bst.insert(38);
            bst.insert(62);
            bst.insert(58);
            bst.insert(73);
            bst.insert(55);
            bst.printTree();
            Console.WriteLine("\nAfter deleting:");
            bst.deleteNode(40);
            bst.printTree();
        }
        public class Node
        {
            public int data;
            public Node parent;
            public Node left;
            public Node right;
            public int color;
        }

        public class RedBlackTree
        {
            public Node root;
            public Node TNULL;

            //PreOder Traversal
            public void PreOder(Node node)
            {
                if (node != TNULL)
                {
                    Console.Write(node.data + " ");
                    PreOder(node.left);
                    PreOder(node.right);
                }
            }

            //InOder Traversal
            public void InOrder(Node node)
            {
                if (node != TNULL)
                {
                    InOrder(node.left);
                    Console.Write(node.data + " ");
                    InOrder(node.right);
                }
            }

            //PostOder Traversal
            public void PostOrder(Node node)
            {
                if (node != TNULL)
                {
                    PostOrder(node.left);
                    PostOrder(node.right);
                    Console.Write(node.data + " ");
                }
            }

            //Searching in the Tree
            public Node searchTreeHelper(Node node, int key)
            {
                if (node == TNULL || key == node.data)
                {
                    return node;
                }

                if (key < node.data)
                {
                    return searchTreeHelper(node.left, key);
                }
                return searchTreeHelper(node.right, key);
            }

            // Balance the tree after deletion of a node
            public void fixDelete(Node x)
            {
                Node s;
                while (x != root && x.color == 0)
                {
                    if (x == x.parent.left)
                    {
                        s = x.parent.right;
                        if (s.color == 1)
                        {
                            s.color = 0;
                            x.parent.color = 1;
                            leftRotate(x.parent);
                            s = x.parent.right;
                        }

                        if (s.left.color == 0 && s.right.color == 0)
                        {
                            s.color = 1;
                            x = x.parent;
                        }
                        else
                        {
                            if (s.right.color == 0)
                            {
                                s.left.color = 0;
                                s.color = 1;
                                rightRotate(s);
                                s = x.parent.right;
                            }

                            s.color = x.parent.color;
                            x.parent.color = 0;
                            s.right.color = 0;
                            leftRotate(x.parent);
                            x = root;
                        }
                    }
                    else
                    {
                        s = x.parent.left;
                        if (s.color == 1)
                        {
                            s.color = 0;
                            x.parent.color = 1;
                            rightRotate(x.parent);
                            s = x.parent.left;
                        }

                        if (s.right.color == 0 && s.right.color == 0)
                        {
                            s.color = 1;
                            x = x.parent;
                        }
                        else
                        {
                            if (s.left.color == 0)
                            {
                                s.right.color = 0;
                                s.color = 1;
                                leftRotate(s);
                                s = x.parent.left;
                            }

                            s.color = x.parent.color;
                            x.parent.color = 0;
                            s.left.color = 0;
                            rightRotate(x.parent);
                            x = root;
                        }
                    }
                }
                x.color = 0;
            }

            public void rbTransplant(Node u, Node v)
            {
                if (u.parent == null)
                {
                    root = v;
                }
                else if (u == u.parent.left)
                {
                    u.parent.left = v;
                }
                else
                {
                    u.parent.right = v;
                }
                v.parent = u.parent;
            }

            //Deleting the Node element
            public void deleteNodeHelper(Node node, int key)
            {
                Node z = TNULL;
                Node x, y;
                while (node != TNULL)
                {
                    if (node.data == key)
                    {
                        z = node;
                    }

                    if (node.data <= key)
                    {
                        node = node.right;
                    }
                    else
                    {
                        node = node.left;
                    }
                }

                if (z == TNULL)
                {
                    Console.WriteLine("Couldn't find key in the tree");
                    return;
                }

                y = z;
                int yOriginalColor = y.color;
                if (z.left == TNULL)
                {
                    x = z.right;
                    rbTransplant(z, z.right);
                }
                else if (z.right == TNULL)
                {
                    x = z.left;
                    rbTransplant(z, z.left);
                }
                else
                {
                    y = minimum(z.right);
                    yOriginalColor = y.color;
                    x = y.right;
                    if (y.parent == z)
                    {
                        x.parent = y;
                    }
                    else
                    {
                        rbTransplant(y, y.right);
                        y.right = z.right;
                        y.right.parent = y;
                    }

                    rbTransplant(z, y);
                    y.left = z.left;
                    y.left.parent = y;
                    y.color = z.color;
                }
                if (yOriginalColor == 0)
                {
                    fixDelete(x);
                }
            }

            // Balance the node after insertion
            public void fixInsert(Node k)
            {
                Node u;
                while (k.parent.color == 1)
                {
                    if (k.parent == k.parent.parent.right)
                    {
                        u = k.parent.parent.left;
                        if (u.color == 1)
                        {
                            u.color = 0;
                            k.parent.color = 0;
                            k.parent.parent.color = 1;
                            k = k.parent.parent;
                        }
                        else
                        {
                            if (k == k.parent.left)
                            {
                                k = k.parent;
                                rightRotate(k);
                            }
                            k.parent.color = 0;
                            k.parent.parent.color = 1;
                            leftRotate(k.parent.parent);
                        }
                    }
                    else
                    {
                        u = k.parent.parent.right;

                        if (u.color == 1)
                        {
                            u.color = 0;
                            k.parent.color = 0;
                            k.parent.parent.color = 1;
                            k = k.parent.parent;
                        }
                        else
                        {
                            if (k == k.parent.right)
                            {
                                k = k.parent;
                                leftRotate(k);
                            }
                            k.parent.color = 0;
                            k.parent.parent.color = 1;
                            rightRotate(k.parent.parent);
                        }
                    }
                    if (k == root)
                    {
                        break;
                    }
                }
                root.color = 0;
            }

            //Printing the Tree
            public void printHelper(Node root, String indent, bool last)
            {
                if (root != TNULL)
                {
                    Console.Write(indent);
                    if (last)
                    {
                        Console.Write("R----");
                        indent += "   ";
                    }
                    else
                    {
                        Console.Write("L----");
                        indent += "|  ";
                    }

                    String sColor = root.color == 1 ? "RED" : "BLACK";
                    Console.WriteLine(root.data + "(" + sColor + ")");
                    printHelper(root.left, indent, false);
                    printHelper(root.right, indent, true);
                }
            }

            public RedBlackTree()
            {
                TNULL = new Node();
                TNULL.color = 0;
                TNULL.left = null;
                TNULL.right = null;
                root = TNULL;
            }

            // PreOder Traversal
            public void preorder()
            {
                PreOder(this.root);
            }

            //InOder Traversal
            public void inorder()
            {
                InOrder(this.root);
            }

            //Post Oder Traversal
            public void postorder()
            {
                PostOrder(this.root);
            }

            //Searching in the tree
            public Node searchTree(int k)
            {
                return searchTreeHelper(this.root, k);
            }

            //Finding the minimum Node element
            public Node minimum(Node node)
            {
                while (node.left != TNULL)
                {
                    node = node.left;
                }
                return node;
            }

            //Finding the maximum Node element
            public Node maximum(Node node)
            {
                while (node.right != TNULL)
                {
                    node = node.right;
                }
                return node;
            }

            //Find the Successor of the element
            public Node successor(Node x)
            {
                if (x.right != TNULL)
                {
                    return minimum(x.right);
                }

                Node y = x.parent;
                while (y != TNULL && x == y.right)
                {
                    x = y;
                    y = y.parent;
                }
                return y;
            }

            //Finding the Predecessor of the element
            public Node predecessor(Node x)
            {
                if (x.left != TNULL)
                {
                    return maximum(x.left);
                }

                Node y = x.parent;
                while (y != TNULL && x == y.left)
                {
                    x = y;
                    y = y.parent;
                }

                return y;
            }

            //Left Rotation
            public void leftRotate(Node x)
            {
                Node y = x.right;
                x.right = y.left;
                if (y.left != TNULL)
                {
                    y.left.parent = x;
                }
                y.parent = x.parent;
                if (x.parent == null)
                {
                    this.root = y;
                }
                else if (x == x.parent.left)
                {
                    x.parent.left = y;
                }
                else
                {
                    x.parent.right = y;
                }
                y.left = x;
                x.parent = y;
            }

            //Right Rotation
            public void rightRotate(Node x)
            {
                Node y = x.left;
                x.left = y.right;
                if (y.right != TNULL)
                {
                    y.right.parent = x;
                }
                y.parent = x.parent;
                if (x.parent == null)
                {
                    this.root = y;
                }
                else if (x == x.parent.right)
                {
                    x.parent.right = y;
                }
                else
                {
                    x.parent.left = y;
                }
                y.right = x;
                x.parent = y;
            }

            //Inserting Key to Tree
            public void insert(int key)
            {
                Node node = new Node();
                node.parent = null;
                node.data = key;
                node.left = TNULL;
                node.right = TNULL;
                node.color = 1;

                Node y = null;
                Node x = this.root;

                while (x != TNULL)
                {
                    y = x;
                    if (node.data < x.data)
                    {
                        x = x.left;
                    }
                    else
                    {
                        x = x.right;
                    }
                }

                node.parent = y;
                if (y == null)
                {
                    root = node;
                }
                else if (node.data < y.data)
                {
                    y.left = node;
                }
                else
                {
                    y.right = node;
                }

                if (node.parent == null)
                {
                    node.color = 0;
                    return;
                }

                if (node.parent.parent == null)
                {
                    return;
                }

                fixInsert(node);
            }

            //Getting the Root element of the tree
            public Node getRoot()
            {
                return this.root;
            }

            //Delete Node
            public void deleteNode(int data)
            {
                deleteNodeHelper(this.root, data);
            }

            //Print the Tree
            public void printTree()
            {
                printHelper(this.root, " ", true);
            }
        }
    }
}
/*R----54(BLACK)
    L----38(BLACK)
    R----62(RED)
       L----58(BLACK)
       |  L----55(RED)
       R----73(BLACK)

After deleting:
Couldn't find key in the tree
 R----54(BLACK)
    L----38(BLACK)
    R----62(RED)
       L----58(BLACK)
       |  L----55(RED)
       R----73(BLACK)*/
