#define vi vector<int>
#define pb push_back
#define mp make_pair
#define ll long long
#define mod 1000000007
#include <bits/stdc++.h>
using namespace std;
int arr[1000001];

void sieve() {
	int n = 1000000;
	for (int i = 1; i <= n; ++i) {
		arr[i] = -1;
	}
	for (int i = 2; i <= n; i++) {
		if (arr[i] == -1) {
			for (int j = i; j <= n; j += i) {
				if (arr[j] == -1) arr[j] = i;
			}
		}
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int n;
	cin >> n;
	sieve();
	while (n > 1) {
		cout << arr[n] << " ";
		n /= arr[n];
	}
	return 0;
}