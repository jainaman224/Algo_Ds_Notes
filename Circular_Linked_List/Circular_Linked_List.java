import java.util.Scanner;

class node {
    int data;
    node next;
    
    node(int data, node next) {
        this.data = data;
        this.next = next;
    }
}

class cirLinkedList {
    node head;
    node tail;
    
    // function to prepend to the list as per README, i.e, to add a node in front of the head 
    void prepend(int num) {
        node temp = new node(num, null);
        
        // if the list is empty, the new node becomes the head (first element of the list)
        if (head == null) {
            head = temp;
            tail = head;
            tail.next = head;
        }
        
        // append new node before head, declare it as the new head
        else {
            temp.next = head;
            tail.next = temp;
            head = temp;
        }
    }
    
    // function to append to the list, i.e. to add a node after tail. 
    void append(int num) {
        node temp = new node(num, null);
        
        // if the list is empty, the new node becomes the head (first element of the list)
        if (head == null) {
            head = temp;
            tail = head;
            tail.next = head;
        }
        
        // append new node before head, declare it as the new tail
        else {
            temp.next = head;
            tail.next = temp;
            tail = temp;
        }
    }
      
    // function to insert a node after a node with value val.
    void insert_after_val(int num, int val) {
        node temp = new node(num, null);
        node pointer = head;
        
        // iterate through the list to find the node with value val
        while (pointer.next != head) { 
            if (pointer.data == val) {
                
                // if val is the value of the tail node, this operation is same as the append operation defined above.
                if (pointer.next == head) {
                    append(num);
                    return;
                }
                
                // add the new node between pointer and pointer.next
                temp.next = pointer.next;
                pointer.next = temp;
                return;
            }
            pointer = pointer.next;
        }
        System.out.println("the desired value is not present in the list");
    }
    
    // function that deletes the first element of the list
    void deleteHead() {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }
        
        // if there is only one element on the list, list becomes empty after this operation
        if (head.next == head) {
            head = null;
            tail = null;
            return;
        }
        
        // remove the node called head and make the next node a new head
        tail.next = head.next;
        head = head.next;  
    }
    
    // function to print all the element present on the list
    void displayList() {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }
        
        // print the first element
        System.out.print(head.data);
        node pointer = head.next;
        
        // iterate through the list until the first element appears again
        while (pointer != head) {
            System.out.print(" " + pointer.data);
            pointer = pointer.next;
        }
        System.out.println();
        return;
    }
}

public class Circular_Linked_List {
    public static void main(String[] args) {
        cirLinkedList cll = new cirLinkedList();
        Scanner input = new Scanner(System.in);
        System.out.println("Number of operations: ");
        int n = input.nextInt();
       
        // perform n operations
        while (n > 0) {
            n--;
            int t = input.nextInt();
            if (t == 1) {
                cll.append(input.nextInt());
            }
            if (t == 2) {
                cll.prepend(input.nextInt());
            }
            if (t == 3) {
                cll.insert_after_val(input.nextInt(), input.nextInt());
            }
            if  (t == 4) {
                cll.deleteHead();
            }
            if (t == 5) {
                cll.displayList();
            }
        }
    }
}

/* Sample Input/Output:
 * 
 * Type of operation: (first value of each line of input)
 * 1 = append. appends next integer input to the list
 * 2 = prepend. prepends next integer input to the list
 * 3 = insert after value. takes 2 input a and b and inserts a after b in the list assuming b is already on the list
 * 4 = delete head. deletes head
 * 5 = display list. prints list
 * 
 * Input:
 * 8
 * 1 5
 * 2 3
 * 5
 * 3 9 3
 * 1 7
 * 5
 * 4
 * 5
 * 
 * Output:
 * 3 5
 * 3 9 5 7
 * 9 5 7
 */
 
