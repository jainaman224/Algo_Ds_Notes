#include <stdio.h>
#include <stdlib.h>

typedef struct bucket{
	double value;					// structure for maintaining buckets
	struct bucket *next;
}b;

b* create_node(double p){
    	b *x;
	x=(b *)malloc(sizeof(b));		//create a new node for inserting new input into the bucket
	x->value=p;
	x->next=NULL;
	return x;
}
	
void sort(b *p,int n){
    	int i=0,j;
    	double *a,key;
    	b *current;
    	current=(b*)malloc(sizeof(b));
    	current=p;
    	a=(double *)malloc(n*sizeof(double));
    	while(current!=NULL){
		a[i]=current->value;
        	current=current->next;					//sorting the values in a bucket using insertion sort
       		i++;
    	}
	for(i=1;i<n;i++){
        	key=a[i];
        	j=i-1;
        	while(j>=0 && a[j]>key){
            		a[j+1]=a[j];
            		j=j-1;
		}
        	a[j+1]=key;
    	}
   	current=p;
	i=0;
    	while(current !=NULL){
        	current->value=a[i];
        	current=current->next;
        	i++;
   	}
}


void Bucket_sort(double a[],int n){
	b **head;
	b **tail;
	b *current;
	int i,p;
	int count[10]={0};
	head=(b **)malloc(10*sizeof(b));
	tail=(b **)malloc(10*sizeof(b));
	for(i=0;i<10;i++){
		head[i]=NULL;
		tail[i]=NULL;
	}
	for(i=0;i<n;i++){
		p=a[i]*10;
		count[p]+=1;
		if(head[p]==NULL){
	        	head[p]=create_node(a[i]);
			tail[p]=head[p];						
		}
		else{
			tail[p]->next=create_node(a[i]);		//Add the inputs those are of same range into one bucket
			tail[p]=tail[p]->next;
		}
	}
	for(i=0;i<10;i++){
       		if(head[i]!=NULL){
	        	sort(head[i],count[i]);
	        	current=head[i];
	        	while(current!=NULL){
	      			printf("%lf\n",current->value);
	        		current=current->next;
	       		}
	    	}
	}
	
	
}
				
int main(){
	int n,i;
	double *a;
	printf("Enter no.of input numbers:\n");
	scanf("%d",&n);
	a=(double *)malloc(n*sizeof(double));
	for(i=0;i<n;i++){
		scanf("%lf",&a[i]);
	}
	Bucket_sort(a,n);
	return 0;
}
