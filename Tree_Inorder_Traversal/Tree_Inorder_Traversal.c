#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *lptr,*rptr;
}node;

node *newnode(int data)
{
	node *newn;
	newn = (node*)malloc(sizeof(node));
	newn->data = data;
	newn->lptr = NULL;
	newn->rptr = NULL;
	return newn;
}

/*Function for INORDER Transversal*/
void inorder(node *root)
{
	if(root != NULL)
	{
		inorder(root->lptr);
		printf("%d ", root->data);
		inorder(root->rptr);
	}
}

int main()
{
	node *root;
	root = newnode(1);
	root->lptr = newnode(2);
	root->rptr = newnode(3);
	root->lptr->lptr = newnode(4);
	root->lptr->rptr = newnode(5);

	printf("In Order Transversal: ");
	inorder(root);

	return 0;
}
