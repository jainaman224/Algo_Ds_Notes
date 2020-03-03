#include<iostream>
using namespace std;

int bitwiseAdditionRecursive(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    else
    {
        int carry = a & b;
        return bitwiseAdditionRecursive(a^b, carry<<1);
    }
}
int main()
{
    int no1,no2;
    cout << "Enter two numbers: ";
    cin >> no1 >> no2;
    cout << endl << "by using recurssive bitwise addition method," << endl;
    cout << no1 << "+" << no2 << " = " << bitwiseAdditionRecursive(no1, no2);
    return 0;
}






/*
INPUT:
    Enter two numbers: 12 30

OUTPUT:
    byusing recursive bitwise addition method,
    12+30 = 42
*/
