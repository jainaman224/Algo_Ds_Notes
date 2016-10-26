#include<stdio.h>
int n;
int a[10000];
int insert(int x){
	int tmp,l;

	a[n]=x;
	l=n;
	n=n+1;
while(a[l/2]>=a[l])
	{
		tmp=a[l/2];
		a[l/2]=a[l];
		a[l]=tmp;
		l=l/2;
	}
}
void print(){
	int i;
	for(i=1;i<n;i++)
		printf("%d\n",a[i]);
}
void swap(int *a,int *b)
 {
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

int d_elet_e(int x){
int i,y,tmp,tmp2,k;
for(i=1;i<=n;i++){
	if(a[i]==x){
		y=i;
		break;
	}
}
if(y==n-1)
 n--;
else
a[y]=a[n-1];
n--;
k=y;
while(a[k]<a[k/2])
{
	tmp=a[k];
	a[k]=a[k/2];
	a[k/2]=tmp;
	k=k/2;
}
while((a[k]>a[k*2] || a[k]>a[k*2+1]) && (k*2<=n)){
if((a[k]>a[k*2]) && (a[k*2]<a[k*2+1])){
		swap(&a[2*k],&a[k]);
	printf("%d pe value hai %d",2*k,a[2*k]);
	k=k*2;
}
else{
tmp2=a[k];
a[k]=a[2*k+1];
a[2*k+1]=tmp2;
k=2*k+1;
}
}
return;
}


int main()
{
	int i,t,j,x;
	n=1;
	char c,d;
	while(1){
	scanf("%c",&c);
	if(c=='d' || c=='D'){
		scanf("%d",&x);
		d_elet_e(x);
	}

	if(c=='I' || c=='i')
	{
		scanf("%d",&x);
		insert(x);
	}

	if(c=='p'||c=='P')
		print();
}
return 0;
}
