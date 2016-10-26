#include<stdio.h>
#include<stdlib.h>
int n;
typedef struct node{
	int value;
	int weight;
	struct node *next;
}Node;

typedef struct edge{
	int start;
	int end;
	int wt;
}Edge;

Node *array[100007];
void set(int point[]){
	int i;
	for(i=0;i<=n;i++)
		point[i]=-1;
}
Node* make_node(int x,int y){

Node *new_node=(Node*)malloc(sizeof(Node));
	if(new_node){
			new_node->value=x;
			new_node->next=NULL;
			new_node->weight=y;
		}
return new_node;
}

void add_edge(int x,int y,int wt){
	Node *tmp=array[x];
	if(tmp==NULL)
		array[x]=make_node(y,wt);

	else{
		while(tmp->next){
			tmp=tmp->next;
		}
		tmp->next=make_node(y,wt);
	}
}


void union_set(int point[],int x,int y){
	int r_x=find(point,x);
	int r_y=find(point,y);

	point[r_x]=r_y;
}

int find(int point[],int value){
	
	if(point[value] == -1)
		return value;
	else 
		find(point,point[value]);
}

void for_sort(Edge edges[],Node *array[]){
	int i;
	int count=0;
	for(i=1;i<=n;i++){
		Node *v=array[i];
		if(v){
			Node *u=v->next;
			while(u){
					edges[count].start=v->value;
					edges[count].end=u->value;
					edges[count].wt=u->weight;
					count++;
					u=u->next;
			}
		}

	}
}

void swap(Edge edges[],int x,int y){
	int s=edges[x].start;
	int end=edges[x].end;
	int wt=edges[x].wt;

	edges[x].start=edges[y].start;
	edges[x].end=edges[y].end;
	edges[x].wt=edges[y].wt;

	edges[y].start=s;
	edges[y].end=end;
	edges[y].wt=wt;
}

void qck_sort(Edge edges[],int x,int y){

	if(x>=y)
		return;
	int mid=partition(edges,x,y);

	qck_sort(edges,x,mid);
	qck_sort(edges,mid+1,y);

}

int partition(Edge edges[],int x,int y){
	int i,j,k,l;
	int mid=edges[x].wt;
		k=x+1;
		l=y;
		while(k<=l){
			while(k<=y && edges[k].wt < mid)
				k++;

			while(l>x && edges[l].wt>=mid)
				l--;

			if(k<l)
				swap(edges,k,l);
		}
	if(l>x)
		swap(edges,x,l);

	return l;
}

void kruskl(Node *array[],int n_edge){
			int point[n+1];
			int i,count=0;
			int wt=0;
		Edge edges[n_edge];
		Edge MST[n_edge];

			for_sort(edges,array);
			qck_sort(edges,0,n_edge);

		set(point);
		for(i=0;i<n_edge;i++){
			if(find(point,edges[i].start)!=find(point,edges[i].end)){
				union_set(point,edges[i].start,edges[i].end);
				MST[count++]=edges[i];
				wt+=edges[i].wt;
			}
		}
		int sum=0;
		if(count!=n-1)
			printf("-1\n");
		else{
		for(i=0;i<count;i++){
		sum+=MST[i].wt;
	//		printf("(%d)->(%d)\n",MST[i].start,MST[i].end);
		}
	printf("%d\n",sum);
}
}

int main(){
int m;
scanf("%d%d",&n,&m);
int i,j;

if(m==0){
	printf("-1\n");
	return 0;
}
for(i=1;i<=n;i++)
	array[i]=make_node(i,0);
	
	int u,v,w;
	for(j=0;j<m;j++){
		scanf("%d%d%d",&u,&v,&w);
			add_edge(u,v,w);
	}
kruskl(array,m);
return 0;
}
