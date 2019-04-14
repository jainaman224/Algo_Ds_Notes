#include<stdio.h>
#include<stdlib.h>

struct ll{
	long int elem;
	long int pr;
};

void swap (struct ll pq[], long int i,long int j)
{
	struct ll temp = pq[i];
	pq[i] = pq[j];
	pq[j] =temp;
}

long  size =0;

void minheapify (struct ll pq[],long  int i,long int len)
{

	long int l= i*2+1;
	long int r = i*2 + 2;
	long int smallest = i;
	if((l<len)&&(pq[smallest].pr>pq[l].pr))
		smallest = l;
	if((r<len)&&(pq[smallest].pr>pq[r].pr))
		smallest = r;
	if(smallest!=i)
	{
		swap(pq,i, smallest);
		minheapify(pq,smallest,len);
	}
	return;
}


void buildminheap(struct ll pq[],long int l)
{
	long int i;
	for(i= (l/2)-1; i>=0; i--)
		minheapify(pq,i,l);
	return;
}
void heapsort(struct ll pq[])
{
	long int length = size;
	do
	{
		buildminheap(pq,length);
		swap(pq, 0 , length-1);
		length = length-1;
	}while(length>0);
}



void insert (struct ll pq[], long int data, long int num)
{
	pq[size-1].elem = data;
	pq[size-1].pr = num;
	heapsort(pq);
}

void extract_min(struct ll pq[])
{
	if(size==0)
		printf("EMPTY\n");
	else
	{
		long int n = pq[size-1].elem;
		printf("%ld ", n);
		printf("(%ld)\n", pq[size-1].pr);
		size--;
	}
	return;
}

void get_min(struct ll pq[])
{
	if(size==0)
		printf("EMPTY\n");
	else
	{
		long int n = pq[size-1].elem;
		printf("%ld ", n);
		printf("(%ld)\n", pq[size-1].pr);
	}
	return;
}

void decrease_priority (struct ll pq[],long int data , long int num )
{
	for(long int j=0; j< size ; j++)
	{
		if(pq[j].elem==data)
			pq[j].pr = num;
	}
	heapsort(pq);
}


int main()
{
struct ll *prqueue ;
prqueue = (struct ll* )malloc( sizeof(struct ll) );

char ch;

do 
{
	//choose the functionality
	scanf("%c",&ch);
	

	switch(ch)
	{
		//insert
		case 'a':{
					prqueue = (struct ll* ) realloc (prqueue, (++size)*sizeof(struct ll));
					long int num, data;
					scanf ("%ld", &data);
					scanf ("%ld", &num);
					insert(prqueue,data,num );
					break;

		}

		//remove the minimum
		case 'e':{
					extract_min(prqueue);
					break;
		}

		//get the minimum
		case 'g':{
					get_min(prqueue);
					break;
		}

		//decrease priority of node
		case 'd':{
					long int num, data;
					scanf ("%ld", &data);
					scanf ("%ld", &num);
					decrease_priority(prqueue,data, num);
					break;
		}

		case 's':	exit(0);

		default :	printf("error\n");
					break;
	}
	getchar();
	
}while(ch!='s');
return 0;
}
