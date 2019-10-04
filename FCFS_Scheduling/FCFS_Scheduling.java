/*
        First Come First Served Scheduling Algorithm.

        The Problem is that there are n processes, which arrive at time 0 together
        at the Scheduler. We have to allot time to them in the order of their arrival
        time, but since all processes here arrive together, we allot processes in 
        order of their process ids, that is, process 1 will be executed first, then
        2 and so on..

        Burst Time : Time taken by a process to complete it's execution.
        Waiting Time : Total time a process has to wait before the scheduler is free.
        Turn Around Time : Total time difference between completion and arrival time.

        Given the Burst time, We need to find Waiting time and Turnaround time of each process.
*/

import java.util.Scanner;
import java.util.*;

class FCFS {
	
    public static void solve(int no_of_process, int burst_time[]) {
        int wait_time[] = new int[no_of_process];
        int turnaround_time[] = new int[no_of_process];
        wait_time[0] = 0; // wait time of 1st process is 0.
        /*
            We use the following equations for computing the result:

            Wait time of process i = wait time of process i-1 + burst time of process i-1.
            Turn Arond time of process i = burst time of process i + wait time of process i.
        */
        for (int i = 1; i < no_of_process; i++) {
            wait_time[i] = wait_time[i - 1] + burst_time[i - 1];
        }
        for (int i = 0; i < no_of_process; i++) {
            turnaround_time[i] = burst_time[i] + wait_time[i];
        }
        for (int i = 0; i < no_of_process ; i++) {
            System.out.println("Process " + (i + 1) + " -->  (B.T) : " + burst_time[i] + " (W.T.) : " + 
            wait_time[i] + " (T.A.T) : " + turnaround_time[i]);
        }
    }

    public static void main(String args[]) {
	Scanner sc = new Scanner(System.in);
        int no_of_process = sc.nextInt();
        int burst_time[] = new int[no_of_process];
	for(int i = 0; i < no_of_process; i++)
        {
            burst_time[i] = sc.nextInt();
        }
        solve(no_of_process, burst_time);
    }
}

/*
INPUT : no_of_process = 3
        Burst Time = {5, 7, 3}

OUTPUT : Process 1 -->  (B.T) : 5 (W.T.) : 0 (T.A.T) : 5
         Process 2 -->  (B.T) : 7 (W.T.) : 5 (T.A.T) : 12
         Process 3 -->  (B.T) : 3 (W.T.) : 12 (T.A.T) : 15

VERIFICATION : Process 1 gets the scheduler first, so it's wait time is 0.
               It completes execution by time = 5 (burst time[0] = 5)

               Now, Process 2 will get executed and it will finish by time = 5 + 7 = 12.
               So, it's wait time = 5 and turnaround time = 12 - 0 = 12. 
               (Completion - arrival time)

               Now, Process 3 has already waited for 5+7 = 12 units. So, 
               Waiting time = 12. Turnaround time = (15 - 0) = 15,
               since it will complete execution at 12 + 3 (Burst time[2] = 3) = 15.
*/
