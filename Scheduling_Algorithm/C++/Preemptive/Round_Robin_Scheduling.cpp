/*Round Robin Scheduling is a CPU scheduling algorithm where each process is assigned a fixed time slot in a cyclic way.
It is preemtive in nature.
It is cyclic in nature so starvation doesn’t occur
It is variant of first come, first served scheduling
No priority given to any process or task
It is also known as Time slicing scheduling
-Arrival Time: Time at which the process arrives in the ready queue.
-Burst Time: Time required by a process for CPU execution.
-Turn Around Time: Time Difference between completion time and arrival time.          
-Waiting Time: Time Difference between turn around time and burst time. */

#include<iostream>
using namespace std;

int main()
{        
    int i, j, no_of_process, current_time, remaining_time;
    int f = 0, time_slice, wait_time = 0, turn_time = 0;
    cout << "Enter number of processes: ";
    cin >> no_of_process;

    int a[no_of_process];	//Arrival Time
    int b[no_of_process];	//Burst Time
    int r[no_of_process];
    remaining_time = no_of_process;

    for(i = 0; i < no_of_process; i++)
    {
        cout << "\nProcess " << i << ": ";
        cout << "Enter Arrival Time: ";
        cin >> a[i];
        cout << "Enter Burst Time: ";
        cin >> b[i];
        r[i] = b[i];
    }

    cout << "Enter Time slice: ";
    cin >> time_slice;

    cout << "\nProcess\tTurnaround time\t Waiting Time\n";
    cout << "-------------------------------------------";
    for(current_time = 0, i = 0; remaining_time != 0;)
    {
        //If burst time is less than time slice
        if(r[i] <= time_slice && r[i] > 0)	
        {
            current_time += r[i];		//Increase current time by adding burst time
            r[i] = 0;				//Make remaining time zero
            f = 1;
        }
        //If required time is more than time slice
        else if(r[i] > 0)			
        {        
            r[i] -= time_slice;			//Reduce remaining time by time slice
            current_time += time_slice;		//Increase current time by adding time slice
        }

        if(r[i] == 0 && f == 1)
        {
            remaining_time--;
            cout << "\nProcess " << i << "\t" << current_time - a[i] << "\t\t" << current_time - a[i] - b[i];
            wait_time += current_time - a[i] - b[i];
            turn_time += current_time - a[i];
            f = 0;
        }
        if(i >= no_of_process - 1)
            i = 0;
        else if(a[i+1] <= current_time)
            i++;
        else
            i = 0;
     }
     cout << "\nAverage Waiting Time: " << (wait_time*1.0) / no_of_process;
     cout << "\nAverage Turnaround Time: " << (turn_time*1.0) / no_of_process;
     return 0;
}

/*
Sample Input/Output:

Enter number of processes: 4

Process 0: Enter Arrival Time: 1
Enter Burst Time: 5

Process 1: Enter Arrival Time: 3
Enter Burst Time: 7

Process 2: Enter Arrival Time: 2
Enter Burst Time: 5

Process 3: Enter Arrival Time: 5
Enter Burst Time: 8
Enter Time slice: 3

Process	Turnaround time	 Waiting Time
-------------------------------------------
Process 0	13		8
Process 2	17		12
Process 1	20		13
Process 3	20		12
Average Waiting Time: 11.25
Average Turnaround Time: 17.5
*/
