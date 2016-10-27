#include<stdio.h>
#include<stdlib.h>

typedef struct node node;
struct node{
		int val;
		node *l;
		node *r;
};
node *root=NULL;
node *tmp;
node *put(node *new){
	if((tmp->val > new->val)&&(new->r!=NULL))
		put(new->r);
	if((tmp->val > new->val)&&(new->r==NULL))
		new->r=tmp;
	if((tmp->val < new->val)&&(new->l!=NULL))
		put(new->l);
	if((tmp->val < new->val)&&(new->l==NULL))
		new->l=tmp;
}
void print(node *view){
	if(root==NULL)
		return;

	else
		if(view->l!=NULL)
			print(view->l);
		if(view->r!=NULL)
			print(view->r);

		printf("%d->",view->val);
}


node *insert(){
	int x;
	scanf("%d",&x);
	tmp=(node*)malloc(sizeof(node));
	tmp->val=x;
	tmp->r=NULL;
	tmp->l=NULL;
	if(root==NULL)
		root=tmp;
	else
	put(root);
}

int main(){
	char a;
	while(1){
	scanf("%c",&a);
	if(a=='I')
		insert();


		if(a=='P'){
		printf("Postorder transversal.\n");
			print(root);
		printf("\n");
		}
				if(a=='Q')
			return 0;
}
}
