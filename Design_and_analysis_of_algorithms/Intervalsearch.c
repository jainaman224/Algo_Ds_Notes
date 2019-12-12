
//red black insert
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max(x,y) x<y?y:x;
enum tree_color {black=1,red=0};

struct node
{
	enum tree_color color;//1 for black and 0 for red
	
	int max;
	int low,high;
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
	nil->low=0;
	nil->high=0;
	nil->max=0;
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
	printf("\n[color:%s, max:%d, low:%d, high:%d]\n",ch,rt->max,rt->low,rt->high);
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
		printf("\nI am the current root now with value %d\n",me->low);
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
			
			grandpa->max=max((grandpa->left)->max,(grandpa->right)->max);
			parent->max=max(me->max,grandpa->max);
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
				printf("\nI am the current root now with value %d\n",parent->low);
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
			grandpa->max=max((grandpa->left)->max,(grandpa->right)->max);
			parent->max=max(me->max,grandpa->max);

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
				printf("\nI am the current root now with value %d\n",parent->low);
			}
			
			
		}
		else if((grandpa->left==parent)&&(parent->right==me))//left-right
		{
			printf("\nexecuting case left-right\n");
			me->parent=grandpa;
			parent->parent=me;
			parent->right=me->left;
			me->left=parent;
			parent->max=max((parent->left)->max,(parent->right)->max);
			me->max=max(parent->max,(me->right)->max);
			
			printf("\nexecuting case left-left in left-right\n");
			grandpa->parent=me;//left-left
			me->parent=gr8_grandpa;
			grandpa->left=me->right;
			me->right=grandpa;
			me->color=black;
			grandpa->max=max((grandpa->left)->max,(grandpa->right)->max);
			me->max=max(parent->max,grandpa->max);

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
				printf("\nI am the current root now with value %d\n",me->low);
			}
			
			
		}
		else if((grandpa->right==parent)&&(parent->left==me))//right-left
		{
			printf("\nexecuting case right-left\n");
			me->parent=grandpa;
			parent->parent=me;
			parent->left=me->right;
			me->right=parent;
			
			parent->max=max((parent->left)->max,(parent->right)->max);
			me->max=max(parent->max,(me->left)->max);
			
			printf("\nexecuting case right-right in case right-left\n");
			grandpa->parent=me;//right-right
			me->parent=gr8_grandpa;
			grandpa->right=me->left;
			me->left=grandpa;
			me->color=black;
			grandpa->max=max((grandpa->left)->max,(grandpa->right)->max);
			me->max=max(parent->max,grandpa->max);

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
				printf("\nI am the current root now with value %d\n",me->low);
			}
			
			
		}
		
	}
}




void insert()
{
	int x,y;
	printf("\nenter interval [low(x) high(x)]\n");
	scanf("%d %d",&x,&y);
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	new->low=x;
	new->high=y;
	new->color=red;
	new->left=nil;
	new->right=nil;
	new->max=y;
	new->parent=NULL;
	struct node *curr=NULL,*precurr=NULL;
	curr=root;
	while(curr!=nil)
	{
		precurr=curr;
		precurr->max=max(y,precurr->max);
		if(x<curr->low)
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
	if(x<precurr->low)
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


void interval_search()
{
	int low_i,high_i;
	printf("\nEnter interval (i.e) 2 integers\n");
	scanf("%d %d",&low_i,&high_i);
	struct node *x;
	x=root;
	while((x!=nil)&&((low_i>x->high)||(high_i<x->low)))
	{
		if(low_i>=(x->left)->max)
		{
			x=x->right;
		}
		else
		{
			x=x->left;
		}
	}
	if(x==nil)
	{
		printf("No overlapping interval exists\n");
	}
	else
	{
		printf("[%d-%d] is overlapping interval\n",x->low,x->high);
	}
	
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
		printf("3. interval search\n");
		printf("4. quit\n");
		printf("Enter choices [1-4]:\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:print_tree(root);break;
			case 2:insert();break;
			case 3:interval_search();break;
			case 4:exit(1);break;
		
		}
	}
	
	return 0;
}
