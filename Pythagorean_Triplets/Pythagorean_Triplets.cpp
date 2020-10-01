/*
PYTHAGOREAN TRIPLETS

Three numbers - a, b and c are said to be pythagorean triplets if following
formula holds :

a^2 + b^2 = c^2
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cout<<"Enter a: "<<endl;
    cin>>a;
    cout<<"Enter b: "<<endl;
    cin>>b;
    cout<<"Enter c: "<<endl;
    cin>>c;
    int sq_a = a * a;
    int sq_b = b * b;
    int sq_c = c * c;
    if (sq_a + sq_b == sq_c || sq_a + sq_c == sq_b || sq_b + sq_c == sq_a) {
        cout<<"It is a pythagorean triplet"<<endl;
    }
    else {
        cout<<"It is not a pythagorean triplet"<<endl;
    }
}

/*
    INPUT : a = 8 b = 6 c = 10
    OUTPUT: It is a pythagorean triplet
    VERIFICATION : 6^2 + 8^2 = 36 + 64 = 100
                   10^2 = 100
*/
