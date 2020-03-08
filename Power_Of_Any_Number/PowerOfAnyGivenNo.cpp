/*
 * PROBLEM STATEMENT
  Program to find if a No. is a power of any Given No. in Java

 * APPROACH
   Comparing the log's value with the floor value of log 
*/
#include <bits/stdc++.h>
using namespace std;

bool isPowerOfGivenNo(int number, int base) {
if(number == 0)
	{
    //0 power anything is 0
    if(base == 0)
	    return true;

    //0 is not the power of any number
    return false;
	}

	//explicitly check for 1 because log(1) = 0
	if(base == 1)
    {
     if(number == 1)
	    return true;
     else
	    return false;
	}

	// -8 cannot be power of 2 but can be power of -2
	if( number < 0 && base > 0)
		return false;

	//converting to positive
	number = abs(number);
	base = abs(base);

	float logValue = (float) ( log(number)/log(base)) ;
	return logValue == floor(logValue);
}


// driver program
int main()
{
    int number, base;
    cout << "Enter a no.: " ;
    cin >> number;
    cout << "Check for which no.? " ;
    cin >> base;
    if( isPowerOfGivenNo(number, base) )
        cout << "Yes " << number << " is a power of " << base;
    else
        cout << "No " << number << " is not a power of " << base;

    return 0;
}

/* SAMPLE INPUT OUTPUT
 * Input :
 	Enter a no. : 14641
	Check for which no. ? 11

 * Output :
	Yes 14641 is a power of 11
 * */
