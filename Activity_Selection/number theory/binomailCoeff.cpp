#define vi vector<int>
#define pb push_back
#define mp make_pair
#define ll long long
#define mod 1000000007
#include <bits/stdc++.h>
using namespace std;
int arr[1000001];

int power(int a, int n) {
	int res = 1;
	while (n) {
		if (n % 2) {
			res = (res * 1LL *  a) % mod;
			n--;
		} else {
			a = (a * 1LL * a) % mod;
			n /= 2;
		}
	}

	return res;
}

int C(int n, int k) {
	if (k > n) return 0;

	int res = arr[n];
	res = (res * 1LL * power(arr[k], mod - 2)) % mod;
	res = (res * 1LL * power(arr[n - k], mod - 2)) % mod;

	return res;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	arr[0] = arr[1] = 1;
	for (int i = 2; i <= 1000000; ++i) {
		arr[i] = (arr[i - 1] * 1LL * i) % mod;
	}
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		cout << C(n - 1, k - 1) << "\n";
	}
	return 0;
}