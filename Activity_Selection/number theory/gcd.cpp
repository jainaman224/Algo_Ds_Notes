#define vi vector<int>
#define pb push_back
#define ll long long
#include <bits/stdc++.h>
using namespace std;



/*
	1. gcd(a, 0) = gcd(0, a) = a;
	2. gcd(a, b) = gcd(b, a) = g;
	3. gcd(a, b) = gcd(a - b, a) = gcd(a, b - a) = g;
*/

int gcd(int a, int b) {
	// if (b == 0) {
	// 	return a;
	// }

	// return gcd(b, a % b);

	while (b > 0) {
		int temp = a;
		a = b;
		b = temp % b;
	}

	return a;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;

	cout << gcd(a, b);
	return 0;
}