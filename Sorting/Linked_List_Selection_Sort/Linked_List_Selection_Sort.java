/*Linked List implementation of Selection sort in java*/

public class selection_sort {
	node head;
	public static class node
	{
		int data;
		node next;

		node(int value)
		{
			data = value;
			next = null;
		}
	}

	public void selectionSort()
	{
		node beg=head;
		node min=head;
		while(beg.next!=null)
		{
			min=beg;
			node current=beg.next;

			while(current!=null)
			{
				if(current.data<min.data)
				{
					min=current;
				}
				current=current.next;
			}

			int temp = beg.data;
			beg.data = min.data;
			min.data = temp;

			beg=beg.next;
		}
	}

	public void create(int value)
	{
		node temp = new node(value);
		node current= head;

		if(head==null)
		{
			head=temp;
			return;
		}
		while(current.next!=null)
			current = current.next;

		current.next = temp;
	}

	public void display()
	{
		node current=head;
		if(current==null)
		{
			System.out.println("Empty list");
			return;
		}

		while(current.next!=null)
		{
			System.out.print(current.data+" -> ");
			current=current.next;
		}

		System.out.print(current.data);
		System.out.println();
	}

	public static void main(String[] args) {
		selection_sort ob=new selection_sort();
		ob.create(11);
		ob.create(5);
		ob.create(3);
		ob.create(6);
		ob.create(13);
		ob.create(10);
		System.out.println("Output:");
		ob.display();
		System.out.println("After selection sort : ");
		ob.selectionSort();
		ob.display();
	}
}

/*
Output:
11 -> 5 -> 3 -> 6 -> 13 -> 10
After selection sort :
3 -> 5 -> 6 -> 10 -> 11 -> 13
*/
