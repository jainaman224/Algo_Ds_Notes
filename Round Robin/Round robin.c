#include<stdio.h>
#include<stdlib.h>
struct node{
		int pid;
		int burst_time;
		int rem_time;
		int wait_time;
		int taround_time;
		struct node *next;
	};
	struct node *front=NULL,*rear, *temp,*temp_prev,*last, *temp1,*temp2;
int n,i,g,t,k,slice,time=0;

int main(){
	printf("-----Implementation of Round Robin Algorithm-----\n");

	printf("Enter no. of processes  :  ");
	scanf("%d",&n);
	struct node arr[n];//creating an array of struct node(process)
	printf("\nEnter slice time  :  ");
	scanf("%d",&slice);
	for(i=0;i<n;i++)
	{
		temp=(struct node*)malloc(sizeof(struct node));//storing each process with id and other details in a structure 
		printf("\nEnter the burst time for process P %d: ",i);
		scanf("%d", &temp->burst_time);
		temp->next=NULL;
		if(front==NULL)
		{
			front=temp;
			last=temp;
		}
		else
		{
			last->next=temp;
			last=temp;
		}
		last->pid=i;
		last->rem_time=last->burst_time;
		last->taround_time=0;
		last->wait_time=0;
		arr[i].pid=i;
		arr[i].burst_time=temp->burst_time;
		arr[i].rem_time=arr[i].burst_time;
		arr[i].wait_time=0;
		arr[i].taround_time=0;

	}
	last->next=front;
	rear=last;
	while(front->pid!=rear->pid)//iteration till only one process is left in queue
    {
        if(front->rem_time>slice){
            time+=slice;
            front->rem_time-=slice;
            front=front->next;
            rear=rear->next;

        }
        else{
            time+=front->rem_time;
            front->rem_time=0;
            arr[front->pid].wait_time=time-arr[front->pid].burst_time;
            arr[front->pid].taround_time=time;
            rear->next=front->next;
            front->next=NULL;
            free(front);
            front=rear->next;
        }


    }
    time+=front->rem_time;
    arr[front->pid].taround_time=time;
    arr[front->pid].wait_time=time-arr[front->pid].burst_time;
    float sumwt=0.0,sumtt=0.0;
	float avgwt,avgtt;
	int i;
	printf("\nPROCESS		BURST TIME		WAITING TIME	TURNAROUND TIME");
	for (i=0;i<n;i++){

		printf("\n P%d		 %d	 	         %d	 	        %d",i,arr[i].burst_time,arr[i].wait_time,arr[i].taround_time);//extra spaces for better visibility
		sumwt=sumwt+arr[i].wait_time;
		sumtt=sumtt+arr[i].taround_time;
	}

	avgwt=sumwt/n;
	avgtt=sumtt/n;
	printf("\nAverage waiting time= %6.6f",avgwt);
	printf("\nAverage turnaround time=%6.6f",avgtt);
}

