//Program for finding first n hamming numbers for user input of n
#include <stdio.h>
#include <math.h>

//Function for checking whether the number is hamming number or not
int is_hamming (int n) {
    if (n == 1)
    {
        return 1;
    }
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) {
        for (int i = 2; i * i < n; ++i) {
	    if (n % i == 0) {
		if (i % 2 != 0 && i % 3 !=0 && i % 5 !=0)       
		    return 0;
	    }
	    if (n % (n / i) == 0) {
		if ((n / i) % 2 != 0 && (n / i) % 3 !=0 && (n / i) % 5 != 0) 
                    return 0;
	    }
	}
        return 1;		
    }
    return 0;
}
//If hamming number is found in above function then it is printed in the main function for the given range
int main () {
    int n;
    scanf("%d", &n);           //user input
    int count = 0;
    int i = 1;
    int first = 1;
    while (count < n) {
        if (is_hamming(i)) {
            if (!first) 
                printf(" ");
            printf("%d", i);
            ++count;
            first = 0;
        }
        ++i;
    }
}

//OUTPUT
//For input 20
//1 2 3 4 5 6 8 9 10 12 15 16 18 20 24 25 27 30 32 36
