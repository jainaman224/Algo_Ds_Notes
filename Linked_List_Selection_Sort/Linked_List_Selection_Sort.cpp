#include <bits/stdc++.h>
using namespace std;

struct node
{
	int value;
	node* next;
};

node *first, *temp;
void insert(int val);
void display();
void selectionSort();

void insert(int val)
{
	if (first == NULL)
	{
		first = new node();
		first -> value = val;
		first -> next = NULL;
	}
	else
	{
		temp = first;
		while (temp -> next)
		{
			temp = temp -> next;
		}
		temp -> next = new node();
		temp = temp -> next;
		temp -> value = val;
		temp -> next = NULL;
	}
}

void display()
{
	temp = first;
	while (temp)
	{
		cout << temp -> value << " ";
		temp = temp -> next;
	}
	cout << "\n";
}
void selectionSort()
{
	node *beg = first;
	node *minimum = first;

	while (beg -> next != NULL)
	{
		minimum = beg;
		node *current  = beg -> next;

		while (current)
		{
			if (current -> value < minimum -> value)
			{
				minimum = current;
			}
			current = current -> next;
		}

        int t = beg -> value;
        beg -> value = minimum -> value;
        minimum -> value = t;

		beg = beg -> next;
	}
}

int main()
{
	insert(1);
	insert(8);
	insert(5);
	insert(4);
	insert(9);
	insert(2);
	cout << "Before sorting : ";
	display();
	selectionSort();
	cout << "After Sorting : ";
	display();
	return 0;
}