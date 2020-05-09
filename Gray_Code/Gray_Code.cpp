//C++ program to generate the Gray Code for any input bit length

#include<bits/stdc++.h>
#define pb push_back
using namespace std;

// Function to generate the Gray Code sequence
void Gray(int n){
    //If input size is less than or equal to 0
    if(n <= 0){
        cout << "Invalid input";
        return;
    }

    vector<string> v;
    v.pb("0");
    v.pb("1");

    for(int i = 2; i < (1 << n); i <<= 1){
        for(int j = i - 1; j >= 0; j--)
            v.pb(v[j]);
        
        for(int j = 0; j < i; j++)
            v[j] = "0" + v[j];
        
        for(int j = i; j < 2 * i; j++)
            v[j] = "1" + v[j];
    }

    cout << "Gray Code for bit length = " << n << " : " << endl;

    for(int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}

int main(){
    int n;
    cout << "Enter the bit length for Gray Code generation : ";
    cin >> n;
    Gray(n);
}

/* Sample input-output
Enter the bit length for Gray Code generation : 3                                                                               
Gray Code for bit length = 3 :                                                                                                  
000                                                                                                                             
001                                                                                                                             
011                                                                                                                             
010                                                                                                                             
110                                                                                                                             
111                                                                                                                             
101                                                                                                                             
100 */
