import java.util.*;
import java.lang.*;
import java.io.*;

class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}

class LinkedList
{
    public static Node merge(Node l1, Node l2)
    {
        Node head = null;
        if(l1 == null)
            return l2;
    
        if(l2 == null)
            return l1;
    

        if(l1.data<l2.data)
        {
            head=l1;
            l1.next = merge(l1.next,l2);
        }
        else
        {
            head=l2;
            l2.next = merge(l2.next, l1);
        }
    
        return head;
    }

    public static Node mergeSort(Node head) 
    {
    
        if(head == null || head.next == null)
            return head;
        
        Node ptr1 = head;
        Node ptr2 = head.next;
    
        while(ptr2 !=null && ptr2.next != null)
        {
            ptr1=ptr1.next;
            if(ptr2.next != null)
                ptr2=ptr2.next.next;
        }
    
        ptr2=ptr1.next;
        ptr1.next=null;
    
        return merge(mergeSort(head),mergeSort(ptr2));
    }

    public static void printList(Node head)
    {
        if(head == null)
           return;
           
        Node temp = head;
        while(temp != null)
        {
            System.out.print(temp.data + "-->");
            temp = temp.next;
        }
        System.out.print("NULL");
    }

    /*Sample Input
    1 - Test cases
    5 - Total number of elements to be inserted in linked list
    23 2 34 5 1 - Adding the contents of the linked list
    */


    public static void main (String[] args) 
    {
        Scanner sc= new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int n = sc.nextInt();
            Node head = new Node(sc.nextInt());
            Node tail = head;
            while(n-- > 1){
                tail.next = new Node(sc.nextInt());
                tail = tail.next;
            }
           
            head = mergeSort(head);
            printList(head);
        }
    }
}