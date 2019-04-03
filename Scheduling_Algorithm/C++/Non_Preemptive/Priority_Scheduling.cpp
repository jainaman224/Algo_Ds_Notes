//Priority scheduling is a non-preemptive algorithm . Each process is assigned a priority. 
//Process with the highest priority is to be executed first and so on.
/*Arrival Time:Time at which the process arrives in the ready queue.
Completion Time:Time at which process completes its execution.
Burst Time:Time required by a process for CPU execution.
Turn Around Time:Time Difference between completion time and arrival time.          
Waiting Time(W.T):Time Difference between turn around time and burst time. */
  
#include <bits/stdc++.h> 
using namespace std; 
  
class Process 
{  
    public:
    int pid;  
    int bt;    
    int priority; 
    void WaitingTime(Process proc[], int n, int wt[]) 
    { 
        wt[0] = 0; 
    
        for (int  i = 1 ; i < n ; i++ ) 
            wt[i] =  proc[i-1].bt + wt[i-1] ; 
    } 
  
    void TurnAroundTime( Process proc[], int n, int wt[], int tat[]) 
    { 
        for (int  i = 0 ; i < n ; i++) 
            tat[i] = proc[i].bt + wt[i]; 
    } 
  
    void avgTime(Process proc[], int n) 
    { 
        int wt[n], tat[n], total_wt = 0, total_tat = 0; 
  
        WaitingTime(proc, n, wt);     
        TurnAroundTime(proc, n, wt, tat);   
    
        cout << "\nProcesses  " << " Burst time  " << " Waiting time  " << " Turn around time\n";   
   
        for (int  i = 0 ; i < n ; i++) 
        { 
            total_wt = total_wt + wt[i]; 
            total_tat = total_tat + tat[i]; 
            cout << "   " << proc[i].pid << "\t\t" << proc[i].bt << "\t    " << wt[i] << "\t\t  " << tat[i] <<endl; 
        } 
  
        cout << "\nAverage waiting time = " << (float)total_wt / (float)n; 
        cout << "\nAverage turn around time = "<< (float)total_tat / (float)n; 
    } 
  
    void priorityScheduling(Process proc[], int n) 
    { 
        //sorting priority in descending order order using selection sort
        for(int i = 0 ; i < n ; i++)
        {
            int pos=i;
            int temp;
            for(int j = i + 1 ; j < n ;j++)
            {
                if( proc[j].priority > proc[pos].priority )
                    pos  = j;
            }
 
            temp = proc[i].priority;
            proc[i].priority = proc[pos].priority;
            proc[pos].priority = temp;
 
            temp = proc[i].pid;
            proc[i].pid = proc[pos].pid;
            proc[pos].pid = temp;

            temp = proc[i].bt;
            proc[i].bt = proc[pos].bt;
            proc[pos].bt = temp;
        }    
  
        cout<< "Order in which processes gets executed \n"; 
        for (int  i = 0 ; i <  n; i++) 
        cout << proc[i].pid << " " ; 
  
        avgTime(proc, n); 
    }  
}; 

int main() 
{   
    int n;
    cout << "Enter the number of processes ";
    cin >> n;
    Process proc[n];
    
    for (int i = 0 ; i < n ; i++)
    {   
        proc[i].pid = i+1;
        cout << "Enter the burst time for process " << i+1 << ": ";
        cin >> proc[i].bt;
        cout << "Enter the priority for process " << i+1 << ": ";
        cin >> proc[i].priority;
    }  
    
    proc[n].priorityScheduling(proc, n); 
    return 0; 
} 

/*Enter the number of processes 3
Enter the burst time for process 1: 9
Enter the priority for process 1: 2
Enter the burst time for process 2: 7
Enter the priority for process 2: 1
Enter the burst time for process 3: 10
Enter the priority for process 3: 3
Order in which processes gets executed 
3 1 2 
Processes   Burst time   Waiting time   Turn around time
   3           10            0              10
   1           9             10             19
   2           7             19             26

Average waiting time = 9.66667
Average turn around time = 18.3333*/
