#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


void best_fit(int memory_block[], int process_size[], int m, int n) {
     int allocated_list[n][3];
     int allocation_marking[m];

     for(int i = 0; i < m; i++)
         allocation_marking[i] = -1;

    for(int i = 0; i < n; i++) {
    
        int allocation = -1;
        int mem_block = 10000000;

        for(int j = 0; j < m; j++) {
            if((process_size[i] <= memory_block[j]) && (allocation_marking[j] ==  -1)) {
            if(memory_block[j] < mem_block) {
                mem_block = memory_block[j];
            allocation = j;
            }
        }
        }
        

               if(allocation == -1) {
            allocated_list[i][0] = process_size[i];
            allocated_list[i][1] = -1;
            allocated_list[i][2] = -1;
        }
        else {
            allocated_list[i][0] = process_size[i];
            allocated_list[i][1] = memory_block[allocation];
                allocated_list[i][2] = allocation;
                allocation_marking[allocation] = i;
        }

        printf("Process Number     Process Size     Allocated memory block size     Memory block number\n");

        for(int i = 0; i < n; i++) {
            if(allocated_list[i][1] != -1) {
                printf("%d\t\t\t\t%d\t\t%d\t\t\t%d\n", i, allocated_list[i][0], allocated_list[i][1], allocated_list[i][2]);
            }
            else { 
                printf("%d\t\t\t\t%d\t\t\tNot Allocated\t\tNot Allocated\n", i, allocated_list[i][0]);
            }
        
        }
        }			
} 


int main() {

    int num_of_mem_blocks;
    int num_of_processes;

    cout << "Enter the number of memory blocks\n";
    cin >> num_of_mem_blocks;

    cout << "Enter the number of processes\n";
    cin >> num_of_processes;

    int memory_block[num_of_mem_blocks];
    int process_size[num_of_processes];

    cout << "Enter the memory blocks size:\n";

    for(int i = 0; i < num_of_mem_blocks; i++) {
        cin >> memory_block[i];
    }

    cout << "Enter the process size:\n";
    
    for(int i = 0; i < num_of_processes; i++) {
        cin >> process_size[i];
    }

    best_fit(memory_block, process_size, num_of_mem_blocks, num_of_processes);
    
    return 0;
}

/*  Input: Memory blocks: 100 500 200 300 600
 
    Processes:     212 417 112 426

    Output: process size       blockno

            212		300

        417		500

        112		200

        426		600

*/	

