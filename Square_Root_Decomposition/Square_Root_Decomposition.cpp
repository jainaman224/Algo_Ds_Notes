#include<bits/stdc++.h>
using namespace std;

void update(int index,int value,int *blocks,int a[],int n){
	blocks[(int)(index/sqrt(n))] += value-a[index];
	a[index]=value;
}

//assuming 0 based indexing
int query(int low,int high,int *blocks,int a[],int n){
	int block_size=sqrt(n);
	int sum=0;

	while(low % block_size!=0 && low<high){
		sum+=a[low];
		low++;
	}
	while(low+block_size<=high){
		sum+=blocks[low/block_size];
		low+=block_size;
	}
	while(low<=high){
		sum+=a[low];
		low++;
	}

	return sum;

}

//divide the array in blocks of size sqrt(n), sum of elements in each block is stored in blocks
int *formBlocks(int a[],int n){
	int block_size=sqrt(n);
	int index=-1;
	int *blocks = new int[(int)(n/block_size)+1];

	for(int i=0;i<n;i++){
		if(i%block_size==0){
			index++;
		}
		blocks[index]+=a[i];
	}
	return blocks;
}

int main(){
	/* Applying square root decomposition to perform range queries
	for finding the sum of numbers in a given range 
	Indexing : 0 based in array
	*/
	//input : array of integers
	int a[]={2,3,4,6,8,9,1,-1,0,3};  //elements
	int n = sizeof(a)/sizeof(a[0]); //number of elements 
	int *blocks=formBlocks(a,n);
	
	//queries
	//input queries with left and right indices to find the sum in that range
	cout<<query(0,2,blocks,a,n)<<endl; //find sum from index 0 to index 2
	//expected output : 9
	
	cout<<query(3,7,blocks,a,n)<<endl; //find sum from index 3 to index 7
	//expected output : 23
	
	cout<<query(1,4,blocks,a,n)<<endl; //find sum from index 1 to index 4
	//expected output : 21
	
	//update
	update(3,1,blocks,a,n);				//update the value at index 3 with value of 1
	
	//query
	cout<<query(1,4,blocks,a,n)<<endl;	//find sum from index 1 to index 4 
	//expected output : 18
	return 0;
}

