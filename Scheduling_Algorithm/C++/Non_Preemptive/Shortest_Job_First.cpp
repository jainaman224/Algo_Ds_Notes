//Shortest job first (SJF)  is a scheduling algorithm that selects
//the waiting process with the smallest execution time to execute next.
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
    int pid; // Process ID 
    int bt; // Burst Time
    void WaitingTime(Process proc[], int n, int wt[]) 
    { 
        // waiting time for first process is 0 
        wt[0] = 0; 

        // calculating waiting time 
        for (int i = 1 ; i < n ; i++ ) 
            wt[i] = proc[i-1].bt + wt[i-1] ; 
    } 

    void TurnAroundTime(Process proc[], int n, int wt[], int tat[]) 
    { 
        // calculating turnaround time by adding 
        // bt[i] + wt[i] 
        for (int i = 0; i < n ; i++) 
            tat[i] = proc[i].bt + wt[i]; 
    } 

    void avgTime(Process proc[], int n) 
    { 
        int wt[n], tat[n], total_wt = 0, total_tat = 0; 

        WaitingTime(proc, n, wt);  
        TurnAroundTime(proc, n, wt, tat); 

        cout << "\nProcesses "<< " Burst time "<< " Waiting time " << " Turn around time\n"; 

        // Calculate total waiting time and total turn around time 
        for (int i = 0; i < n; i++) 
        { 
            total_wt = total_wt + wt[i]; 
            total_tat = total_tat + tat[i]; 
            cout << " " << proc[i].pid << "\t\t"<< proc[i].bt << "\t " << wt[i]<< "\t\t " << tat[i] <<endl; 
        } 

        cout << "Average waiting time = "<< (float)total_wt / (float)n; 
        cout << "\nAverage turn around time = "<< (float)total_tat / (float)n; 
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
    }  
    //sorting burst time in ascending order using selection sort
    for(int i = 0 ; i < n ; i++)
    {
        int pos = i;
        int temp;
        for(int j = i + 1 ; j < n ; j++)
        {
            if( proc[j].bt < proc[pos].bt)
                pos = j ;
        }

        temp = proc[i].bt;
        proc[i].bt = proc[pos].bt;
        proc[pos].bt = temp;

        temp = proc[i].pid;
        proc[i].pid = proc[pos].pid;
        proc[pos].pid = temp;
    }    

    cout << "Order in which process gets executed\n"; 
    for (int i = 0 ; i < n; i++) 
        cout << proc[i].pid <<" "; 

    proc[n].avgTime(proc, n); 
    return 0; 
} 

/*Enter the number of processes 4
Enter the burst time for process 1: 4
Enter the burst time for process 2: 8
Enter the burst time for process 3: 3
Enter the burst time for process 4: 7
Order in which process gets executed
3 1 4 2 
Processes  Burst time  Waiting time  Turn around time
 3		3	 0		 3
 1		4	 3		 7
 4		7	 7		 14
 2		8	 14		 22
Average waiting time = 6
Average turn around time = 11.5*/
