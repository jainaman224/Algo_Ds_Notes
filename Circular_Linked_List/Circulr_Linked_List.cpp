#include <iostream>

using namespace std;

struct node
{
	int data;
	node *next;
};

node *last;

/**** Create Circular Link List ****/
void create_node(int value)
{
    node *temp;
    temp = new node;
    temp->data = value;
    if (last == NULL)
    {
        last = temp;
        temp->next = last;   
    }
    else
    {
        temp->next = last->next; 
        last->next = temp;
        last = temp;
    }
}

/**** Insertion of element at a particular place ****/
void Insertion(int value, int pos)
{
    if (last == NULL)
        return;
 
    node *temp, *s;
    s = last->next;
    for (int i = 1; i < pos; i++)
    {
        s = s->next;
        if (s == last->next)
            return;
    }
    temp = new node;
    temp->next = s->next;
    temp->data = value;
    s->next = temp;
    
    if (s == last)    // Element inserted at the end
    { 
        last = temp;
    }
}


/**** Deletion of element from the list ****/
void Deletion(int value)
{
    struct node *temp, *s;
    s = last->next;
      
    if (last->next == last && last->data == value)          // One element is there 
    {
        temp = last;
        last = NULL;
        delete temp;
        return;
    }
    if (s->data == value)                           // First Element Deletion
    {
        temp = s;
        last->next = s->next;
        delete temp;
        return;
    }
    while (s->next != last)
    {
        if (s->next->data == value)              // Deletion in between of list 
        {
            temp = s->next;
            s->next = temp->next;
            delete temp;
            return;
        }
        s = s->next;
    }
    
    if (s->next->data == value)                 // Deletion of last element  
    {
        temp = s->next;
        s->next = last->next;
        delete temp;
        last = s;
        return;
    }
    cout << "Not found in the list" << endl;
}
 
 
/**** Search element in the list ****/
void Search(int value)
{
    node *s;
    int position = 0;
    s = last->next;
    while (s != last)
    {
        position++;
        if (s->data == value)    
        {
        	cout << "Found at :" << position << endl;
            return;
        }
        s = s->next;
    }
    if (s->data == value)    
    {
        position++;
		cout << "Found at :" << position << endl;             
        return;
    }
    cout << "Not found in the list" << endl;
}
 
/**** Print Circular Link List ****/
void Print()
{
    node *s;
    if (last == NULL)
      return;       // Empty list

    s = last->next;
    
    while (s != last)
    {
        cout<<s->data<<" -> ";
        s = s->next;
    }
    cout << s->data << endl;
}

int main()
{
	create_node(5);
	Print();     // 5
 	
	create_node(3);
	Print();     // 5 -> 3
    
	create_node(9);
	Print();     // 5 -> 3 -> 9
    
	Insertion(1, 2);
	Print();     // 5 -> 3 -> 1 -> 9
    
	Search(1);                    // Found at 3                    
	
	Search(4);                    // Not found in the list
	
	Deletion(1);
	Print();     // 5 -> 3 -> 9

	return 0;
}

