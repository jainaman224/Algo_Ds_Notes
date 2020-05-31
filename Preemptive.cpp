About:In priority scheduling, a number is assigned to each process that indicates its priority level. 
Lower the number, higher is the priority. In this type of scheduling algorithm, if a newer process arrives, that is having a higher 
priority than the currently running process, then the currently running process is preempted.

Program for preemptive priority
#include <bits/stdc++.h>
using namespace std;

struct Process {
    int processID;
    int burstTime;
    int tempburstTime;
    int responsetime;
    int arrivalTime;
    int priority;
    int outtime;
    int intime;
};

// It is used to include all the valid and eligible
// processes in the heap for execution. heapsize defines
// the number of processes in execution depending on
// the current time currentTime keeps a record of
// the current CPU time.
void insert(Process Heap[], Process value, int* heapsize,int* currentTime)
{
    int start = *heapsize, i;
    Heap[*heapsize] = value;
    if (Heap[*heapsize].intime == -1)
        Heap[*heapsize].intime = *currentTime;
    ++(*heapsize);

    // Ordering the Heap
    while (start != 0 && Heap[(start - 1) / 2].priority > Heap[start].priority) {
        Process temp = Heap[(start - 1) / 2];
        Heap[(start - 1) / 2] = Heap[start];
        Heap[start] = temp;
        start = (start - 1) / 2;
    }
}

// It is used to reorder the heap according to
// priority if the processes after insertion
// of new process.
void order(Process Heap[], int* heapsize, int start)
{
    int smallest = start;
    int left = 2 * start + 1;
    int right = 2 * start + 2;
    if (left < *heapsize && Heap[left].priority <Heap[smallest].priority)
        smallest = left;
     if (right < *heapsize && Heap[right].priority <Heap[smallest].priority)
        smallest = right;

    // Ordering the Heap
    if (smallest != start) {
        Process temp = Heap[smallest];
        Heap[smallest] = Heap[start];
        Heap[start] = temp;
        order(Heap, heapsize, smallest);
    }
}

// This function is used to find the process with
// highest priority from the heap. It also reorders
// the heap after extracting the highest priority process.
Process extractminimum(Process Heap[], int* heapsize,int* currentTime)
{
    Process min = Heap[0];
    if (min.responsetime == -1)
        min.responsetime = *currentTime - min.arrivalTime;
    --(*heapsize);
    if (*heapsize >= 1) {
        Heap[0] = Heap[*heapsize];
        order(Heap, heapsize, 0);
    }
    return min;
}

// Compares two intervals according to staring times.
int compare(Process p1, Process p2)
{
     if (p1.arrivalTime < p2.arrivalTime)
         return 1;
     else
         return 0;
}

// This function is responsible for executing
// the highest priority extracted from Heap[].
void scheduling(Process Heap[], Process array[], int n,int* heapsize, int* currentTime)
{
    if (heapsize == 0)
        return;

    Process min = extractminimum(Heap, heapsize, currentTime);
    min.outtime = *currentTime + 1;
    --min.burstTime;
    printf("process id = %d\tcurrent_time = %d\n",
           min.processID, *currentTime);

    // If the process is not yet finished
    // insert it back into the Heap*/
    if (min.burstTime > 0) {
        insert(Heap, min, heapsize, currentTime);
        return;
    }

    for (int i = 0; i < n; i++)
        if (array[i].processID == min.processID) {
            array[i] = min;
            break;
        }
}

// This function is responsible for
// managing the entire execution of the
// processes as they arrive in the CPU
// according to their arrival time.
void priority(Process array[], int n)
{
    sort(array, array + n, compare);

    int totalwaitingtime = 0, totalbursttime = 0,
        totalturnaroundtime = 0, i, insertedprocess = 0,
        heapsize = 0, currentTime = array[0].arrivalTime,
        totalresponsetime = 0;

    Process Heap[4 * n];

    // Calculating the total burst time
    // of the processes
    for (int i = 0; i < n; i++) {
        totalbursttime += array[i].burstTime;
        array[i].tempburstTime = array[i].burstTime;
    }

    // Inserting the processes in Heap
    // according to arrival time
    do {
        if (insertedprocess != n) {
            for (i = 0; i < n; i++) {
                if (array[i].arrivalTime == currentTime) {
                    ++insertedprocess;
                    array[i].intime = -1;
                    array[i].responsetime = -1;
                    insert(Heap, array[i], &heapsize, &currentTime);
                }
            }
        }
        scheduling(Heap, array, n, &heapsize, &currentTime);
        ++currentTime;
        if (heapsize == 0 && insertedprocess == n)
            break;
    } while (1);

    for (int i = 0; i < n; i++) {
        totalresponsetime += array[i].responsetime;
        totalwaitingtime += (array[i].outtime - array[i].intime -
                                         array[i].tempburstTime);
        totalbursttime += array[i].burstTime;
    }
    printf("\n\nAverage waiting time = %f\n",
           ((float)totalwaitingtime / (float)n));
    printf("\nAverage response time =%f\n",
           ((float)totalresponsetime / (float)n));
    printf("\nAverage turn around time = %f\n",
           ((float)(totalwaitingtime + totalbursttime) / (float)n));
}

// Driver code
int main()
{
    int n, i;
    Process a[5];
    printf("Enter the no.of Process:-");
    cin>>n;
    printf("Arival_Time  Burst_Time  Priority\n");
    for(int i=0;i<n;i++)
    {
    a[i].processID=i+1;
    cin>>a[i].arrivalTime;
    cin>>a[i].burstTime;
    cin>>a[i].priority;
	}
    priority(a, n);
    return 0;
}



Output:-
Enter the no.of Process:-5
Arival_Time  Burst_Time  Priority
          1           4         3
          3           7         2
          0           9         5 
          4           3         4
          2           5         1
process id = 3  current_time = 0
process id = 1  current_time = 1
process id = 5  current_time = 2
process id = 5  current_time = 3
process id = 5  current_time = 4
process id = 5  current_time = 5
process id = 5  current_time = 6
process id = 2  current_time = 7
process id = 2  current_time = 8
process id = 2  current_time = 9
process id = 2  current_time = 10
process id = 2  current_time = 11
process id = 2  current_time = 12
process id = 2  current_time = 13
process id = 1  current_time = 14
process id = 1  current_time = 15
process id = 1  current_time = 16
process id = 4  current_time = 17
process id = 4  current_time = 18
process id = 4  current_time = 19
process id = 3  current_time = 20
process id = 3  current_time = 21
process id = 3  current_time = 22
process id = 3  current_time = 23
process id = 3  current_time = 24
process id = 3  current_time = 25
process id = 3  current_time = 26
process id = 3  current_time = 27


Average waiting time = 9.600000

Average response time =3.400000

Average turn around time = 15.200000   
     
