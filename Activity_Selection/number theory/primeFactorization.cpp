#include <iostream>
#include <map>

using namespace std;


// unique prime facotrization theorem 

/*
	Every number greater than 1 can be written as the multiplication of rthe prime numbers.
	

	p1^x * p2^y * p3^z .... pn

	x Total divisors = (x+1) * (y+1) * (z+1) .....
*/


map<int, int> primeFactor(int n) {
	std::map<int, int> m;

	int res;
	for (int i = 2; i * i <= n; ++i)
	{
		if(n % i == 0) {
			res = 0;
			while(n % i == 0) {
				res++;
				n /= i;
			}	
			m[n] = res;
		}
	}

	return m;
}
int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;

	map<int, int> m = primeFactor(36);

	for(auto x: m) {
		cout << x.first << " " << x.second;
	}
	return 0;
}