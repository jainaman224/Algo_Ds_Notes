#include<iostream>
#include<conio.h>
using namespace std;

struct node
{
  int info;
  node *next;
};
node *create (int x) //creating a new node
{
  node *p = new node;
  p->info = x;
  p->next = NULL;
  return p;

}

void print (node * ptr) //printing the linked list
{
  while (ptr != NULL)
    {
      cout << ptr->info << " ";
      ptr = ptr->next;
    }
  cout << "\n\n";
}

void rem (node * slow, node * head) //removing the cycle from the linked list
{
  node *ptr;
  node *temp;
  ptr = head;
  while (1)
    {
      temp = slow;
      while (temp->next != slow && temp->next != ptr)
	{
	  temp = temp->next;
	}
      if (temp->next == ptr)
	break;
      ptr = ptr->next;
    }
  temp->next = NULL;

}

int detect (node * ptr) //detecting cycle in the linked list
{

  node *slow = ptr;
  node *fast = ptr;
  while (slow && fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
	{
	  rem (slow, ptr); //remove function called
	  return 1;
	}
    }
  return 0;
}

int main ()
{
  node *head = create (10);
  head->next = create (20);
  head->next->next = create (30);
  head->next->next->next = head;

  if (detect (head) == 1) //detec function called
    {
      cout << "\nA cycle is present in the linked list\n";
      cout << "\n\nAfter removing the cycle, linked list is as follows:\n";
      print (head);
    }
  else
    cout << "No cycle is present within the loop\n";

  return 0;
}

/* Sample input :HARDCORED VALUES:
  10->20->30->(attached to head)

   Sample output:
   A cycle is present in the linked list

   After removing the cycle, linked list is as follows:
   10 20 30
/*




