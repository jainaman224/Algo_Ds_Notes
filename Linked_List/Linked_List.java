class Linked_List
{
    node head;

    static class node
    {
        int data;
        node next;

        // Constructor
        node(int d)
        {
            data = d;
            next = null;
        }
    }

    public boolean Is_List_Empty()
    {
        if(head == null)
            return true;

        return false;
    }

    public void Insert_At_Beginning(int value)
    {
        node temp = new node(value);
        temp.next = head;
        head = temp;
    }

    public void Insert_At_End(int value)
    {
        node temp = new node(value), current = head;
        // temp.next = null;

        if(Is_List_Empty())
        {
            head = temp;
            return ;
        }

        while(current.next != null)
            current = current.next;

        current.next = temp;
    }

    public void Insert_After_Value(int desired, int value)
    {
        node current = head;

        while(current != null && current.data != desired)
            current = current.next;

        if(current == null)
            System.out.println("Element " + desired + " is not in list");
        else
        {
            node temp = new node(value);
            temp.next = current.next;
            current.next = temp;
        }
    }

    public void Delete_At_Beginning()
    {
        if(Is_List_Empty())
            System.out.println("List is empty");
        else
        {
            node temp = head;
            head = head.next;
            temp.next = null;
        }
    }

    public void Delete_At_End()
    {
        if(Is_List_Empty())
        {
            System.out.println("List is empty");
            return ;
        }

        node temp = head, prev = null;

        if(head.next == null)
        {
            head = null;
            temp.next = null;
            return ;
        }

        while(temp.next != null)
        {
            prev = temp;
            temp = temp.next;
        }

        prev.next = temp.next;
        temp.next = null;
    }

    public void Delete_With_Value(int desired)
    {
        if(Is_List_Empty())
        {
            System.out.println("List is empty");
            return ;
        }

        node temp = head, prev = null;

        if(head.data == desired)
        {
            head = head.next;
            temp.next = null;
            return ;
        }

        while(temp != null && temp.data != desired)
        {
            prev = temp;
            temp = temp.next;
        }

        if(temp == null)
            System.out.println("Element " + desired + " is not in list");
        else
        {
            prev.next = temp.next;
            temp.next = null;
        }
    }

    public void Search(int desired)
    {
        node temp = head;

        while(temp != null && temp.data != desired)
            temp = temp.next;

        if(temp == null)
            System.out.println("Element " + desired + " not found");
        else
            System.out.println("Element " + desired + " is present in list");
    }

    public void Print_Linked_List()
    {
        if(Is_List_Empty())
        {
            System.out.println("List is empty");
            return ;
        }

        node current = head;

        while(current.next != null)
        {
            System.out.print(current.data + " -> ");
            current = current.next;
        }

        System.out.println(current.data);
    }

    public void Get_Length_Iterative()
    {
        int elementCounter = 0;
        node current = head;

        while (current != null)
        {
            elementCounter++;
            current = current.next;
        }

        System.out.println("Current Length: " + elementCounter);
    }

    public void Get_Length_Recursive()
    {
        System.out.println("Current Length: " + Count_Recursive(head));
    }

    public int Count_Recursive(node currNode)
    {
        if (currNode == null)
            return 0;
        else
            return Count_Recursive(currNode.next) + 1;
    }

    public static void main(String[] args)
    {
        Linked_List LinkedList = new Linked_List();

        int i;

        for(i = 0; i < 5; i++)
            LinkedList.Insert_At_Beginning(i);



        LinkedList.Print_Linked_List();
        LinkedList.Get_Length_Iterative();

        for(i = 5; i < 10; i++)
            LinkedList.Insert_At_End(i);

        LinkedList.Print_Linked_List();
        LinkedList.Get_Length_Recursive();

        LinkedList.Insert_After_Value(5, 9);
        LinkedList.Insert_After_Value(10, 9);

        LinkedList.Print_Linked_List();
        LinkedList.Get_Length_Iterative();

        for(i = 0; i < 3; i++)
            LinkedList.Delete_At_End();

        LinkedList.Print_Linked_List();
        LinkedList.Get_Length_Recursive();

        for(i = 0; i < 3; i++)
            LinkedList.Delete_At_Beginning();

        LinkedList.Print_Linked_List();
        LinkedList.Get_Length_Iterative();

        LinkedList.Delete_With_Value(1);
        LinkedList.Delete_With_Value(5);

        LinkedList.Print_Linked_List();
        LinkedList.Get_Length_Recursive();

        LinkedList.Search(6);
        LinkedList.Search(8);
    }
}

/*  Output
    4 -> 3 -> 2 -> 1 -> 0
    Current Length: 5
    4 -> 3 -> 2 -> 1 -> 0 -> 5 -> 6 -> 7 -> 8 -> 9
    Current Length: 10
    Element 10 is not in list
    4 -> 3 -> 2 -> 1 -> 0 -> 5 -> 9 -> 6 -> 7 -> 8 -> 9
    Current Length: 11
    4 -> 3 -> 2 -> 1 -> 0 -> 5 -> 9 -> 6
    Current Length: 8
    1 -> 0 -> 5 -> 9 -> 6
    Current Length: 5
    0 -> 9 -> 6
    Current Length: 3
    Element 6 is present in list
    Element 8 not found
*/
