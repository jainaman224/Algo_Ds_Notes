#include<stdio.h>
#include<stdlib.h>

typedef struct circ buff;
struct circ{
	int val;
	buff *prev;
	buff *next;
};

buff *head;
buff *tail;

buff *insert(buff *head,int x){
	buff *tmp;
	tmp=(buff*)malloc(sizeof(buff));
	tmp->val=x;
	tmp->next=tmp;
	tmp->prev=tmp;

	if(head==NULL){
		tail=tmp;
		return tmp;
	}
	else{
		tmp->prev=tail;
		tmp->next=head;
		tail->next=tmp;
		head->prev=tmp;
		tail=tmp;
	}
	return head;
}

buff *print(buff *head){
	buff *start=head;
	while(head!=tail){
		printf("%d ",head->val);
	head=head->next;
	}
	printf("%d\n",head->val);
	return start;
}

int main(){
	int x,i,j; 
	tail=head=NULL;
	
	//char c;
//	scanf("%c",&c);
//	if(c=='i'){
while(1){
	scanf("%d",&x);
	head=insert(head,x);
	head=print(head);
	printf("head-> %d\n",tail->next->val); 
	printf("tail-> %d\n",head->prev->val);
}

return 0;
}
