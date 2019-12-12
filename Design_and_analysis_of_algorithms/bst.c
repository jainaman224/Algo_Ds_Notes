//bst sort

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *left,*right;
};
struct node *root,*curr;
void BST_insert(int x)
{
	if(root==NULL)
	{
		root=(struct node*)malloc(sizeof(struct node));
    	root->value=x;
    	root->left=NULL;
    	root->right=NULL;
    	return;
	}
    struct node *z=root;
    struct node *temproot;
    int flag=0;
    while(z!=NULL)
    {
        if(z->value>x)
        {
            temproot=z;

            z=z->left;
            flag=1;

        }
        else
        {
            temproot=z;
            z=z->right;
            flag=2;
        }
    }
    z=(struct node*)malloc(sizeof(struct node));
    z->value=x;
    z->left=NULL;
    z->right=NULL;
    if(flag==1)
    {
        temproot->left=z;
    }
    else
    {
        temproot->right=z;
    }
}
void buildBST(int* a,int n)
{
    int i;
    
    for(i=0;i<n;i++)
    {
        BST_insert(a[i]);
    }
}
void inorder_tree_walk(struct node* rt)
{
    if(rt==NULL)
    {
        return;
    }
    inorder_tree_walk(rt->left);
    printf("%d\t",rt->value);
    inorder_tree_walk(rt->right);
}
int main()
{
    int *a;
   
    int choice,num,n,i;
	while(1)
	{
		printf("\nMENU\n");
		printf("1. print tree elements in sorted order\n");
		printf("2. insert an element\n");
		printf("3. insert few elements at a time\n");
		printf("4. quit\n");
		printf("Enter choices [1-4]:\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	inorder_tree_walk(root);break;
			case 2:	printf("enter integer to be inserted:\t");
					scanf("%d",&num);
					BST_insert(num);break;
					
			case 3:	printf("enter number of elements\t");
					scanf("%d",&n);
					a=(int*)malloc(sizeof(int)*n);
					printf("enter integers\n");
					for(i=0;i<n;i++)
					{
						scanf("%d",&a[i]);
					}
					buildBST(a,n);
					break;
					
			case 4:	exit(1);break;
		
		}
	}
	
	


    return 0;
}
