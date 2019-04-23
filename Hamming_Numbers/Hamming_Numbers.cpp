//Program for finding first n hamming numbers for user input of n
#include <iostream>
#include <cmath>
using namespace std;

//Function for checking whether the number is hamming number or not
bool is_hamming (int n) {
    if (n == 1)
    {
        return true;
    }
    if (n%2==0 || n%3==0 || n%5==0) {
	   for (int i = 2; i*i < n; ++i) {
	    if (n%i == 0) {
				if (i%2 != 0 and i%3!=0 and i%5!=0) 
                    return false;
			}
			if (n%(n/i) == 0) {
				if ((n/i)%2 != 0 and (n/i)%3!=0 and (n/i)%5!=0) 
                    return false;
			}
		}
		return true;		
    }
	return false;
}
//If hamming number is found in above function then it is printed in the main function for the given range
int main () {
	int n;
	cin >> n;           //user input
	int count = 0;
	int i = 1;
    bool first = true;
    while (count < n) {
        if (is_hamming(i)) {
            if (!first) 
                cout << " ";
            cout << i;
            ++count;
            first = false;
        }
        ++i;
    }
}

//OUTPUT
//For input 20
//1 2 3 4 5 6 8 9 10 12 15 16 18 20 24 25 27 30 32 36
