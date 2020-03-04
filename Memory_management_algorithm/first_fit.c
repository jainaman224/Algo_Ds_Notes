#include <stdio.h>
#include <stdlib.h>


void first_fit(int memory_block[],int process_size[],int m,int n)
{

	int allocated_list[n][3];

	int allocation_marking[m];

	for(int i=0;i<m;i++)
	 allocation_marking[i]=-1;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if((process_size[i]<=memory_block[j]) && (allocation_marking[j]== -1))
			{
				allocated_list[i][0]=process_size[i];

				allocated_list[i][1]=memory_block[j];

				allocated_list[i][2]=j;

				allocation_marking[j]=i;

				break;
			}
			else
			{
				allocated_list[i][0]=process_size[i];

				allocated_list[i][1]=-1;

				allocated_list[i][2]=-1;
			}
		}
	}

	printf("Process Number     Process Size     Allocated memory block size     Memory block number\n");

	for(int i=0;i<n;i++)
	{
		if(allocated_list[i][1]!=-1)
		{
			printf("%d                         %d                          %d                    %d\n",i,allocated_list[i][0],allocated_list[i][1],allocated_list[i][2]);
		}
		else
		{
			printf("%d                         %d                          Not Allocated          Not Allocated\n",i,allocated_list[i][0]);
		}
		
	}


}



int main()
{

	int memory_block[] = {100,500,250,300,50,400};

	int process_size[] = {300,250,229,97,103,350};

	int num_of_mem_blocks = sizeof(memory_block)/sizeof(memory_block[0]);

	int num_of_processes = sizeof(process_size)/sizeof(process_size[0]);

	first_fit(memory_block,process_size,num_of_mem_blocks,num_of_processes);

	return 0;
}

