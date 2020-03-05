import java.util.Scanner;

class Doubly_Linked_List {

    int size;
    Node head;
    Node tail;

    class Node {
        int data;
        Node next;
        Node prev;

        Node(int d) {
            data = d;
        }
    }

    // Adding an element at the beginning of the list
    void addFirst(int d) {

        // If head will be null new node is created and assigned to head
        if (head == null) {
            Node n = new Node(d);
            head = n;
            tail = n;
            size = size + 1;
        } else {
            Node n = new Node(d);
            head.prev = n;
            n.next = head;
            head = n;
            size = size + 1;
        }
    }

    // Adding an element at the last of the list
    void addLast(int d) {
        if (head == null) {
            Node n = new Node(d);
            head = n;
            tail = n;
            size = size + 1;
        } else {
            Node n = new Node(d);
            tail.next = n;
            n.prev = tail;
            tail = n;
            size = size + 1;
        }
    }

    // Adding an element at the index given by the user
    void addAt(int d, int idx) {
        try {
            if (idx > size) {
                throw new ArrayIndexOutOfBoundsException();
            } else if (idx == 0) {
                if (head == null) {
                    Node n = new Node(d);
                    head = n;
                    tail = n;
                    size = size + 1;
                } else {
                    Node n = new Node(d);
                    head.prev = n;
                    n.next = head;
                    head = n;
                    size = size + 1;
                }
            } else if (idx == size) {
                Node n = new Node(d);
                tail.next = n;
                n.prev = tail;
                tail = n;
                size = size + 1;
            } else {
                Node temp = head;
                for (int i = 0; i < idx - 1; i++) {
                    temp = temp.next;
                }
                Node n = new Node(d);
                n.next = temp.next;
                n.prev = temp;
                temp.next.prev = n;
                temp.next = n;
                size = size + 1;
            }
        } catch (Exception e) {
            System.out.println("Index out of Bounds");
        }
    }

    // Removes the first element of list
    void removeFirst() {

        // If the list is empty i.e head is null no element can be removed
        if (head == null) {
            System.out.println("List is Empty");
        } else if (size == 1) {
            head = null;
            tail = null;
            size = size - 1;
        } else {
            Node temp = head.next;
            temp.prev = null;
            head = temp;
            size = size - 1;
        }
    }

    // Removes the last element of the list
    void removeLast() {

        // If there are no elements in the list i.e head is null no element will be removed
        if (head == null) {
            System.out.println("List is Empty");
        } else if (size == 1) {
            head = null;
            tail = null;
            size = size - 1;
        } else {
            Node temp = tail.prev;
            temp.next = null;
            tail = temp;
            size = size - 1;
        }
    }

    // Removes at a given index given by the user
    void removeAt(int idx) {
        if (idx > size) {
            System.out.println("Index Out Of Bounds");
        } else if (idx == 0) {
            if (size == 1) {
                head = null;
                tail = null;
                size = size - 1;
            } else {
                Node temp = head.next;
                temp.prev = null;
                head = temp;
                size = size - 1;
            }
        } else if (idx == size - 1) {
            Node temp = tail.prev;
            temp.next = null;
            tail = temp;
            size = size - 1;
        } else {
            Node temp = head;
            for (int i = 0; i < idx - 1; i++) {
                temp = temp.next;
            }
            temp.next = temp.next.next;
            Node t = temp;
            temp = temp.next;
            temp.prev = t;
            size = size - 1;
        }
    }

    void display() {
        Node temp = head;

        // Traverse over the doubly linked list and print the elements

        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        doublyLL lst = new doublyLL();
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        while (n != 0) {
            System.out.println("1: Add Last");
            System.out.println("2: Add First");
            System.out.println("3: Add At");
            System.out.println("4: Remove Last");
            System.out.println("5: Remove First");
            System.out.println("6: Remove At");
            System.out.println("7: Display"); 
            int c = scn.nextInt();
            switch (c) {
            case 1:
                System.out.println("Enter Value");
                int num = scn.nextInt();
                lst.addLast(num);
                break;
            case 2:
                System.out.println("Enter Value");
                int num1 = scn.nextInt();
                lst.addFirst(num1);
                break;
            case 3:
                System.out.println("Enter Index");
                int idx = scn.nextInt();
                System.out.println("Enter Value");
                int num3 = scn.nextInt();
                lst.addAt(num3, idx);
                break;
            case 4:
                lst.removeLast();
                break;
            case 5:
                lst.removeFirst();
                break;
            case 6:
                System.out.println("Enter Index");
                int idx1 = scn.nextInt();
                lst.removeAt(idx1);
                break;
            case 7:
                lst.display();
                break;
            default:
                System.out.println("Invalid");
            }
            System.out.println("Enter 0 to quit and 1 to continue");
            int no = scn.nextInt();
            n = no;
        }

    }

}

/*
    * Sample Input 1: lst.addFirst(10)
    *lst.addLast(30) 
    *lst.addAt(20,1);
    * lst.display(); => 10, 20, 30 
    *lst.removeFirst(); 
    *lst.removeLast();
    * lst.display(); => 20
*/
