//Priority scheduling is a non-preemptive algorithm . Each process is assigned a priority. 
//Process with the highest priority is to be executed first and so on.
/*Arrival Time:Time at which the process arrives in the ready queue.
Completion Time:Time at which process completes its execution.
Burst Time:Time required by a process for CPU execution.
Turn Around Time:Time Difference between completion time and arrival time.          
Waiting Time(W.T):Time Difference between turn around time and burst time. */
  
#include <stdio.h> 
struct Process 
{   
    int pid;  // Process ID 
    int bt;   // CPU Burst time required 
    int priority; // Priority of this process 
}; 

void swap (int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
} 

int main() 
{   
    struct Process proc[] = {{1, 9, 2}, {2, 2, 1}, {3, 10, 3}}; 
    int n = sizeof proc / sizeof proc[0]; 
    
    //Priority Scheduling
    //sorting priority in descending order order using selection sort
    for(int i = 0; i < n; i++)
    {
        int pos=i;
        int temp;
        for(int j = i + 1; j < n;j++)
        {
            if( proc[j].priority > proc[pos].priority )
                pos = j;
        }
        swap(&proc[i].priority, &proc[pos].priority);
        swap(&proc[i].pid, &proc[pos].pid);
        swap(&proc[i].bt, &proc[pos].bt);

    }    

    printf("Order in which processes gets executed \n"); 
    for (int  i = 0; i < n; i++) 
        printf( " %d  ", proc[i].pid) ; 
    printf ("\n"); 
    
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
          
    // waiting time for first process is 0 
    wt[0] = 0; 

    // calculating waiting time 
    for (int  i = 1; i < n; i++ ) 
        wt[i] = proc[i-1].bt + wt[i-1] ;
     
    // calculating turnaround time by adding burst time and waiting time
    for (int  i = 0; i < n; i++) 
        tat[i] = proc[i].bt + wt[i]; 
          
    //Display processes along with all details 
    printf( "Processes\tBurst time\tWaiting time\tTurn around time \n"); 

    // Calculate total waiting time and total turn around time 
    for (int  i = 0; i < n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        printf("%d\t\t %d \t\t %d \t\t %d\n",i+1 ,proc[i].bt , wt[i], tat[i] ); 
    } 

    printf( "Average waiting time = %f", (float)total_wt / (float)n); 
    printf( "\nAverage turn around time = %f", (float)total_tat / (float)n);  
    return 0; 
} 

/*
Order in which processes gets executed
 3   1   2
Processes       Burst time      Waiting time    Turn around time
3                10              0               10
1                9               10              19
2                2               19              21
Average waiting time = 9.666667
Average turn around time = 16.666666
*/
