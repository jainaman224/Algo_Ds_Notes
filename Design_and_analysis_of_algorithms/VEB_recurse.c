//fixed universe successor
//van emde boas recursive

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#define SIZE 16 //please set size to be 2^(2^k), where ^ denotes power operator and k is +ve integer
struct widget
{
	int min;//min of this widget
	int max;//max of this widget
	bool ne; //non-empty bit for this widget, even final value (i.e) whether bit is present or not is also checked using this bit
	struct widget** clusters; //sub-widgets
	struct widget* ne_widget; //widget for non-empty bit array corresponding to each cluster 
	
	
};
//widget_root
struct widget *W;


//memory allocation for widget
void init_widget(struct widget **w,int size)
{
	//base case
	if(size <= 2)
	{
		(*w)=(struct widget*)malloc(sizeof(struct widget));
		(*w)->min=100000;
		(*w)->max=-1;
		(*w)->ne=false;
		(*w)->clusters=(struct widget**)malloc(2*sizeof(struct widget*));
		(*w)->clusters[0]=(struct widget*)malloc(sizeof(struct widget));
		(*w)->clusters[1]=(struct widget*)malloc(sizeof(struct widget));
		(*w)->ne_widget=(struct widget*)malloc(sizeof(struct widget));
		
		//w->clusters[0] & w->clusters[1] are base widgets, (i.e)their ne value will be used as final value (i.e) whether bit is present or not
		return;		
	}
	
	int sizei=(int)sqrt(size);
	int i;
	
	
	
	
	(*w)=(struct widget*)malloc(sizeof(struct widget));
	//printf("\nevaluated\n");
	(*w)->min=100000;
	(*w)->max=-1;
	(*w)->ne=false;
	(*w)->clusters=(struct widget**)malloc(sizeof(struct widget*)*sizei);
	//w->ne_widget=(struct widget*)malloc(sizeof(struct widget)*sizei);
	init_widget(&((*w)->ne_widget),sizei);
	for(i=0;i<sizei;i++)
	{
		init_widget(&((*w)->clusters[i]),sizei);
	}
	
}


void insert(struct widget** r,int size,int x)
{
	
	
	struct widget *w=(*r);
	//base case
	if(size<=2)
	{
		w->max=(x>(w->max))?x:(w->max);
		w->min=(x<(w->min))?x:(w->min);
		w->ne=true;
		(w->ne_widget)[0].ne=true;
		struct widget* base_node=w->clusters[x];
		base_node->ne=true;//since base node contain only one struct widget & no clusters, we require only it's ne value;
		return;
	}
	int sizei=(int)sqrt(size);
	//printf("\n**x***%d*****\n",x);
	int h_x=x/sizei;//high of x
	//printf("\n**h_x***%d*****\n",h_x);
	int l_x=x%sizei;//low of x
	//printf("\n**l_x***%d*****\n",l_x);
	
	w->max=(x>(w->max))?x:(w->max);
	//printf("\n**w->max***%d*****\n",w->max);
	w->min=(x<(w->min))?x:(w->min);
	//printf("\n**w->min***%d*****\n",w->min);
	w->ne=true;
	insert(&(w->clusters[h_x]),sizei,l_x);
	insert(&(w->ne_widget),sizei,h_x);
	
	
}
int successor(struct widget* w,int size,int x)
{
	//base case
	if(size<=2)
	{
		if(x==0&&(w->clusters[1])->ne)
		{
		    //printf("\nx:%d****(w->clusters[1])->ne:%d******\n",x,(w->clusters[1])->ne);
			return 1;
		}
		else
		{
			printf("\nunfortunately x has no successor\n");
			return -1;
		}
		
		
		
	}
	int sizei=(int)sqrt(size);
	int h_x=x/sizei;//high of x
	int l_x=x%sizei;//low of x
	if(x>=w->max)
	{
		//printf("\n**w->max***%d*****\n",w->max);
		printf("\nunfortunately x has no successor\n");
		return -1;
	}
	struct widget *cluste=w->clusters[h_x];
	int h_succ,l_succ;
	if(l_x<cluste->max)
	{
	
		h_succ=h_x;
		l_succ=successor(cluste,sizei,l_x);
		//printf("+++++++%d+++%d++++%d+++++++",h_succ,sizei,l_succ);
		if(l_succ==-1)
		{
			printf("\nunfortunately x has no successor\n");
			return -1;
		}
		
		return h_succ*sizei+l_succ;
		
	}
	else
	{
		h_succ=successor(w->ne_widget,sizei,h_x);
		if(h_succ==-1||h_succ>sizei)
		{
		    printf("\nunfortunately x has no successor\n");
			return -1;
		}
		l_succ=(w->clusters[h_succ])->min;
		return h_succ*sizei+l_succ;
		
	}
	return h_succ*sizei+l_succ;
	
}
int predecessor(struct widget* w,int size,int x)
{
	//base case
	if(size<=2)
	{
		if(x==1&&(w->clusters[0])->ne==true)
		{
			return 1;
		}
		else
		{
			printf("\nunfortunately x has no successor 1\n");
			return -1;
		}
		
		
		
	}
	int sizei=(int)sqrt(size);
	int h_x=x/sizei;//high of x
	int l_x=x%sizei;//low of x
	if(x<=w->min)
	{
		printf("\nunfortunately x has no successor 2\n");
		return -1;
	}
	struct widget *cluste=w->clusters[h_x];
	int h_pre,l_pre;
	if(l_x>cluste->min)
	{
		h_pre=h_x;
		l_pre=predecessor(cluste,sizei,l_x);
		if(l_pre==-1)
			return -1;
		
	}
	else
	{
		h_pre=successor(w->ne_widget,sizei,h_x);
		l_pre=(w->clusters[h_pre])->max;
		if(h_pre==-1)
			return -1;
		
	}
	return h_pre*sizei+l_pre;
	
}

int main()
{
	init_widget(&W,SIZE);
	int choice;
	int x,ans;
	//printf("\n***********%d***********\n",W->max);
	while(1)
	{
		printf("\nMENU\n");
		printf("1. Insert\n");
		printf("2. Successor Query\n");
		printf("3. Predessor Query\n");
		printf("4. exit\n");
		printf("Enter choices [1-4]\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	printf("Enter an integer to be inserted: ");
					scanf("%d",&x);
					insert(&W,SIZE,x);break;
					
			case 2: printf("Enter an integer whose successor is to be found: ");
					scanf("%d",&x);
					ans=successor(W,SIZE,x);
					printf("Successor of %d is %d",x,ans);break;
					
			case 3: printf("Enter an integer whose predecessor is to be found: ");
					scanf("%d",&x);
					ans=predecessor(W,SIZE,x);
					printf("Successor of %d is %d",x,ans);break;
					
			case 4:exit(1);break;
		}
		//printf("\n***********%d***********\n",W->ne);
		//printf("\n***********%d***********\n",((W->clusters[0])->ne));
		//printf("\n***********%d***********\n",(((W->clusters[0])->clusters[1])->ne));
	}
	
}
