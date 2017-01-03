#include <stdio.h>
#include <malloc.h>

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

/*Function for POSTORDER Transversal*/
void postorder(node *root)
{
	if(root != NULL)
	{
		postorder(root->lptr);
		postorder(root->rptr);
		printf("%d ", root->data);
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

	printf("Post Order Transversal: ");
	postorder(root);

	return 0;
}
