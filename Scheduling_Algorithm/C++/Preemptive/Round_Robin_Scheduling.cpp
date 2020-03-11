#include<iostream>
using namespace std;

int main()
{        
    int i, j, no_of_process, current_time, remaining_time, f = 0, time_slice, wait_time = 0, turn_time = 0;
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
    cout << "-------------------------------------------"
    for(current_time = 0, i = 0; remaining_time != 0;)
    {
        if(r[i] <= time_slice && r[i] > 0)	//If burst time is less than time slice
        {
	    current_time += r[i];		//Increase current time by adding burst time
            r[i] = 0;				//Make remaining time zero
            f = 1;
        }
        else if(r[i] > 0)			//If required time is more than time slice
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
