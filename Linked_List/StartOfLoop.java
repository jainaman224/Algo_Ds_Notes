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
	
	static void createLoop()
	{
		// For demonstration, we will link the last node with the 3rd node of the linked list to create a loop.
		Node tail = head;
		while(tail.next != null)
			tail = tail.next;
		tail.next = head.next.next;
		// Now, linked list contains a loop.
		// We have linked 7 to 3 in our list 1, 2, 3, 4, 5, 6, 7
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
		int n = scan.nextInt();

		System.out.println("Please enter " + n + " elements");
		for(int i = 0; i < n; i++)
			insert(scan.nextInt());
		// Lets have 7 elements in our list 1, 2, 3, 4, 5, 6, 7
	
		createLoop(); // to create a loop in the linked list

		System.out.println("The first element of the loop is: " + startOfLoop().data);
	}

}
