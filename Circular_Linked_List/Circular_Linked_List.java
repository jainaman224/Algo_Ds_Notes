class node{
    int data;
    node next;
    
    node(int data, node next){
        this.data=data;
        this.next=next;
    }
}

class cirLinkedList{
    node head;
    node tail; //tail is the node that points to the head. created to complete some operations like append in O(1) instead of O(n).
    
    
    //function to prepend to the list as per README, i.e, to add a node in front of the head 
    void prepend(int num) {
        //create a new node
        node temp=new node(num, null);
        
        //if the list is empty, the new node becomes the head (first element of the list)
        if (head==null) {
            head=temp;
            tail=head;
            tail.next=head;
        }
        //append new node before head, declare it as the new head
        else {
            temp.next=head;
            tail.next=temp;
            head=temp;
        }
    }
    
    
    //function to append to the list, i.e. to add a node after tail. the only difference between append and prepend
    //is that after append new node becomes the tail whereas after prepend new node becomes the head.
    void append(int num) {
        node temp=new node(num, null);
        
        //if the list is empty, the new node becomes the head (first element of the list)
        if (head==null) {
            head=temp;
            tail=head;
            tail.next=head;
        }
        //append new node before head, declare it as the new tail
        else {
            temp.next=head;
            tail.next=temp;
            tail=temp;
        }
    }
    
    
    //function to insert a node after a node with value val.
    void insert_after_val(int num, int val) {
        node temp=new node(num,null);
        node pointer=head;
        //iterate through the list to find the node with value val
        while (pointer.next!=head) {
            
            if (pointer.data==val) {
                //if val is the value of the tail node, this operation is same as the append operation defined above.
                if (pointer.next==head) {
                    append(num);
                    return;
                }
                //add the new node between pointer and pointer.next
                temp.next=pointer.next;
                pointer.next=temp;
                return;
            }
            pointer=pointer.next;
        }
        System.out.println("the desired value is not present in the list");
    }
    
    
    //function that deletes the first element of the list
    void deleteHead() {
        
        if (head==null) {
            System.out.println("List is empty");
            return;
        }
        
        //if there is only one element on the list, list becomes empty after this operation
        if (head.next==head) {
            head=null;
            tail=null;
            return;
        }
        //remove the node called head and make the next node a new head
        tail.next=head.next;
        head=head.next;
        
    }
    
    //function to print all the element present on the list
    void displayList() {
        if (head==null) {
            System.out.println("list is empty");
            return;
        }
        //print the first element
        System.out.print(head.data);
        node pointer=head.next;
        
        //iterate through the list until the first element appears again
        while(pointer!=head) {
            System.out.print(" "+pointer.data);
            pointer=pointer.next;
        }
        System.out.println();
        return;
    }
}

public class Circular_Linked_List {

    public static void main(String[] args) {
    
        cirLinkedList cll=new cirLinkedList();
        cll.append(2);  // 2
        cll.append(9);  // 2 -> 9
        cll.prepend(1);  // 1 -> 2 -> 9
        cll.insert_after_val(11, 2);  // 1 -> 2 -> 11 -> 9
        cll.displayList();
        cll.deleteHead();  // 2 -> 11 -> 9
        cll.displayList();
        
    }

}
