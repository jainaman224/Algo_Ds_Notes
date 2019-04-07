//Shortest Remaining Time First is the preemptive version of SJF scheduling.
//In SRTF, the execution of the process can be stopped after certain amount of time. 
//At the arrival of every process, the short term scheduler schedules the process with 
//the least remaining burst time among the list of available processes and the running process.
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
    int art; // Arrival Time 
    void WaitingTime(Process proc[], int n,int wt[]) 
    { 
        int runtime[n]; 

        // Copy the burst time into runtime
        for (int i = 0 ; i < n ; i++) 
            runtime[i] = proc[i].bt; 

        int complete = 0, t = 0, min = INT_MAX; 
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
                min = INT_MAX; 
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
    } 

    void TurnAroundTime(Process proc[], int n, int wt[], int tat[]) 
    { 
        // calculating turnaround time by adding burst time and waiting time 
        for (int i = 0; i < n; i++) 
            tat[i] = proc[i].bt + wt[i]; 
    } 

    void avgTime(Process proc[], int n) 
    { 
        int wt[n], tat[n], total_wt = 0, total_tat = 0; 

        WaitingTime(proc, n, wt); 
        TurnAroundTime(proc, n, wt, tat); 

        cout << "Processes "<< " Burst time "<<"Arrival time"<< " Waiting time "<< " Turn around time\n"; 

        for (int i = 0; i < n; i++) 
        {
            total_wt = total_wt + wt[i]; 
            total_tat = total_tat + tat[i]; 
            cout << " " << proc[i].pid << "\t\t"<< proc[i].bt << "\t\t "<<proc[i].art<<"\t\t "<< wt[i]<< "\t\t " << tat[i] << endl; 
        } 

        cout << "\nAverage waiting time = "<< (float)total_wt / (float)n; 
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
        cout << "Enter the arrival time for process " << i+1 << ": ";
        cin >> proc[i].art;
    }  
  
    proc[n].avgTime(proc, n); 
    return 0; 
}

/*Enter the number of processes 3
Enter the burst time for process 1: 5
Enter the arrival time for process 1: 2
Enter the burst time for process 2: 7
Enter the arrival time for process 2: 6
Enter the burst time for process 3: 2
Enter the arrival time for process 3: 3
Processes  Burst time Arrival time Waiting time  Turn around time
     1          5         2             2             7
     2          7         6             3             10
     3          2         3             0             2
Average waiting time = 1.66667
Average turn around time = 6.33333*/
