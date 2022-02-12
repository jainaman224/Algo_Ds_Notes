#define vi vector<int>
#define pb push_back
#define ll long long
#define mod 1000000007
#include <bits/stdc++.h>
using namespace std;
/*
	Extended Euclidean Algorithm
	gcd(a, b) = a * x + b * y;

*/
ll extendedGCD(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll x1, y1;
	ll d = extendedGCD(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}
// int extendedGCD(int a, int b, int &x, int &y) {

// 	if (a == 0) {
// 		x = 0;
// 		y = 1;
// 		return b;
// 	}
// 	int x1, y1;
// 	int ans = extendedGCD(b % a, a, x1, y1);
// 	x = y1 - (b / a) * x1;
// 	y = x1;
// 	return ans;
// }


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);

	ll a, b, x, y;
	while (cin >> a >> b) {
		ll ans = extendedGCD(a, b, x, y);
		cout << x << " " << y << " " << ans << "\n";
	}
	return 0;
}