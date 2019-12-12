//bucket sort
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct node
{
	int value;
	struct node *next;
};
void printBucket(struct node* root)
{
	//printf("\nbucket is:\t");
	struct node *curr;
	for(curr=root;curr!=NULL;curr=curr->next)
	{
		printf("%d\t",curr->value);
	}
	//printf("\n");
}

int findmax(int* a,int n)
{
    int  max=a[0];
    int i;
    for(i=1;i<n;i++)
    {
        if(max<a[i])
        {
            max=a[i];
        }
    }
    return max;
}
void insert(struct node** rootaddr,int elem)
{
	struct node *curr,*new,*temp;
	new=(struct node*)malloc(sizeof(struct node));
	new->value=elem;
	if((*rootaddr)==NULL)
	{
		new->next=NULL;
		(*rootaddr)=new;
		//printf("hi\n");
		return;
	}
	if((*rootaddr)->value>elem)
	{
		temp=(*rootaddr);
		(*rootaddr)=new;
		new->next=temp;
		//printf("hii\n");
		return;
		
	}
	for(curr=(*rootaddr);curr->next!=NULL;curr=curr->next)
	{
		if((curr->next)->value>=elem)
			break;
	}
	
	temp=curr->next;
	curr->next=new;
	new->next=temp;
	//printf("hiii\n");
	
	
}
void bucketsort(int* arr,int n)
{
    int kk,ten;
    int i,j,count=0;

    int max=findmax(arr,n);
    for(kk=max,ten=1;kk>10;kk=kk/10)
    {
        count++;
        ten=ten*10;
    }
    int *a;
    //c=(int*)malloc(sizeof(int)*10);
    struct node** bucket=(struct node**)malloc(sizeof(struct node*)*10);
    for(i=0;i<10;i++)
    {
    	bucket[i]=NULL;
    }
    a=(int*)malloc(sizeof(int)*n);
    //b=(int*)malloc(sizeof(int)*n);
    //for(j=0;j<count;j++,ten=ten/10)
    //{
        for(i=0;i<n;i++)
        {
            a[i]=(arr[i]/ten)%10;
            //printf("%d\t",a[i]);

        }

      // printf("%d\n",k);

        /*for(i=0;i<10;i++)
        {
            c[i]=0;
        }*/
       // printf("111111\n");
        for(i=0;i<n;i++)
        {
            insert(&bucket[a[i]],arr[i]);
            //printf("bi\n");
        }
       // printf("2222222\n");
        /*for(i=1;i<10;i++)
        {
            c[i]+=c[i-1];
        }
       // printf("333333\n");
        for(i=n-1;i>=0;i--)
        {
            b[c[a[i]]-1],arr[i];
            //printf("%d\n",b[c[a[i]]]);
            c[a[i]]--;
        }
       // printf("444444\n");

    }*/
    for(i=0;i<10;i++)
    {
        printBucket(bucket[i]);
    }

}


int main()
{
    //int a[]={895,897,533,245,911,500};
    //int i;
    //int *b;
    int n;
    
    int i;
    //int *b;
    printf("enter no. of elements\n");
    scanf("%d",&n);
    int *a=(int*)malloc(sizeof(int)*n);
    printf("enter the integers to be sorted\n");
    
    for(i=0;i<n;i++)
    {
    	scanf("%d",&a[i]);
    }
    bucketsort(a,n);

    return 0;
}
