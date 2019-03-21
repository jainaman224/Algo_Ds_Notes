/*
    @author: AkshitAggarwal
    @date: 15/03/2019
*/

#include<iostream>

using namespace std;

int towerOfHanoi(int n, char barFrom, char barTo, char barAuxillary)
{
    if(n == 1)
    {   cout<<"\nMove disk 1 from "<<barFrom<<" to "<<barTo;
        return 1;
    }
    towerOfHanoi(n - 1, barFrom, barAuxillary, barTo);
    cout<<"\nMove disk "<< n <<" from "<<barFrom<<" to "<<barTo;
    towerOfHanoi(n - 1, barAuxillary, barTo, barFrom);
}

int main()
{
    int disks;
    cout<<"\nEnter number of  Disks: ";
    cin>>disks;
    towerOfHanoi(disks, 'A', 'C', 'B');
    return 0;
}
