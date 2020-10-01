class Stacks
{
    node TOS;

    static class node
    {
        int data;
        node next;

        node(int value)
        {
            data = value;
        }
    }

    public void Push(int value)
    {
        node new_node = new node(value);
        new_node.next = TOS;
        TOS = new_node;
    }

    public void Pop()
    {
        if(TOS == null)
            System.out.println("Stack is empty");
        else
        {
            TOS = TOS.next;
        }
    }

    public void Print_Stack()
    {
        if(TOS == null)
            System.out.println("Stack is empty");
        else
        {
            System.out.println("Top of stack is " + TOS.data);

            if(TOS.next != null)
            {
                System.out.print("Other elements are : ");
                node current;
                current = TOS.next;

                while(current != null)
                {
                    System.out.print(current.data + " ");
                    current = current.next;
                }

                System.out.println();
            }
        }
    }

    public static void main(String[] args)
    {
        Stacks Stack = new Stacks();

        for(int i = 0; i < 5; i++)
            Stack.Push(i);

        Stack.Print_Stack();

        for(int i = 0; i < 6; i++)
            Stack.Pop();

        Stack.Print_Stack();
    }
}


/* Output

Top of stack is 4
Other Elements are : 3 2 1 0
Stack is empty
Stack is empty

*/
