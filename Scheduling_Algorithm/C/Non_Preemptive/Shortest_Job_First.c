//Shortest job first (SJF)  is a scheduling algorithm that selects
//the waiting process with the smallest execution time to execute next.
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
}; 

void swap (int *a, int *b);

int main() 
{ 
    struct Process proc[] = {{1, 4}, {2, 8}, {3, 3}, {4, 7}}; 
    int n = sizeof proc / sizeof proc[0];  
    
    //sorting burst time in ascending order using selection sort
    for(int i = 0; i < n; i++)
    {
        int pos = i;
        int temp;
        for(int j = i + 1; j < n; j++)
        {
            if( proc[j].bt < proc[pos].bt)
                pos = j ;
        }

        swap(&proc[i].pid,&proc[pos].pid);
        swap(&proc[i].bt,&proc[pos].bt);
    }    

    printf("Order in which processes gets executed \n"); 
    for (int  i = 0 ; i <  n; i++) 
        printf( " %d  ",proc[i].pid) ; 
    printf("\n");
    
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

void swap (int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/*
Order in which process gets executed
3 1 4 2 
Processes       Burst time      Waiting time    Turn around time
3                3               0               3
1                4               3               7
4                7               7               14
2                8               14              22
Average waiting time = 6
Average turn around time = 11.5*/
 
