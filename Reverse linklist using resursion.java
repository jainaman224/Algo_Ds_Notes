public class ReverseLinkedList {
public static void main(String[] args) {
	LinkedList li=new LinkedList();
	li.InsertData(5);
	li.InsertData(55);
	li.InsertData(555);
	li.InsertData(5555);
	Node head=li.head;
	reverse(head);
}
public static void reverse(Node head)
{
	if(head==null)
		return;
	
	reverse(head.next);
	System.out.println(head.val);
	
}
}
