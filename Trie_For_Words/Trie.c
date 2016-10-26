#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 26
struct node{
int data;
struct node *link[max];
}node;

struct node *root=NULL;

struct node *create(){
int x;
	struct node *q=(struct node*)malloc(sizeof(struct node));
for(x=0;x<max;x++)
	q->link[x]=NULL;

q->data=-1;
return q;
}

/*void itoa(int n,char s[])
{
	static i=0;
	if(n/10){
		itoa(n/10,s);
	}
	else{
		if(n<0)
		s[i++]='-';
	}
		s[i++]=abs(n)%10+'0';
		s[i]='\0';
}
*/
struct  node *insert(char key[]){
int level=0;
int index;
int length=strlen(key);
if(root==NULL)
	root=create();

struct node *q=root;
for(;level<length;level++){
	index=key[level]-'a';

	if(q->link[index]==NULL){
		q->link[index]=create();
		}
	q=q->link[index];
}
q->data=level;
}
int search(char string[]){
struct node *q;
q=root;
int length=strlen(string);
int level=0;
int index;
for(;level<length;level++){
	index=string[level]-'a';
	if(q->link[index]!=NULL)
		q=q->link[index];

	else
		break;
}

if((level==length && level>=1)||(string[level]=='\0' && q->data!=-1))
	return 4;	

return 10;
}

int main(){
int l,t,i,j,n,x,y;
char str[100000],one[100000];

scanf("%d",&n);

for(i=0;i<n;i++)
{
scanf("%s",str);
//itoa(x,s);
insert(str);
}
scanf("%d",&t);
for(j=0;j<t;j++){
scanf("%s",one);
	//itoa(y,one);
l=search(one);
if(l==4)
	printf("IT Exists!\n");
if(l==10)
	printf("Does not Exist.!\n");
}
return 0;
}
