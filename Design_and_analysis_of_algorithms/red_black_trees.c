//red-black trees
//insertion
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum rb {black = 1, red = 0};
struct node
{	
	enum rb color;
	int value;
	struct node *parent,*left,*right;
};
struct node *nil;//leaf node
struct node *root=NULL;
void init_nil()
{
	nil=(struct node*)malloc(sizeof(struct node));
	nil->color=black;
	
}
void rotate_left(struct node* papa)
{
	struct node* grandpa=papa->parent;
	struct node* me=papa->right;
	papa->parent=me;
	papa->right=me->left;
	me->left=papa;
	me->color=black;
	papa->color=red;
	if(grandpa==NULL)
	{		
		me->parent=NULL;
		printf("root changed\n");
		root=me;
		
	}
	else if(grandpa->left==papa)
	{
		
		me->parent=grandpa;
		grandpa->left=me;
	}
	else if(grandpa->right==papa)
	{
		me->parent=grandpa;
		grandpa->right=me;
	}
	else
	{
		printf("\nOops!something went wrong in rotate-left\n");
	}
	
}
void rotate_right(struct node* papa)
{
	struct node* grandpa=papa->parent;
	struct node* me=papa->left;
	papa->parent=me;
	papa->left=me->right;
	me->right=papa;
	me->color=black;
	papa->color=red;
	if(grandpa==NULL)
	{		
		me->parent=NULL;
		printf("root changed\n");
		root=me;
	}
	else if(grandpa->left==papa)
	{
		
		me->parent=grandpa;
		grandpa->left=me;
	}
	else if(grandpa->right==papa)
	{
		me->parent=grandpa;
		grandpa->right=me;
	}
	else
	{
		printf("\nOops!something went wrong in rotate-right\n");
	}
	
}


void rb_fixup(struct node* me)
{
	struct node* papa=me->parent;
	if(papa==NULL)
	{
		printf("root changed\n");
		me->color=black;
		root=me;
		return;
	}
	if(papa->color==black)
	{
		printf("parent was already black,so I took peace\n");
		return;
	}
	struct node* grandpa=papa->parent;
	if(grandpa==NULL)
	{
		printf("\nOops!Something went wrong in rb_fixup\n");
		return;
	}
	struct node* uncle;
	if(grandpa->left==papa)
	{
		
		uncle=grandpa->right;
	}
	else
	{
		uncle=grandpa->left;
	}
	if(uncle==NULL)
	{
		printf("error++\n");
		return;
	}
	if(uncle->color==red)
	{
		printf("uncle is red\n");
		grandpa->color=red;
		papa->color=black;
		uncle->color=black;
		rb_fixup(grandpa);
	}
	else
	{
		
		if(grandpa->left==papa && papa->left==me)//left-left
		{
			printf("left-left\n");
			rotate_right(grandpa);
			return;
		}
		if(grandpa->right==papa && papa->right==me)//right-right
		{
			printf("right-right\n");
			rotate_left(grandpa);
			return;
		}
		if(grandpa->left==papa && papa->right==me)//left-right
		{
			printf("left-right\n");
			rotate_left(papa);
			rotate_right(grandpa);
			return;
		}
		if(grandpa->right==papa && papa->left==me)//right-left
		{
			printf("right-left\n");
			rotate_right(papa);
			rotate_left(grandpa);
			return;
		
		}
	}
}
void rb_insert(int value)
{
	struct node *new=(struct node*)malloc(sizeof(struct node));
	new->value=value;
	new->parent=NULL;
	new->left=nil;
	new->right=nil;
	new->color=red;
	struct node *curr,*prev;
	if(root==NULL)
	{
		root=new;
		rb_fixup(new);
		return;
	}
	for(curr=root;curr!=nil;)
	{
		
		prev=curr;
		if(value>curr->value)
		{
			
			curr=curr->right;
			
		}
		else
		{
			
			curr=curr->left;
			
		}
	}
	new->parent=prev;
	if(prev->value>value)
	{
		prev->left=new;
		
	}
	else
	{
		prev->right=new;
	}
	rb_fixup(new);
	
}
void in_order_traversal(struct node* sub_root)
{
	if(sub_root==nil)
	{
		return;
	}
	in_order_traversal(sub_root->left);
	char a[6];
	char black_str[]="black";
	char red_str[]="red";
	if(sub_root->color==black)
	{
		strcpy(a,black_str);
	}
	else
	{
		strcpy(a,red_str);
	}
	printf("\nvalue:%d color:%s\n",sub_root->value,a);
	in_order_traversal(sub_root->right);
	
}
int main()
{
	init_nil();
	int choice;
	int val;
	while(1)
	{
		printf("\nMENU\n");
		printf("1.insert\n");
		printf("2.print\n");
		printf("3.exit\n");
		printf("enter choices [1-3]\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("enter value to be inserted: ");
					scanf("%d",&val);
					rb_insert(val);break;
			case 2:in_order_traversal(root);break;
			case 3:exit(1);break;
		}
		
		
	}
	return 0;
}
































