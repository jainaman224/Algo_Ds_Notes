/*
 * Author: Jennifer Tran
 * Last Updated: 21/10/2016
 *
 * NOTE: To make this code OOP friendly, place the Node and
 * LinkedList classes outside of the LinkedList_Bubble_Sort
 * class and remove the static.
 */

public class Linked_List_Bubble_Sort
{
  public static void main(String[] args)
  {
    LinkedList list = new LinkedList();

    // Adding integers unordered
    list.insertAtTop(14);
    list.insertAtTop(33);
    list.insertAtTop(27);
    list.insertAtTop(35);
    list.insertAtTop(10);

    // Prints the integers before sorting
    System.out.println("Before sorting: ");
    list.print();

    // Call BubbleSort method
    list.bubbleSort();
    System.out.println();

    // Prints out the integers after sorting
    System.out.println("After sorting: ");
    list.print();
  }

  static class Node
  {
    private int item;
    private Node next;

    // Constructor
    public Node (int newItem, Node newNode)
    {
      item = newItem;
      next = newNode;
    }

    // Getter's and Setters
    public int getItem()
    {
      return item;
    }

    public void setItem(int newItem)
    {
      item = newItem;
    }

    public Node getNext()
    {
      return next;
    }

    public void setNext(Node newNext)
    {
      next = newNext;
    }
  }

  static class LinkedList
  {
    private Node top;

    public LinkedList()
    {
      top = null;
    }

    public void insertAtTop(int value)
    {
      Node newNode = new Node(value,top);
      top = newNode;
    }

    public void print()
    {
      Node curr = top;
      while(curr != null)
      {
        System.out.print(curr.getItem() + " ");
        curr = curr.getNext();
      }

      System.out.println();
    }

    public void bubbleSort()
    {
      Node curr = top;
      Node prev = null;
      int temp = 0;

      while(curr.getNext() != null)
      {
        prev = top;
        while(prev.getNext() != null)
        {
          // If previous item is greater than current
          if(prev.getItem() > prev.getNext().getItem())
          {
            temp = prev.getItem();

            // Make the swap
            prev.setItem(prev.getNext().getItem());
            prev.getNext().setItem(temp);

          }
          prev = prev.getNext();
        }
        curr = curr.getNext();
      }
    }
  }
}

/*
OUTPUT:
Before sorting:
10 35 27 33 14

After sorting:
10 14 27 33 35
*/
