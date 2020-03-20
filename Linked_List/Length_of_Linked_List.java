import java.util.*;

/*
This code is written for Strings to store in LinkedList, if you want to store numericals or any other datatype,
just replace relevent data type in place of string in class Node.
*/

class Node
{
    String data;
    Node next;
    Node(String info)
    {
        data = info;
        next = null;
    }
}

class LinkedListLength
{
    Node head;
    public void pushing_data_to_LL(String new_data)
    {
        Node new_node = new Node(new_data); // Creating the node and assign the data.
        new_node.next = head; // making the next node as head node
        head = new_node; // making head to point to new Node
    }
    public int gettingLength()
    {
        Node temp = head;
        int count = 0;
        while(temp != null)
        {
            count++;
            temp = temp.next;
        }
        return count;
    }
}

class Mainer 
{
    public static void main(String[] args)
    {
        LinkedListLength thisList = new LinkedListLength();
        
        System.out.println("Currently the Length of the LinkedList is: " + thisList.gettingLength());
        
        thisList.pushing_data_to_LL("G");
        thisList.pushing_data_to_LL("S");
        thisList.pushing_data_to_LL("S");
        thisList.pushing_data_to_LL("O");
        thisList.pushing_data_to_LL("C");
        
        System.out.println("Currently the Length of the LinkedList is: " + thisList.gettingLength());
        
        thisList.pushing_data_to_LL("2");
        thisList.pushing_data_to_LL("0");
        thisList.pushing_data_to_LL("2");
        thisList.pushing_data_to_LL("0");
        
        System.out.println("Currently the Length of the LinkedList is: " + thisList.gettingLength());
    }
}

/*
TestCase-1:
Sample Input: G S S O C 2 0 2 0 
Sample Output: 9 //9 letters

TestCase-2:
Sample Input: O p e n - S o u r c e
Sample Output: 11 //11 letters
*/