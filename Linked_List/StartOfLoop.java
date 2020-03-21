/*
* Find first node of a loop in a Linked List
* A linked list is reported to form a loop. We have to find the first element of the loop or cycle.
*
*/

import java.util.Scanner;

class StartOfLoop
{
    static Node head;
    static class Node
    {
        int data;
        Node next;
        Node(int d)
        {
            data = d;
            next = null;
        }
    }

    static void insert(int d)
    {
        Node n = new Node(d);
        if(head == null)
            head = n;
        else
        {
            Node current = head;
            while(current.next != null)
                current = current.next;
            current.next = n;
        }
    }
    
    static void createLoop(int p)
    {
        // For demonstration, we will link the last node with the element at position p.
        Node current = head, tail = head;
        while(tail.next != null)
            tail = tail.next;
        
        int count = 1;
        while(current.next != null && count < p)
	{   
	    count += 1;
	    current = current.next;
	}
	tail.next = current;
        // Now, linked list contains a loop.
    }
    
    static Node startOfLoop()
    {
        /* sp is a slow pointer(tortoise) that jumps one node at a time.
         *  fp is a fast pointer(hare) that jumps two nodes at a time.
         */
        Node sp = head, fp = head;
        while(sp != null &&  fp!= null && fp.next != null)
        {
            sp = sp.next;
            fp = fp.next.next;
            if(sp == fp)
                break;
        }
        fp = head; // Re-initialise the fast pointer to head and now, make both the pointers jump one node.

        while(fp != sp) // The node where the pointers meet is the start of the loop.
        {
            sp = sp.next;
            fp = fp.next;
        }
        return sp;
    }
    
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);

        System.out.println("Please enter no. of elements");    
        int size = scan.nextInt();

        System.out.println("Please enter " + size + " elements");
        for(int i = 0; i < size; i++)
            insert(scan.nextInt());
    
        System.out.println("Enter the position where loop should be created");
        int position = 0;
        while((position = scan.nextInt()) > size)
            System.out.println("Please enter position less than or equal to " + size);      
        
        createLoop(position); // to create a loop in the linked list at the given position

        System.out.println("The first element of the loop is: " + startOfLoop().data);
    }

}
    /*
    *    Sample Input
    *    n = 7
    *    position = 3
    *    list elements: 1, 2, 3, 4, 5, 6, 7
    */

    
    /*
    *    Sample Output
    *    The first element of the loop is: 3
    *    (as we arbritarily chose to link the 3rd node with the last node)
    */
