#include<stdio.h>
#include<stdlib.h>
typedef struct queue one;
struct queue{
	int key;
	one *next;
};
int x;
one *top;
one *tail;
typedef struct node edge;
struct node{
	int val;
	int count;
	edge *next;
	edge *down;
};
edge *head;
edge *insert_vertex(int v,edge *head){
	edge *tmp;
	edge *start=head;
	tmp=(edge*)malloc(sizeof(edge));
		tmp->val=v;
		tmp->next=tmp->down=NULL;
	if(head==NULL)
		return tmp;
	else{
		while(start && start->down){
		start=start->down;
		}
		start->down=tmp;
	}
	return head;
}
edge *insert_edge(int v1,int v2,edge *head){
	edge *start=head;
	edge *tmp=head;
	edge *var=(edge*)malloc(sizeof(edge));
		var->val=v2;
		var->next=NULL;
	while(start){
	if(start->val==v1){	
		if(start->next==NULL)
			start->next=var;
		else{
			while(start && start->next){
				start=start->next;
			}
		start->next=var;
		}
		break;
	}
	else
		start=start->down;
	}
	while(tmp->val!=v2){
		tmp=tmp->down;
	}	
		tmp->count=tmp->count+1;
	
return head;
}
void print(edge *head){
		edge *tmp,*start,*var;
		tmp=start=var=head;
		while(tmp){
			printf("%d->count=[%d]",tmp->val,tmp->count);
				tmp=tmp->next;
			while(tmp){
				printf("->%d",tmp->val);
					tmp=tmp->next;	
			}
			printf("\n");
			start=start->down;
			tmp=start;
		}
}
void count_down(int y){
	edge *tmp=head;
	while(tmp->val!=y){
		tmp=tmp->down;
	}
		tmp->count=tmp->count-1;
}

void pop(one *top){
		int y;
	while(top!=NULL){
		if(top->next==NULL){
			tail=NULL;
		}
		one *tmp=top;
		y=tmp->key;
		top=top->next;
		free(tmp);
		printf("%d ",y);
		x++;
	}
}
one *push(int x){
		one *tmp;
		tmp=(one*)malloc(sizeof(one));
		tmp->key=x;
		printf("push->%d \n",x);
		tmp->next=NULL;
		if(tail==NULL){
			top=tmp;
			return tmp;
		}
			else{
			tail->next=tmp;
			tail=tmp;
		}
		return tail;
}
int flag[100];

edge *check(edge *head){
	edge *tmp=head;
	edge *start;
	int y;
	while(tmp){
		if(tmp->count==0 && flag[tmp->val]!=1){
			start=tmp;
		start=start->next; 
			flag[tmp->val]=1;
	while(start){
		y=start->val;
		count_down(y);
		start=start->next; 
	}
	tail=push(tmp->val);
		tmp=head;
		}
else{
tmp=tmp->down;
}
}
	return head;
}

int main(){
	head=NULL;
	top=tail=NULL;
	int n;
	printf("total no. of vertex");
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++){
		head=insert_vertex(i,head);
	}
	int v1,v2;
	printf("total no. of edges \n");
	int m;
	 x=0;
scanf("%d",&m);
	for(j=0;j<m;j++){
			scanf("%d%d",&v1,&v2);
			head=insert_edge(v1,v2,head);
	}
	print(head);
	while(n>x){
		head=check(head);
		pop(top);
	}
	printf("\n");
	return 0;
}
