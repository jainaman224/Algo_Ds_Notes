#include<stdio.h>
#include<stdlib.h>
int main(){
	int num,j,sum,i,sumwt,sumtt;
	float avgwt,avgtt;
	printf("Enter number of processes	: ");//taking number of processes as input
	scanf("%d",&num);
	int *a,*b;
	a=(int*)malloc(num*sizeof(int));//declaring an array with required size
	for( i=0;i<num;i++){
		printf("\nEnter burst time for process %d	:",i);//taking input for burst time for each process
		scanf("%d",&a[i]);
	}
	b=(int*)malloc(num*sizeof(int));//declaring array for storing waiting time of each process
	for( i=0;i<num;i++){
		if(i==0){
			b[i]=0;//first process does not wait
		}
		else{
			sum=0;
			for (j=0;j<i;j++){
				sum=sum+a[j];
			}
			b[i]=sum;//for rest of processes, waiting time will be the sum of burst time of previous process  
		}
	}
	sumwt=0+0.0,sumtt=0+0.0;
	printf("PROCESS		BURST TIME		WAITING TIME	TURNAROUND TIME");
	for (i=0;i<num;i++){
		
		printf("\n	P%d			%d				%d						%d",i,a[i],b[i],b[i]+a[i]);//extra spaces for better view
		sumwt=sumwt+b[i];
		sumtt=sumtt+b[i]+a[i];
	}
	avgwt=sumwt/num;
	avgtt=sumtt/num;
	printf("\nAverage waiting time= %6.6f",avgwt);
	printf("\nAverage turnaround time=%6.6f",avgtt);
}
