//Shortest Remaining Time First is the preemptive version of SJF scheduling.
//In SRTF, the execution of the process can be stopped after certain amount of time. 
//At the arrival of every process, the short term scheduler schedules the process with 
//the least remaining burst time among the list of available processes and the running process.
/*Arrival Time:Time at which the process arrives in the ready queue.
Completion Time:Time at which process completes its execution.
Burst Time:Time required by a process for CPU execution.
Turn Around Time:Time Difference between completion time and arrival time.          
Waiting Time(W.T):Time Difference between turn around time and burst time. */

#include <stdio.h> 
#include <stdbool.h>

struct Process 
{   
    int pid;  // Process ID 
    int bt;   // CPU Burst time required 
    int art; // Arrival Time 
}; 

int main() 
{ 
    struct Process proc[] = {{1, 5, 2}, {2, 7, 6}, {3, 2, 3}}; 
    int n = sizeof proc / sizeof proc[0];  
    //sorting burst time in ascending order using selection sort
    
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 
    
    int runtime[n]; 

    // Copy the burst time into runtime
    for (int i = 0 ; i < n ; i++) 
        runtime[i] = proc[i].bt; 

    int complete = 0, t = 0, min = __INT32_MAX__; 
    int shortest = 0, finish_time; 
    bool check = false; 

    // Process until all processes gets completed 
    while (complete != n)
    { 
        // Find process with minimum remaining time among the processes that arrives till the current time` 
        for (int j = 0; j < n; j++)
        { 
            if ((proc[j].art <= t) && (runtime[j] < min) && runtime[j] > 0)
            { 
                min = runtime[j]; 
                shortest = j; 
                check = true; 
            } 
        } 

        if (check == false)
        { 
            t++; 
            continue; 
        } 

        runtime[shortest]--; 
        min = runtime[shortest]; 
        if (min == 0) 
            min = __INT32_MAX__; 
        if (runtime[shortest] == 0)
        { 
            complete++; 
            check = false;            
            finish_time = t + 1;             
            wt[shortest] = finish_time - proc[shortest].bt - proc[shortest].art;  
            if (wt[shortest] < 0) 
                wt[shortest] = 0; 
        } 
        t++; 
    } 
    
    for (int  i = 0 ; i < n ; i++) 
        tat[i] = proc[i].bt + wt[i]; 
    
    printf( "Processes\tBurst time\tWaiting time\tTurn around time \n");    

    for (int  i = 0 ; i < n ; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        printf("%d\t\t %d \t\t %d \t\t %d\n", proc[i].pid , proc[i].bt , wt[i] , tat[i]); 
    } 

    printf( "Average waiting time = %f", (float)total_wt / (float)n); 
    printf( "\nAverage turn around time = %f", (float)total_tat / (float)n); 
    
    return 0; 
} 

/*
Processes       Burst time      Waiting time    Turn around time
1                5               2               7
2                7               3               10
3                2               0               2
Average waiting time = 1.666667
Average turn around time = 6.333333*/
