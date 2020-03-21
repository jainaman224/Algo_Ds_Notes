#include<iostream>
using namespace std;

int bitwiseaddition(int a, int b)
{
    while(b != 0)
    {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}
int main()
{
    int no1,no2;
    cout << "Enter two numbers: ";
    cin >> no1 >> no2;
    cout << endl << "using bitwise operations," << endl;
    cout << endl << no1 << "+" << no2 <<" = " << bitwiseaddition(no1, no2);
    return 0;
}


/*
INPUT:
    Enter two numbers: 12 30

OUTPUT:
    using bitwise operations,
    
	12+30 = 42
*/
