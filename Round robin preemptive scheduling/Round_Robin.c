#include<stdio.h> 
 
void main() 
{ 
 
  int count,j,n,time,remain,flag=0,time_quantum; 
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10]; 
  printf("Enter Total Process:\t "); 
  scanf("%d",&n); 
  remain=n; 
  for(count=0;count<n;count++) 
  { 
    printf("Enter Arrival Time and Burst Time for Process Number %d :",count+1); 
    scanf("%d",&at[count]); 
    scanf("%d",&bt[count]); 
    rt[count]=bt[count]; 
  } 
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
      wait_time+=time-at[count]-bt[count]; 
      turnaround_time+=time-at[count]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
  
 
}
//  --------------- Result -------------------

// Enter Total Process:     5
// Enter Arrival Time and Burst Time for Process Number 1 :0 10
// Enter Arrival Time and Burst Time for Process Number 2 :3 1
// Enter Arrival Time and Burst Time for Process Number 3 :2 2
// Enter Arrival Time and Burst Time for Process Number 4 :4 1
// Enter Arrival Time and Burst Time for Process Number 5 :1 5
// Enter Time Quantum: 2


// Process |Turnaround Time|Waiting Time

// P[2]    |   2   |   1
// P[3]    |   5   |   3
// P[4]    |   4   |   3
// P[5]    |   16  |   11
// P[1]    |   19  |   9

// Average Waiting Time= 5.400000
// Avg Turnaround Time = 9.200000
