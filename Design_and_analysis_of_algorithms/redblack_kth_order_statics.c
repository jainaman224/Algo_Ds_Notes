
//red black insert
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum tree_color {black=1,red=0};

struct node
{
	enum tree_color color;//1 for black and 0 for red
	
	int size;
	int value;
	struct node *left,*right,*parent; 
	
};
struct node *root;
struct node *nil;
void nils()
{
	nil=(struct node*)malloc(sizeof(struct node));
	nil->color=black;
	nil->left=NULL;
	nil->right=NULL;
	nil->parent=NULL;
	nil->value=-9999;
	nil->size=0;
	root=nil;
}

void print_tree(struct node* rt)
{
	if(rt==nil)
	{
		return;
	}
	char black[6]="black";
	char red[6]="red";
	
	print_tree(rt->left);
	char ch[6];
	if(rt->color)
	{
		strcpy(ch,black);
	}
	else
	{
		strcpy(ch,red);
	}
	printf("\n[color:%s, size:%d, value:%d]\n",ch,rt->size,rt->value);
	print_tree(rt->right);
}




void insert_fixup(struct node* me)
{

	struct node *parent=me->parent;
	
	if(parent==NULL)
	{
		me->color=black;
		//me->left=nil;
		//me->right=nil;
		//me->size=1;
		root=me;
		printf("\nI am the current root now with value %d\n",me->value);
		return;
	}
	if(parent->color==black)
	{
		return;
	}
	
	struct node *grandpa=parent->parent;
	if(grandpa==NULL)
	{
		printf("\ngrandpa is null\n");
		return;
	}
	
	struct node *uncle;
	
	if(parent->color==red)
	{
		printf("\nme is red and parent is also red\n");
	}
	
	if(grandpa->left==parent)
	{
		uncle=grandpa->right;
		
	}
	else if(grandpa->right==parent)
	{
		uncle=grandpa->left;
		
	}
	else
	{
		printf("\nuncle not found\n");
	}
	
	
	struct node *gr8_grandpa=grandpa->parent;
	int flag;
	if(gr8_grandpa==NULL)
	{
		flag=-1;
	}
	else if(gr8_grandpa->left==grandpa)
	{
		flag=1;
	}
	else if(gr8_grandpa->right==grandpa)
	{
		flag=0;
	}
	
	
	if(uncle->color==red)//case 1
	{
		printf("\nCase 1 is being executed\n");
		uncle->color = black;
		parent->color = black;
		grandpa->color = red;
		if(grandpa==root)
		{
			grandpa->color = black;
			return;
		}
		
		if(gr8_grandpa->color == red)
		{
			
			insert_fixup(grandpa);
		}
		else if(gr8_grandpa->color == black)
		{
			return;
		}
		else
		{
			printf("\ngreat grandpa not found\n");
		}
	}
	else//color of uncle of uncle is black or if uncle is nil
	{
		if((grandpa->left==parent)&&(parent->left==me))//left-left
		{
		
			printf("\nexecuting case left-left\n");
			grandpa->parent=parent;
			parent->parent=gr8_grandpa;
			grandpa->left=parent->right;
			parent->right=grandpa;
			parent->color=black;
			parent->size=grandpa->size;
			grandpa->size-=(me->size+1);
			grandpa->color=red;
			if(flag==1)
			{
				gr8_grandpa->left=parent;
			}
			else if(flag==0)
			{
				gr8_grandpa->right=parent;
			}
			if(parent->parent==NULL)
			{
				root=parent;
				printf("\nI am the current root now with value %d\n",parent->value);
			}
			
		}
		else if((grandpa->right==parent)&&(parent->right==me))//right-right
		{
			printf("\nexecuting case right-right\n");
			grandpa->parent=parent;
			parent->parent=gr8_grandpa;
			grandpa->right=parent->left;
			parent->left=grandpa;
			parent->color=black;
			parent->size=grandpa->size;
			grandpa->size-=(me->size+1);
			grandpa->color=red;
			if(flag==1)
			{
				gr8_grandpa->left=parent;
			}
			else if(flag==0)
			{
				gr8_grandpa->right=parent;
			}
			if(parent->parent==NULL)
			{
				root=parent;
				printf("\nI am the current root now with value %d\n",parent->value);
			}
			
			
		}
		else if((grandpa->left==parent)&&(parent->right==me))//left-right
		{
			printf("\nexecuting case left-right\n");
			me->parent=grandpa;
			parent->parent=me;
			parent->right=me->left;
			me->left=parent;
			me->size=parent->size;
			parent->size=((parent->left)->size)+((parent->right)->size)+1;
			
			printf("\nexecuting case left-left in left-right\n");
			grandpa->parent=me;//left-left
			me->parent=gr8_grandpa;
			grandpa->left=me->right;
			me->right=grandpa;
			me->color=black;
			me->size=grandpa->size;
			grandpa->size-=(parent->size+1);
			grandpa->color=red;
			if(flag==1)
			{
				gr8_grandpa->left=me;
			}
			else if(flag==0)
			{
				gr8_grandpa->right=me;
			}
			if(me->parent==NULL)
			{
				root=me;
				printf("\nI am the current root now with value %d\n",me->value);
			}
			
			
		}
		else if((grandpa->right==parent)&&(parent->left==me))//right-left
		{
			printf("\nexecuting case right-left\n");
			me->parent=grandpa;
			parent->parent=me;
			parent->left=me->right;
			me->right=parent;
			me->size=parent->size;
			parent->size=((parent->left)->size)+((parent->right)->size)+1;
			
			printf("\nexecuting case right-right in case right-left\n");
			grandpa->parent=me;//right-right
			me->parent=gr8_grandpa;
			grandpa->right=me->left;
			me->left=grandpa;
			me->color=black;
			me->size=grandpa->size;
			grandpa->size-=(parent->size+1);
			grandpa->color=red;
			if(flag==1)
			{
				gr8_grandpa->left=me;
			}
			else if(flag==0)
			{
				gr8_grandpa->right=me;
			}
			if(me->parent==NULL)
			{
				root=me;
				printf("\nI am the current root now with value %d\n",me->value);
			}
			
			
		}
		
	}
}




