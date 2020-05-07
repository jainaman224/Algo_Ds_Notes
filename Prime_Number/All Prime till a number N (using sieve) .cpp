#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cout << "Enter number till which you want to find prime numbers : ";
	cin >> N;
	vector<bool> v(N+1, true);
	v[0] = false;
	v[1] = false;
	int k = 0;									// Stores number of primes till N
	vector<int> primes;							// Stores all primes till N
	for(int i = 2; i < N+1; i++){
		if(v[i] == true){
			primes.push_back(i);
			k++;
			for(int j = i*i; j < N+1; j += i){
				v[j] = false;
			}
		}
	}
	cout << "Number of primes till " << N << " = " << k << endl;
	cout << "And the primes are :\n";
	for(auto x : primes){
		cout << x << "\t";
	}
	return 0;
}

