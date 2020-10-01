//First come first serve (FCFS) scheduling algorithm simply schedules the jobs according
//to their arrival time. The job which comes first in the ready queue will get the
//CPU first. 
/*Arrival Time:Time at which the process arrives in the ready queue.
Completion Time:Time at which process completes its execution.
Burst Time:Time required by a process for CPU execution.
Turn Around Time:Time Difference between completion time and arrival time.          
Waiting Time(W.T):Time Difference between turn around time and burst time. */

#include<iostream> 
using namespace std;  

void WaitingTime (int processes[], int n , int bt[], int wt[]); 
void TurnAroundTime ( int processes[], int n,int bt[], int wt[], int tat[]); 
void avgTime ( int processes[], int n, int bt[]) ;  

int main() 
{ 
    int n ;
    cout << "Enter the number of processes " ;
    cin >> n ;
    int processes[n]; 
    int burst_time[n];
    for (int i = 0 ; i < n ; i++)
    {
        cout << "Enter the burst time for process " << i+1 << ": " ;
        cin >> burst_time[i];
    }
    
    avgTime( processes, n,  burst_time ); 
    return 0; 
}

void WaitingTime (int processes[], int n,int bt[], int wt[]) 
{ 
    // waiting time for first process is 0 
    wt[0] = 0; 
  
    // calculating waiting time 
    for (int  i = 1; i < n ; i++ ) 
        wt[i] =  bt[i-1] + wt[i-1] ; 
} 

void TurnAroundTime( int processes[], int n,int bt[], int wt[], int tat[]) 
{ 
    // calculating turnaround time by adding burst time and waiting time
    for (int  i = 0; i < n ; i++) 
        tat[i] = bt[i] + wt[i]; 
} 
 
void avgTime( int processes[], int n, int bt[]) 
{ 
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 
    
    WaitingTime(processes, n, bt, wt); 
    TurnAroundTime(processes, n, bt, wt, tat); 
    
    //Display processes along with all details 
    cout << "Processes  " << " Burst time  " << " Waiting time  " << " Turn around time\n"; 
  
    // Calculate total waiting time and total turn around time 
    for (int  i = 0; i < n ; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << "   " << i+1 << "\t\t" << bt[i] <<"\t    "<< wt[i] <<"\t\t  " << tat[i] <<endl; 
    } 
  
    cout << "Average waiting time = "<< (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)n; 
} 

/*Enter the number of processes 4
Enter the burst time for process 1 :8
Enter the burst time for process 2 :4
Enter the burst time for process 3 :7
Enter the burst time for process 4 :1
Processes   Burst time   Waiting time   Turn around time
   1		8	    0		  8
   2		4	    8		  12
   3		7	    12		  19
   4		1	    19		  20
Average waiting time = 9.75
Average turn around time = 14.75*/