void insert()
{
	int val;
	printf("\nenter a integer value:\n");
	scanf("%d",&val);
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	new->value=val;
	new->color=red;
	new->left=nil;
	new->right=nil;
	new->size=1;
	new->parent=NULL;
	struct node *curr=NULL,*precurr=NULL;
	curr=root;
	while(curr!=nil)
	{
		precurr=curr;
		precurr->size++;
		if(val<curr->value)
		{
			
			curr=curr->left;
		}
		else
		{
			curr=curr->right;
		}
	}
	if(precurr==NULL)
	{
		insert_fixup(new);
		return;
	}
	if(val<precurr->value)
	{
		precurr->left=new;
		
	}
	else
	{
		precurr->right=new;
	}
	new->parent=precurr;
	insert_fixup(new);
	
}




int os_select(struct node* rt,int i)
{
	int k;
	struct node *x;
	x=rt;
	k=((x->left)->size)+1;
	if(i==k)
	{
		return x->value;
	}
	else if(i<k)
	{
		return os_select(x->left,i);
	}
	else
	{
		return os_select(x->right,i-k);
	}
	
}



void kth_largest()
{
	int k;
	printf("\nenter value of k for kth order statistics:\t");
	scanf("%d",&k);
	printf("\n%d largest element is %d\n",k,os_select(root,k));
	
}


int main()
{
	nils();//create nils
	int choice;
	while(1)
	{
		printf("\nMENU\n");
		printf("1. print tree elements in sorted order\n");
		printf("2. insert element\n");
		printf("3. get kth largest element\n");
		printf("4. quit\n");
		printf("Enter choices [1-4]:\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:print_tree(root);break;
			case 2:insert();break;
			case 3:kth_largest();break;
			case 4:exit(1);break;
		
		}
	}
	
	return 0;
}
