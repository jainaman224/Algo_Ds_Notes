class LinkedList 
{ 
    Node head=null;
    // Linked list Node
    class Node 
    { 
        int data; 
        Node next; 
        Node(int val) 
        {
            data = val;
            next = null;
        } 
    } 

    // Funtion to insert a node in Linked List
    public void insert(int val) 
    { 
        Node temp = new Node(val);
        temp.next = head;
        head = temp; 
    } 
    
    // Function to detect a cycle in Linked List
    boolean detectCycle() 
    { 
        Node slow_ptr = head;
        Node fast_ptr = head; 
        while (fast_ptr && fast_ptr.next)
        { 
            slow_ptr = slow_ptr.next; 
            fast_ptr = fast_ptr.next.next; 
            if (slow_ptr == fast_ptr) {
                return true; 
            } 
        } 
        return false; 
    } 
  
    // Main method
    public static void main(String args[]) 
    { 
        LinkedList list = new LinkedList(); 
        int values[]={10,20,30,40};
        int n=values.length;
        for(int i= n-1; i>=0; i--)
            list.insert(values[i]);

        // Creating a loop
        list.head.next.next.next.next = list.head.next; 
        if(list.detectCycle())
		System.out.println("Cycle found");
        else
		System.out.println("No cycle found");
    }
}  
