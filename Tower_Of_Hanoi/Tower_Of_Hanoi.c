/*
    @author: AkshitAggarwal
    @date: 15/03/2019
*/

#include<stdio.h>

int towerOfHanoi(int n, char barFrom, char barTo, char barAuxillary)
{
    if(n == 1)
    {   printf("\nMove disk 1 from %c to %c", barFrom, barTo);
        return 1;
    }
    towerOfHanoi(n - 1, barFrom, barAuxillary, barTo);
    printf("\nMove disk %d from %c to %c", n, barFrom, barTo);
    towerOfHanoi(n - 1, barAuxillary, barTo, barFrom);
}

int main()
{
    int disks;
    printf("Enter the no. of disks: ");
    scanf("%d", &disks);
    towerOfHanoi(disks, 'A', 'C', 'B');
    return 0;
}