class LinkedList { 
    Node head; 
    class Node { 
        int data; 
        Node next; 
        Node(int d) 
        { 
            data = d; 
            next = null; 
        } 
    } 
  
    //Function to get the nth node from the last of a linked list
    void printNthFromLast(int n) 
    { 
        int len = 0; 
        Node temp = head; 
  
        // count the number of nodes in Linked List 
        while (temp != null) { 
            temp = temp.next; 
            len++; 
        } 
  
        // check if value of n is not more than length of the linked list 
        if (len < n) 
            return; 
  
        temp = head; 
  
        //get the (len-n+1)th node from the beginning 
        for (int i = 1; i < len - n + 1; i++) 
            temp = temp.next; 
  
        System.out.println(temp.data); 
    } 
  
    //Inserts a new Node at front of the list. 
    public void push(int new_data) 
    { 
       Node new_node = new Node(new_data);     /*Allocate the Node & Put in the data*/ 
  
       new_node.next = head;                  /* Make next of new Node as head */
  
        head = new_node;                       /* 4. Move the head to point to new Node */ 
    } 
  
    public static void main(String[] args) 
    { 
        LinkedList llist = new LinkedList(); 
        llist.push(20); 
        llist.push(4); 
        llist.push(15); 
        llist.push(35); 
  
        llist.printNthFromLast(4); 
    } 
} 
