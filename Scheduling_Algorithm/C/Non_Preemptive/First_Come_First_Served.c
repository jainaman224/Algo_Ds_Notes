//First come first serve (FCFS) scheduling algorithm simply schedules the jobs according
//to their arrival time. The job which comes first in the ready queue will get the
//CPU first. 
/*Arrival Time:Time at which the process arrives in the ready queue.
Completion Time:Time at which process completes its execution.
Burst Time:Time required by a process for CPU execution.
Turn Around Time:Time Difference between completion time and arrival time.          
Waiting Time(W.T):Time Difference between turn around time and burst time. */

# include <stdio.h>

int main() 
{ 
    int processes[] = { 1, 2, 3, 4}; 
    int n = sizeof processes / sizeof processes[0]; 
  
    int bt[]={3, 6, 9, 3};//Burst time    

    int wt[n], tat[n], total_wt = 0, total_tat = 0;
          
    // waiting time for first process is 0 
    wt[0] = 0; 

    // calculating waiting time 
    for (int  i = 1; i < n; i++ ) 
        wt[i] =  bt[i-1] + wt[i-1] ;
     
    // calculating turnaround time by adding burst time and waiting time
    for (int  i = 0; i < n; i++) 
        tat[i] = bt[i] + wt[i]; 
          
    //Display processes along with all details 
    printf( "Processes\tBurst time\tWaiting time\tTurn around time \n"); 

    // Calculate total waiting time and total turn around time 
    for (int  i = 0; i < n ; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        printf("%d\t\t %d \t\t %d \t\t %d\n",i+1 ,bt[i] , wt[i], tat[i] ); 
    } 

    printf( "Average waiting time = %f", (float)total_wt / (float)n); 
    printf( "\nAverage turn around time = %f", (float)total_tat / (float)n);       
    return 0; 
}

/*
Processes       Burst time      Waiting time    Turn around time
1                3               0               3
2                6               3               9
3                9               9               18
4                3               18              21
Average waiting time = 7.500000
Average turn around time = 12.750000*/
