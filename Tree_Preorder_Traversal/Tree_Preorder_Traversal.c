#include <stdio.h>
#include <malloc.h>

typedef struct node
{
	int data;
	struct node *lptr, *rptr;
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

/*Function for PREORDER Transversal*/
void preorder(node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->data);
		preorder(root->lptr);
		preorder(root->rptr);
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

	printf("Pre Order Transversal: ");
	preorder(root);

	return 0;
}
