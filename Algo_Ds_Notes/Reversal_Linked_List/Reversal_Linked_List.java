package LinkedLIst;

/**
 * Created by Last on 10/19/2016.
 */
public class Linked_List {
    public Node createLL(){
        Node head=null,tail=null;
        int x = 10; // you can take input here
        while(x != 100){
            Node newNode = new Node(x);
            if (head == null){
                head = newNode;
                tail = newNode;
            }
            else{
                tail.next = newNode;
                tail = newNode;
            }
            x+=10; // You can take input here
        }
        return head;
    }
    public Node reverseLL(Node head){
        Node prev = null;
        Node temp = head;
        while(temp!=null){
            Node next = temp.next;
            temp.next = prev;
            prev = temp;
            temp = next;
        }
        head = prev;
        return head;
    }
    public void printLL(Node head){
        Node temp = head;
        while (temp!=null){
            System.out.print(""+temp.data+" -> ");
            temp = temp.next;
        }
        System.out.println();
    }
    public static void main(String[] args) {
        Linked_List linked_list = new Linked_List();
        Node head = linked_list.createLL();
        linked_list.printLL(head);
        head = linked_list.reverseLL(head);
        linked_list.printLL(head);
    }

    static class Node{
        public Integer data;
        public Node next;
        public Node(int data){
            this.data = data;
            next = null;
        }
    }
}
//Output
//10 -> 20 -> 30 -> 40 -> 50 -> 60 -> 70 -> 80 -> 90 ->
//90 -> 80 -> 70 -> 60 -> 50 -> 40 -> 30 -> 20 -> 10 ->
