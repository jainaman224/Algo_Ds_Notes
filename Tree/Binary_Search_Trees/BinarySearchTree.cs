using System;

namespace BinarySearchTree
{
        public class node
        {
            public int data;
            public node left;
            public node right;
            public node(int d)
            {
                data = d;
                left = null;
                right = null;
            }
        }

        class Program
        {
            node head;
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
                                return;
                            }
                        }
                        else
                        {
                            if (current.right != null)
                                current = current.right;
                            else
                            {
                                current.right = temp;
                                return;
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
                        Console.WriteLine("Element " + value + " Found");
                        return;
                    }
                }

                Console.WriteLine("Element " + value + " not Found");
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

            static void Main(string[] args)
            {
                Program x = new Program();

                x.Insert(5);
                x.Insert(7);
                x.Insert(9);
                x.Insert(8);
                x.Insert(6);
                x.Insert(4);

                x.Search(9);
                x.Search(2);

                x.Delete(7);
                x.Delete(5);
                x.Delete(4);

                x.Search(9);
                x.Search(2);
                x.Search(5);
                x.Search(6);
                Console.WriteLine();
                Console.ReadLine();
            }
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
