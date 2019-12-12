//binary tree


#include<stdio.h>
#include<stdlib.h>
struct tree_node
{
    int value;
    struct tree_node *left,*right;
};

//queue
struct node
{
	struct tree_node* value;
	struct node *next;
};

struct node *top=NULL,*root=NULL,*curr=NULL;
void print()
{
	printf("Linked list is:\n");
	
	for(curr=root;curr!=NULL;curr=curr->next)
	{
		printf("%d\t",(curr->value)->value);
	}
	printf("\n");
}
void enqueue(struct tree_node* data)
{
	struct node* addr;
	
	addr=(struct node*)malloc(sizeof(struct node));
	
	
	if(root == NULL)
	{
		root=addr;
		top=root;
		root->value=data;
		root->next=NULL;
		
	}
	else
	{
		top->next=addr;
		top=addr;
		top->value=data;
		top->next=NULL;
		
	}
	
	
}
void dequeue()
{
	struct node* temp;
	temp=root;
	if(root == NULL)
	{
		printf("Ups!List is empty");
	}
	if(top == root)
	{
		top=root=NULL;
		
	}
	else	
	{
		root=root->next;
	}
	
	free(temp);
	
	
}
void isEmpty()
{
	if(root == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		printf("List is not empty\n");
	}
}










//Binary tree


struct tree_node *tree_root=NULL,*current=NULL;
struct tree_node* BT_insert(int x, struct tree_node *rt, int flag)
{
	if(tree_root==NULL)
	{
		tree_root=(struct tree_node*)malloc(sizeof(struct tree_node));
		tree_root->value=x;
		tree_root->left=NULL;
		tree_root->right=NULL;
		return tree_root;
	}
    struct tree_node *z=rt;
   
    
    z=(struct tree_node*)malloc(sizeof(struct tree_node));
    z->value=x;
    z->left=NULL;
    z->right=NULL;
    if(flag==1)
    {
        rt->left=z;
    }
    else
    {
        rt->right=z;
    }
    return z;
}
void buildBT(int* a,int n)
{
    int i;
    enqueue(BT_insert(a[0],NULL,0));
    //printf("\n*******\n");
    //print();
    //printf("\n******\n");
    for(i=1;i<n;i++)
    {
        enqueue(BT_insert(a[i],root->value,i%2));
        //printf("\n*******\n");
        //print();
        //printf("\n******\n");
        if(i%2==0)
        {
        	dequeue();
        }
        
    }
}



void inorder_tree_walk(struct tree_node* rt)
{
    if(rt==NULL)
    {
        return;
    }
    inorder_tree_walk(rt->left);
    printf("%d\t",rt->value);
    inorder_tree_walk(rt->right);
}
void preorder_tree_walk(struct tree_node* rt)
{
    if(rt==NULL)
    {
        return;
    }
    printf("%d\t",rt->value);
    preorder_tree_walk(rt->left);
    
    preorder_tree_walk(rt->right);
}

void postorder_tree_walk(struct tree_node* rt)
{
    if(rt==NULL)
    {
        return;
    }
    
    postorder_tree_walk(rt->left);
    
    postorder_tree_walk(rt->right);
    printf("%d\t",rt->value);
}






int LCA(int a,int b,int *arr,int n)
{
	int ar[n],br[n];
	int indexa,indexb,i,j;
	int sizear,sizebr;
	for(i=0;i<n;i++)
	{
		if(a==arr[i])
		{
			indexa=i;
		}
		if(b==arr[i])
		{
			indexb=i;
		}
	}
	for(sizear=0;indexa>0;sizear++)
	{
		ar[sizear]=arr[indexa];
		indexa=(indexa-1)/2;
	}
	for(sizebr=0;indexb>0;sizebr++)
	{
		br[sizebr]=arr[indexb];
		indexb=(indexb-1)/2;
	}
	for(i=0;i<sizear;i++)
	{
		for(j=0;j<sizebr;j++)
		{
			if(ar[i]==br[j])
			{
				return ar[i];
			}
		}
	}
	return arr[0];
	
}








int main()
{
	/*int choice;
	while(1)
	{
		printf("Menu\n");
		printf("1. EnQueue\n");
		printf("2. DeQueue\n");
		printf("3. IsEmpty\n");
		printf("4. print queue\n");
		printf("5. Exit\n");
		printf("Enter choices [1-5]:\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: enqueue();break;
			case 2: dequeue();break;
			case 3: isEmpty();break;
			case 4: print();break;
			case 5: exit(1);
		}
	}*/
	int n,i,a,b,lca;
	int *arr;
	printf("enter no. of elements in binary tree\n");
	scanf("%d",&n);
	arr=(int *)malloc(sizeof(int)*n);
	printf("enter elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	buildBT(arr,n);
	printf("\nIn-order traversal:\n");
	inorder_tree_walk(tree_root);
	printf("\npre-order traversal:\n");
	preorder_tree_walk(tree_root);
	printf("\npost-order traversal:\n");
	postorder_tree_walk(tree_root);
	printf("\nenter 2 integer whose LCA is to be found\t");
	scanf("%d %d",&a,&b);
	lca=LCA(a,b,arr,n);
	printf("\nLCA value is %d\n",lca);
	
}



























