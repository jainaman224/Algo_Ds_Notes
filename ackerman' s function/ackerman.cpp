// C++ program to illustrate Ackermann function 
#include <iostream> 
using namespace std; 

int ack(int m, int n) 
{ 
	if (m == 0){ 
		return n + 1; 
	} 
	else if((m > 0) && (n == 0)){ 
		return ack(m - 1, 1); 
	} 
	else if((m > 0) && (n > 0)){ 
		return ack(m - 1, ack(m, n - 1)); 
	} 
} 

// Driver code 
int main() 
{ 
	int A; 
	A = ack(1, 2); 
	cout << A << endl; 
	return 0; 
} 


